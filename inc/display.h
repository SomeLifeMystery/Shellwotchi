#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "ansiGraphic2.1.h"

#define WIDTH 80
#define HEIGHT 20
#define FRAMES_PER_SECOND 15

extern ansigraphic_image_t* screen;

void display_ui();
void display_pet();
int display_GAMESTATE_STARTUP();
int display_GAMESTATE_MAIN();
int display_GAMESTATE_TIME();

#endif /* !DISPLAY_H_ */
