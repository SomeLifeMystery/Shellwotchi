#ifndef GAME_DATA_H_
#define GAME_DATA_H_

#include "ansiGraphic2.h"

struct s_game_data {
  ansigraphic_sprite_t loading_screen;
  ansigraphic_sprite_t ui_stats;
  ansigraphic_sprite_t ui_food;
  ansigraphic_sprite_t ui_bath;
  ansigraphic_sprite_t ui_sport;
  ansigraphic_sprite_t ui_interaction;
  ansigraphic_sprite_t ui_medecine;
  ansigraphic_sprite_t ui_light;
  ansigraphic_sprite_t ui_mood;
  ansigraphic_sprite_t ui_time;
  ansigraphic_animatedSprite_t* pet_age0;
};

extern struct s_game_data game_data;

int data_load_loading_screen();
int data_load_ui_stats();
int data_load_ui_food();
int data_load_ui_bath();
int data_load_ui_sport();
int data_load_ui_interaction();
int data_load_ui_medecine();
int data_load_ui_light();
int data_load_ui_mood();
int data_load_ui_time();
int data_load_pet_age0();

#endif /* !GAME_DATA_H_ */
