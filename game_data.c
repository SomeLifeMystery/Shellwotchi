#include "global.h"
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
  game_data.loading_screen.xy.x = game.width/2 - width;
  game_data.loading_screen.xy.y = game.height/2 - height;
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
