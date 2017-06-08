#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include "global.h"
#include "dhms_clock.h"

char* saveFile;

int saveManager_load() {
  int fd, read_byte, size=(sizeof(game) + sizeof(dhms_clock));

  fd = open(saveFile, O_RDWR);
  lseek(fd, -size, SEEK_END);
  read(fd, &game, sizeof(game));
  read(fd, &dhms_clock, sizeof(dhms_clock));
  close(fd);
  return 0;
}

int saveManager_save() {
  int fd, read_byte, size=(sizeof(game) + sizeof(dhms_clock));

  fd = open(saveFile, O_RDWR);
  lseek(fd, -size, SEEK_END);
  write(fd, &game, sizeof(game));
  write(fd, &dhms_clock, sizeof(dhms_clock));
  close(fd);

  printf("game saved\n");
  return 0;
}
