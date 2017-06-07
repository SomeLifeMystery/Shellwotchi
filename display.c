#include "global.h"
#include "display.h"

ansigraphic_image_t* screen;

void display_ui() {
  ansigraphic_dvector2_t start, end;
  ansigraphic_spritePrint(screen, &game_data.ui_stats);
  ansigraphic_spritePrint(screen, &game_data.ui_food);
  ansigraphic_spritePrint(screen, &game_data.ui_bath);
  ansigraphic_spritePrint(screen, &game_data.ui_sport);
  ansigraphic_spritePrint(screen, &game_data.ui_interaction);
  ansigraphic_spritePrint(screen, &game_data.ui_medecine);
  ansigraphic_spritePrint(screen, &game_data.ui_light);
  ansigraphic_spritePrint(screen, &game_data.ui_mood);
  start.x = 20; start.y = 0; end.x = 20; end.y = 20;
  ansigraphic_drawLine(screen, &start, &end, '*', "015", "000");
  start.x = 60; start.y = 0; end.x = 60; end.y = 20;
  ansigraphic_drawLine(screen, &start, &end, '*', "015", "000");
}

void display_pet() {
}

int display_GAMESTATE_STARTUP() {
  ansigraphic_imageFill(screen, ' ', "015", "000");
  ansigraphic_spritePrint(screen, &game_data.loading_screen);
  ansigraphic_imagePrint(screen);
  return 0;
}

int display_GAMESTATE_MAIN() {
  ansigraphic_imageFill(screen, ' ', "000", "015");
  display_ui();
  display_pet();
  ansigraphic_imagePrint(screen);
  return 0;
}

