#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include "ansiGraphic2.h"

typedef struct {
  int width;
  int height;
  int frames_per_second;
  int state;
  char player_name[5];
  char pet_name[5];
  char pet_parent_name[2][5];
  unsigned char pet_happiness;
  unsigned char pet_food;
  unsigned char pet_poo;
  unsigned char pet_health;
} game_t;

void mode_raw(int activer)
{
  static struct termios cooked;
  static int raw_actif = 0;

  if (raw_actif == activer)
    return;

  if (activer)
    {
      struct termios raw;

      tcgetattr(STDIN_FILENO, &cooked);

      raw = cooked;
      cfmakeraw(&raw);
      tcsetattr(STDIN_FILENO, TCSANOW, &raw);
    }
  else
    tcsetattr(STDIN_FILENO, TCSANOW, &cooked);

  raw_actif = activer;
}

int unix_text_kbhit(void)
{
  struct timeval tv = { 0, 0 };
  fd_set readfds;

  FD_ZERO(&readfds);
  FD_SET(STDIN_FILENO, &readfds);

  return select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv) == 1;
}

int display(game_t* game, ansigraphic_image_t* screen) {
  ansigraphic_imagePrint(screen);
  ansigraphic_imageClear(screen);
  return 0;
}

int handle_events(game_t* game) {
    char c[4] = {0, 0, 0, 0};
    if (unix_text_kbhit())
      read(1, c, 4);
    switch (*((int*)c)) {
    case 27:
      mode_raw(0);
      exit(0);
      break;
    }
  return 0;
}

int main() {
  game_t game = {
    .height = 20,
    .width = 80,
    .frames_per_second = 15
  };
  ansigraphic_image_t* screen = ansigraphic_newImage(game.width, game.height);
  clock_t timer, clocked = 0;
  int delay = 1000 / game.frames_per_second;

  mode_raw(1);
  while (42) {
    timer = clocked;
    display();
    handle_events();
    clocked = clock() / CLOCKS_PER_SEC;
    timer = delay - (clocked - timer);
    if (timer > 0)
      usleep(timer * 1000);
  }
}
