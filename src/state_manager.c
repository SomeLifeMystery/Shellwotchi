#include <stdlib.h>
#include "global.h"

#include "state_manager.h"

void state_manager_set_state(int state) {
  static int prev_state;

  prev_state = game.state;

  switch (state) {
  case STATE_PREVIUS:
    state_manager_set_state(prev_state);
    break;
  case GAMESTATE_STARTUP:
    game.state = GAMESTATE_STARTUP;
    break;
  case GAMESTATE_STARTUP_SET_TIME:
    set_state_GAMESTATE_STARTUP_SET_TIME();
    break;
  case GAMESTATE_STARTUP_SET_PET_NAME:
    set_state_GAMESTATE_STARTUP_SET_PET_NAME();
    break;
  case GAMESTATE_MAIN:
    set_state_GAMESTATE_MAIN();
    break;
  case GAMESTATE_STATS:
    set_state_GAMESTATE_STATS();
    break;
  case GAMESTATE_FOOD:
    set_state_GAMESTATE_FOOD();
    break;
  case GAMESTATE_BATH:
    set_state_GAMESTATE_BATH();
    break;
  case GAMESTATE_SPORT:
    set_state_GAMESTATE_SPORT();
    break;
  case GAMESTATE_INTERACTION:
    set_state_GAMESTATE_INTERACTION();
    break;
  case GAMESTATE_MEDECINE:
    set_state_GAMESTATE_MEDECINE();
    break;
  case GAMESTATE_LIGHT:
    set_state_GAMESTATE_LIGHT();
    break;
  case GAMESTATE_TIME:
    set_state_GAMESTATE_TIME();
    break;
  case GAMESTATE_EXIT:
    set_state_GAMESTATE_EXIT();
    break;
  default:
    exit(1);
  }
}

void set_state_GAMESTATE_EXIT() {
  game.state = GAMESTATE_EXIT;
}

void set_state_GAMESTATE_STARTUP_SET_TIME() {
  game.state = GAMESTATE_STARTUP_SET_TIME;
  game.selection_index = 0;
}

void set_state_GAMESTATE_STARTUP_SET_PET_NAME() {
  game.state = GAMESTATE_STARTUP_SET_PET_NAME;
  game.selection_index = 0;
}

void set_state_GAMESTATE_MAIN() {
  game.state = GAMESTATE_MAIN;
  game.selection_index = -1;
}

void set_state_GAMESTATE_STATS() {
  game.state = GAMESTATE_STATS;
  game.selection_index = -1;
}

void set_state_GAMESTATE_FOOD() {
  game.state = GAMESTATE_FOOD;
  game.selection_index = 0;
}

void set_state_GAMESTATE_BATH() {
  game.state = GAMESTATE_BATH;
}

void set_state_GAMESTATE_SPORT() {
  game.state = GAMESTATE_SPORT;
  game.selection_index = 0;
}

void set_state_GAMESTATE_INTERACTION() {
  game.state = GAMESTATE_INTERACTION;
  game.selection_index = 0;
}

void set_state_GAMESTATE_MEDECINE() {
  game.state = GAMESTATE_MEDECINE;
}

void set_state_GAMESTATE_LIGHT() {
  game.state = GAMESTATE_LIGHT;
  game.lightOnOff = game.lightOnOff == 1 ? 0 : 1;
  set_state_GAMESTATE_MAIN();
}

void set_state_GAMESTATE_TIME() {
  game.state = GAMESTATE_TIME;
}
