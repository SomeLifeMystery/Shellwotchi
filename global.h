#ifndef GLOBAL_H_
#define GLOBAL_H_

#include "ansiGraphic2.h"

enum {
  GAMESTATE_STARTUP,
  GAMESTATE_MAIN,
  GAMESTATE_EXIT
};

struct s_raw_data {
  int loading_screen_w;
  int loading_screen_h;
  char loading_screen[13*2];
  int ui_stats_w;
  int ui_stats_h;
  char ui_stats[15*4];
};

extern struct s_raw_data raw_data;

struct s_game_data {
  ansigraphic_sprite_t loading_screen;
  ansigraphic_sprite_t ui_stats;
};

extern struct s_game_data game_data;

typedef struct {
  int width;
  int height;
  int frames_per_second;
  int state;
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

extern ansigraphic_image_t* screen;

#endif /* !GLOBAL_H_ */
