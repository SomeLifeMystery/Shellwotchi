#include <stdlib.h>
#include <string.h>

#include "global.h"
#include "state_manager.h"
#include "dhms_clock.h"
#include "saveManager.h"

#include "process.h"

int process_GAMESTATE_STARTUP() {
  game_t tmp; memcpy(&tmp, &game, sizeof(game));
  dhms_clock_reset();
  saveManager_load();
  if (game.magic!=123456789666) memcpy(&game, &tmp, sizeof(game));
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
  set_state_GAMESTATE_MAIN();
  return 0;
}

int process_GAMESTATE_EXIT() {
  mode_raw(0);
  saveManager_save();
  exit(0);
}
