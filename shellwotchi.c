/*
 *
 * gcc -g3 -o Shellwotchi shellwotchi.c raw_data.c game_data.c events.c display.c process.c ../ansiGraphic/ansiGraphic2.c -I ../ansiGraphic/
 *
 */


#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include "global.h"
#include "events.h"
#include "game_data.h"
#include "display.h"

game_t game = {
  .height = 20,
  .width = 80,
  .frames_per_second = 15,
  .state = GAMESTATE_STARTUP,
  .event = 0
};

int main() {
  data_load_loading_screen();
  screen = ansigraphic_newImage(game.width, game.height);
  clock_t timer, clocked = 0;
  int delay = 1000 / game.frames_per_second;
  int event = 0;

  mode_raw(1);
  while (42) {
    timer = clocked;
    game.event = get_events();
    switch (game.state) {
    case GAMESTATE_STARTUP:
      display_GAMESTATE_STARTUP();
      process_GAMESTATE_STARTUP();
      handle_events_GAMESTATE_STARTUP();
      break;
    case GAMESTATE_MAIN:
      display_GAMESTATE_MAIN();
      handle_events_GAMESTATE_MAIN();
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
