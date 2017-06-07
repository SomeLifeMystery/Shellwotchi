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
  int ui_food_w;
  int ui_food_h;
  char ui_food[15*4];
  int ui_bath_w;
  int ui_bath_h;
  char ui_bath[15*4];
  int ui_sport_w;
  int ui_sport_h;
  char ui_sport[15*4];
  int ui_multi_w;
  int ui_multi_h;
  char ui_multi[15*4];
  int ui_education_w;
  int ui_education_h;
  char ui_education[15*4];
  int ui_medecine_w;
  int ui_medecine_h;
  char ui_medecine[15*4];
  int ui_light_w;
  int ui_light_h;
  char ui_light[15*4];
  int ui_fun_w;
  int ui_fun_h;
  char ui_fun[15*4];
  int ui_attitude_w;
  int ui_attitude_h;
  char ui_attitude[15*4];
};

extern struct s_raw_data raw_data;

struct s_game_data {
  ansigraphic_sprite_t loading_screen;
  ansigraphic_sprite_t ui_stats;
  ansigraphic_sprite_t ui_food;
  ansigraphic_sprite_t ui_bath;
  ansigraphic_sprite_t ui_sport;
  ansigraphic_sprite_t ui_multi;
  ansigraphic_sprite_t ui_education;
  ansigraphic_sprite_t ui_medecine;
  ansigraphic_sprite_t ui_light;
  ansigraphic_sprite_t ui_fun;
  ansigraphic_sprite_t ui_attitude;
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
