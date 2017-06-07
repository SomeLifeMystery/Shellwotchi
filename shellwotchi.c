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

int process_GAMESTATE_STARTUP() {
  return 0;
}

int main() {
  data_load_loading_screen();
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
