#include "global.h"
#include "display.h"

ansigraphic_image_t* screen;

void display_ui() {
}

void display_pet() {
}

int display_GAMESTATE_STARTUP() {
  ansigraphic_imageClear(screen);
  ansigraphic_spritePrint(screen, &game_data.loading_screen);
  ansigraphic_imagePrint(screen);
  return 0;
}

