#include "global.h"
#include "display.h"

ansigraphic_image_t* screen;

void display_ui() {
  ansigraphic_spritePrint(screen, &game_data.ui_stats);
}

void display_pet() {
}

int display_GAMESTATE_STARTUP() {
  ansigraphic_imageClear(screen);
  ansigraphic_image_reverse(screen);
  ansigraphic_spritePrint(screen, &game_data.loading_screen);
  ansigraphic_imagePrint(screen);
  return 0;
}

int display_GAMESTATE_MAIN() {
  ansigraphic_imageClear(screen);
  ansigraphic_image_reverse(screen);
  display_ui();
  display_pet();
  ansigraphic_imagePrint(screen);
  return 0;
}

