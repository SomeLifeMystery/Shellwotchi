#include "global.h"
#include "raw_data.h"
#include "display.h"

#include "game_data.h"

struct s_game_data game_data;

int data_load_raw(ansigraphic_image_t* dest, char*src) {
  ansigraphic_ivector2_t xy;
  int x, y;
  int width = dest->width;
  int height = dest->height;
  char val;

  y = -1;
  while (++y < height) {
    x = -1;
    while (++x < width) {
      xy.x = x;
      xy.y = height - 1 - y;
      val = src[x + (y*width)];
      if (val < 0) {
	ansigraphic_pixelSetColor(dest, &xy, "015", "000");
	ansigraphic_pixelSetValue(dest, &xy, -val);
      } else {
	ansigraphic_pixelSetColor(dest, &xy, "000", "015");
	ansigraphic_pixelSetValue(dest, &xy, val);
      }
    }
  }
  return 0;
}

int data_load_loading_screen() {
  int width = raw_data.loading_screen_w;
  int height = raw_data.loading_screen_h;
  game_data.loading_screen.image = ansigraphic_newImage(width, height);
  game_data.loading_screen.xy.x = WIDTH/2 - width;
  game_data.loading_screen.xy.y = HEIGHT/2 - height;
  data_load_raw(game_data.loading_screen.image, raw_data.loading_screen);
  return 0;
}

int data_load_ui_stats() {
  int width = raw_data.ui_stats_w;
  int height = raw_data.ui_stats_h;
  game_data.ui_stats.image = ansigraphic_newImage(width, height);
  game_data.ui_stats.xy.x = 0;
  game_data.ui_stats.xy.y = 0;
  data_load_raw(game_data.ui_stats.image, raw_data.ui_stats);
  return 0;
}

int data_load_ui_food() {
  int width = raw_data.ui_food_w;
  int height = raw_data.ui_food_h;
  game_data.ui_food.image = ansigraphic_newImage(width, height);
  game_data.ui_food.xy.x = 0;
  game_data.ui_food.xy.y = height+1;
  data_load_raw(game_data.ui_food.image, raw_data.ui_food);
  return 0;
}

int data_load_ui_bath() {
  int width = raw_data.ui_bath_w;
  int height = raw_data.ui_bath_h;
  game_data.ui_bath.image = ansigraphic_newImage(width, height);
  game_data.ui_bath.xy.x = 0;
  game_data.ui_bath.xy.y = 2*(height+1);
  data_load_raw(game_data.ui_bath.image, raw_data.ui_bath);
  return 0;
}

int data_load_ui_sport() {
  int width = raw_data.ui_sport_w;
  int height = raw_data.ui_sport_h;
  game_data.ui_sport.image = ansigraphic_newImage(width, height);
  game_data.ui_sport.xy.x = 0;
  game_data.ui_sport.xy.y = 3*(height+1);
  data_load_raw(game_data.ui_sport.image, raw_data.ui_sport);
  return 0;
}

int data_load_ui_interaction() {
  int width = raw_data.ui_interaction_w;
  int height = raw_data.ui_interaction_h;
  game_data.ui_interaction.image = ansigraphic_newImage(width, height);
  game_data.ui_interaction.xy.x = WIDTH - 1 - width;
  game_data.ui_interaction.xy.y = 0;
  data_load_raw(game_data.ui_interaction.image, raw_data.ui_interaction);
  return 0;
}

int data_load_ui_medecine() {
  int width = raw_data.ui_medecine_w;
  int height = raw_data.ui_medecine_h;
  game_data.ui_medecine.image = ansigraphic_newImage(width, height);
  game_data.ui_medecine.xy.x = WIDTH - 1 - width;
  game_data.ui_medecine.xy.y = height+1;
  data_load_raw(game_data.ui_medecine.image, raw_data.ui_medecine);
  return 0;
}

int data_load_ui_light() {
  int width = raw_data.ui_light_w;
  int height = raw_data.ui_light_h;
  game_data.ui_light.image = ansigraphic_newImage(width, height);
  game_data.ui_light.xy.x = WIDTH - 1 - width;
  game_data.ui_light.xy.y = 2*(height+1);
  data_load_raw(game_data.ui_light.image, raw_data.ui_light);
  return 0;
}

int data_load_ui_mood() {
  int width = raw_data.ui_mood_w;
  int height = raw_data.ui_mood_h;
  game_data.ui_mood.image = ansigraphic_newImage(width, height);
  game_data.ui_mood.xy.x = WIDTH - 1 - width;
  game_data.ui_mood.xy.y = 3*(height+1);
  data_load_raw(game_data.ui_mood.image, raw_data.ui_mood);
  return 0;
}

int data_load_ui_time() {
  int width = raw_data.ui_time_w;
  int height = raw_data.ui_time_h;
  game_data.ui_time.image = ansigraphic_newImage(width, height);
  game_data.ui_time.xy.x = WIDTH/2 - width;
  game_data.ui_time.xy.y = HEIGHT/2 - height;
  data_load_raw(game_data.ui_time.image, raw_data.ui_time);
  return 0;
}

int data_load_pet_age0() {
  int width = raw_data.pet_age0_w;
  int height = raw_data.pet_age0_h;
  game_data.pet_age0 = ansigraphic_newAnimatedSprite();
  ansigraphic_animatedSprite_pushFrame(game_data.pet_age0, ansigraphic_newImage(width, height));
  ansigraphic_animatedSprite_pushFrame(game_data.pet_age0, ansigraphic_newImage(width, height));
  game_data.pet_age0->xy.x = 20;
  game_data.pet_age0->xy.y = 0;
  game_data.pet_age0->frameRate /= 2;
  data_load_raw(game_data.pet_age0->imageFrames[0], raw_data.pet_age0[0]);
  data_load_raw(game_data.pet_age0->imageFrames[1], raw_data.pet_age0[1]);
  return 0;
}
