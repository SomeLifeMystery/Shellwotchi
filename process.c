#include "global.h"
#include "process.h"

int process_GAMESTATE_STARTUP() {
  data_load_ui_stats();
  game.state = GAMESTATE_MAIN;
  return 0;
}

