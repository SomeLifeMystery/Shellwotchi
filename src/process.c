#include "global.h"
#include "state_manager.h"
#include "dhms_clock.h"

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
  dhms_clock_reset();
  data_load_pet_age0();
  set_state_GAMESTATE_MAIN();
  return 0;
}

