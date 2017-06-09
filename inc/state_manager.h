#ifndef STATE_MANAGER_H_
#define STATE_MANAGER_H_

enum {
  STATE_PREVIUS,
  GAMESTATE_STARTUP,
  GAMESTATE_MAIN,
  GAMESTATE_STATS,
  GAMESTATE_FOOD,
  GAMESTATE_BATH,
  GAMESTATE_SPORT,
  GAMESTATE_INTERACTION,
  GAMESTATE_MEDECINE,
  GAMESTATE_LIGHT,
  GAMESTATE_TIME,
  GAMESTATE_EXIT
};

void state_manager_set_state(int state);
void set_state_GAMESTATE_EXIT();
void set_state_GAMESTATE_MAIN();
void set_state_GAMESTATE_STATS();
void set_state_GAMESTATE_FOOD();
void set_state_GAMESTATE_BATH();
void set_state_GAMESTATE_SPORT();
void set_state_GAMESTATE_INTERACTION();
void set_state_GAMESTATE_MEDECINE();
void set_state_GAMESTATE_LIGHT();
void set_state_GAMESTATE_TIME();

#endif /* !STATE_MANAGER_H_ */
