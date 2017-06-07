#include "global.h"

struct s_raw_data raw_data = {
  .loading_screen_w = 13,
  .loading_screen_h = 2,
  .loading_screen = {
    'S','h','e','l','l','w','o','t','c','h','i',' ','!',
    'L','o','a','d','i','n','g','.','.','.',' ',' ',' '
  },
  .ui_stats_w = 15,
  .ui_stats_h = 4,
  .ui_stats = {
    0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,
    0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,
    0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,
    0,0,0,1,1,1,1,1,1,1,1,1,0,0,0
  }
};

