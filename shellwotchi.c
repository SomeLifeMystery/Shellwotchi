/*
 *
 * gcc -g3 -o Shellwotchi shellwotchi.c raw_data.c game_data.c ../ansiGraphic/ansiGraphic2.c -I ../ansiGraphic/
 *
 *
 */


#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include "global.h"

game_t game = {
  .height = 20,
  .width = 80,
  .frames_per_second = 15,
  .state = GAMESTATE_STARTUP,
  .event = 0
};

int data_loading_screen() {
  ansigraphic_ivector2_t xy;
  int x, y;
  int width = raw_data.loading_screen_w;
  int height = raw_data.loading_screen_h;
  game_data.loading_screen.image = ansigraphic_newImage(width, height);
  game_data.loading_screen.xy.x = game.width/2 - width;
  game_data.loading_screen.xy.y = game.height/2 - height;
  y = -1;
  while (++y < height) {
    x = -1;
    while (++x < width) {
      xy.x = x;
      xy.y = height - 1 - y;
      ansigraphic_pixelSetColor(game_data.loading_screen.image, &xy, "015", "000");
      ansigraphic_pixelSetValue(game_data.loading_screen.image, &xy, raw_data.loading_screen[x + (y*width)]);
    }
  }
}

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

int display_GAMESTATE_STARTUP(ansigraphic_image_t* screen) {
  ansigraphic_imageClear(screen);
  ansigraphic_spritePrint(screen, &game_data.loading_screen);
  ansigraphic_imagePrint(screen);
  return 0;
}

int handle_events_GAMESTATE_STARTUP() {
    switch (game.event) {
    case 27:
      mode_raw(0);
      exit(0);
      break;
    }
}

int process_GAMESTATE_STARTUP() {
  return 0;
}

int main() {
  data_loading_screen();
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
      display_GAMESTATE_STARTUP(screen);
      process_GAMESTATE_STARTUP();
      handle_events_GAMESTATE_STARTUP();
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
