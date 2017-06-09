#include <stdlib.h>
#include <string.h>

#include "global.h"
#include "state_manager.h"
#include "dhms_clock.h"
#include "saveManager.h"
#include "state_manager.h"

#include "process.h"

int process_GAMESTATE_STARTUP() {
  data_load_ui_stats();
  data_load_ui_food();
  data_load_ui_bath();
  data_load_ui_sport();
  data_load_ui_interaction();
  data_load_ui_medecine();
  data_load_ui_light();
  data_load_ui_mood();
  data_load_ui_time();
  data_load_pet_age0();
  dhms_clock_reset();
  game_t tmpGame; memcpy(&tmpGame, &game, sizeof(game));
  struct s_dhms_clock tmpClock; memcpy(&tmpClock, &dhms_clock, sizeof(dhms_clock));
  saveManager_load();
  if (game.magic!=123456789666) {
    memcpy(&game, &tmpGame, sizeof(game));
    memcpy(&dhms_clock, &tmpClock, sizeof(dhms_clock));
    state_manager_set_state(GAMESTATE_STARTUP_SET_TIME);
  } else 
    state_manager_set_state(GAMESTATE_MAIN);
  return 0;
}

int process_GAMESTATE_EXIT() {
  mode_raw(0);
  saveManager_save();
  exit(0);
}
