#include <termios.h>
#include <unistd.h>
#include <stdlib.h>

#include "global.h"
#include "state_manager.h"

#include "events.h"

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

int handle_events_GAMESTATE_STARTUP() {
    switch (game.event) {
    case 27:
      state_manager_set_state(GAMESTATE_EXIT);
      break;
    }
}

int handle_events_GAMESTATE_MAIN() {
    switch (game.event) {
    case 27://ESC
      state_manager_set_state(GAMESTATE_EXIT);
      break;
    case 4283163://UP
      game.selection_index-=1;
      if (game.selection_index < 0)
	game.selection_index=6;
      break;
    case 4348699://DOWN
      game.selection_index+=1;
      if (game.selection_index > 6)
	game.selection_index=0;
      break;
    case 4414235://RIGHT
      switch (game.selection_index) {
      case -1:
	state_manager_set_state(GAMESTATE_TIME);
	break;
      case 0:
        state_manager_set_state(GAMESTATE_STATS);
	break;
      case 1:
        state_manager_set_state(GAMESTATE_FOOD);
	break;
      case 2:
        state_manager_set_state(GAMESTATE_BATH);
	break;
      case 3:
        state_manager_set_state(GAMESTATE_SPORT);
	break;
      case 4:
        state_manager_set_state(GAMESTATE_INTERACTION);
	break;
      case 5:
        state_manager_set_state(GAMESTATE_MEDECINE);
	break;
      case 6:
        state_manager_set_state(GAMESTATE_LIGHT);
	break;
      default:break;
      }
      break;
    case 4479771://LEFT
      game.selection_index = -1;
      break;
    }
}

int handle_events_GAMESTATE_TIME() {
    switch (game.event) {
    case 27://ESC
      state_manager_set_state(GAMESTATE_EXIT);
      break;
    case 4414235://RIGHT
      state_manager_set_state(GAMESTATE_MAIN);
      break;
    case 4479771://LEFT
      state_manager_set_state(GAMESTATE_MAIN);
      break;
    }
}
