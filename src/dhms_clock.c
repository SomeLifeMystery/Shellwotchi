#include "dhms_clock.h"

struct s_dhms_clock dhms_clock = {
  .t=0,
  .d=0,
  .h=0,
  .m=0,
  .s=0
};

void dhms_clock_reset() {
  dhms_clock.t = time(0);
  dhms_clock.d = 0;
  dhms_clock.h = 0;
  dhms_clock.m = 0;
  dhms_clock.s = 0;
}

void dhms_clock_tick() {
  time_t ct = time(0);
  time_t passed = ct - dhms_clock.t;
  dhms_clock.t = ct;
  if (passed > 0) {
    dhms_clock.d += passed / (24*60*60);
    dhms_clock.h += (passed % (24*60*60)) / (60*60);
    dhms_clock.m += (passed % (60*60)) / (60);
    dhms_clock.s += passed % 60;
    if (dhms_clock.s >= 60) {
      dhms_clock.m += dhms_clock.s / 60;
      dhms_clock.s %= 60;
    }
    if (dhms_clock.m >= 60) {
      dhms_clock.h += dhms_clock.m / 60;
      dhms_clock.m %= 60;
    }
    if (dhms_clock.h >= 24) {
      dhms_clock.d += dhms_clock.h / 24;
      dhms_clock.h %= 24;
    }
  }
}
