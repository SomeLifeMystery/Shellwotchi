#ifndef DHMS_CLOCK_H_
#define DHMS_CLOCK_H_

#include <time.h>

struct s_dhms_clock {
  time_t t;
  char d;
  char h;
  char m;
  char s;
};

extern struct s_dhms_clock dhms_clock;

void dhms_clock_reset();
void dhms_clock_tick();

#endif /* !DHMS_CLOCK_H_ */
