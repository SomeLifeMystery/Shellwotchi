#ifndef GLOBAL_H_
#define GLOBAL_H_

typedef struct {
  int width;
  int height;
  int frames_per_second;
  int state;
  int selection_index;
  int event;
  char player_name[5];
  char pet_name[5];
  char pet_parent_name[2][5];
  unsigned char pet_happiness;
  unsigned char pet_food;
  unsigned char pet_poo;
  unsigned char pet_health;
} game_t;

extern game_t game;

#endif /* !GLOBAL_H_ */
