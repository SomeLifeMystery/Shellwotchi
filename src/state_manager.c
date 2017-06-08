#include "global.h"

#include "state_manager.h"

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

