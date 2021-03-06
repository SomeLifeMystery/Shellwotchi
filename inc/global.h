#ifndef GLOBAL_H_
#define GLOBAL_H_

typedef struct {
  unsigned long magic;
  int state;
  int selection_index;
  int event;
  char lightOnOff;
  char player_name[5];
  char pet_name[5];
  unsigned char pet_happiness;
  unsigned char pet_food;
  unsigned char pet_weight;
  unsigned char pet_poo;
  unsigned char pet_health;
} game_t;

extern game_t game;

#endif /* !GLOBAL_H_ */
