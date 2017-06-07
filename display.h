#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "ansiGraphic2.h"

extern ansigraphic_image_t* screen;

void display_ui();
void display_pet();
int display_GAMESTATE_STARTUP();
int display_GAMESTATE_MAIN();

#endif /* !DISPLAY_H_ */
