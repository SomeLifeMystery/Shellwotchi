#include "global.h"
#include "game_data.h"

struct s_game_data game_data;

int data_load_loading_screen() {
  ansigraphic_ivector2_t xy;
  int x, y;
  int width = raw_data.loading_screen_w;
  int height = raw_data.loading_screen_h;
  game_data.loading_screen.image = ansigraphic_newImage(width, height);
  game_data.loading_screen.xy.x = game.width/2 - width;
  game_data.loading_screen.xy.y = game.height/2 - height;
  y = -1;
  while (++y < height) {
    x = -1;
    while (++x < width) {
      xy.x = x;
      xy.y = height - 1 - y;
      ansigraphic_pixelSetColor(game_data.loading_screen.image, &xy, "015", "000");
      ansigraphic_pixelSetValue(game_data.loading_screen.image, &xy, raw_data.loading_screen[x + (y*width)]);
    }
  }
}
