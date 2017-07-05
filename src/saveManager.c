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
  int fd, read_byte, size=(sizeof(game_t) + sizeof(struct s_dhms_clock));

  if ((fd = open(saveFile, O_RDONLY)) <= 0)
    game.magic=0;
  else {    
    read(fd, &game, sizeof(game_t));
    read(fd, &dhms_clock, sizeof(struct s_dhms_clock));
    close(fd);
  }
  return 0;
}

int saveManager_save() {
  int fd;

  fd = open(saveFile, O_CREAT|O_WRONLY, (mode_t)0666);
  write(fd, &game, sizeof(game_t));
  write(fd, &dhms_clock, sizeof(struct s_dhms_clock));
  close(fd);
  return 0;
}
