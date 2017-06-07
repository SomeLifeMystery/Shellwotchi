/*
 *
 * gcc -o Shellwotchi shellwotchi.c ../ansiGraphic/ansiGraphic2.c -I ../ansiGraphic/
 *
 */


#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include "ansiGraphic2.h"

enum {
  GAMESTATE_STARTUP,
  GAMESTATE_MAIN,
  GAMESTATE_EXIT
};

struct s_game_data {
  ansigraphic_image_t* loading_screen;
};

typedef struct {
  struct s_game_data data;
  int width;
  int height;
  int frames_per_second;
  int state;
  int event;
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

int get_events() {
  char c[4] = {0, 0, 0, 0};
  if (unix_text_kbhit())
    read(1, c, 4);
  return (*((int*)c));
}

void display_ui() {
}

void display_pet() {
}

int display_GAMESTATE_STARTUP(game_t* game, ansigraphic_image_t* screen) {
  ansigraphic_imageClear(screen);
  game->data.loading_screen = ansigraphic_newImage(screen->width, screen->height);
  ansigraphic_imagePrint(screen);
  return 0;
}

int handle_events_GAMESTATE_STARTUP(game_t* game) {
    switch (game->event) {
    case 27:
      mode_raw(0);
      exit(0);
      break;
    }
}

int process_GAMESTATE_STARTUP(game_t* game) {
  return 0;
}

int main() {
  game_t game = {
    .height = 20,
    .width = 80,
    .frames_per_second = 15,
    .state = GAMESTATE_STARTUP,
    .event = 0
  };
  ansigraphic_image_t* screen = ansigraphic_newImage(game.width, game.height);
  clock_t timer, clocked = 0;
  int delay = 1000 / game.frames_per_second;
  int event = 0;

  mode_raw(1);
  while (42) {
    timer = clocked;
    game.event = get_events();
    switch (game.state) {
    case GAMESTATE_STARTUP:
      display_GAMESTATE_STARTUP(&game, screen);
      process_GAMESTATE_STARTUP(&game);
      handle_events_GAMESTATE_STARTUP(&game);
      break;
    default:
      exit(-1);
    }
    clocked = clock() / CLOCKS_PER_SEC;
    timer = delay - (clocked - timer);
    if (timer > 0)
      usleep(timer * 1000);
  }
}
