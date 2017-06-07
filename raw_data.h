#ifndef RAW_DATA_H_
#define RAW_DATA_H_

struct s_raw_data {
  int loading_screen_w;
  int loading_screen_h;
  char loading_screen[13*2];
  int ui_stats_w;
  int ui_stats_h;
  char ui_stats[15*4];
  int ui_food_w;
  int ui_food_h;
  char ui_food[15*4];
  int ui_bath_w;
  int ui_bath_h;
  char ui_bath[15*4];
  int ui_sport_w;
  int ui_sport_h;
  char ui_sport[15*4];
  int ui_interaction_w;
  int ui_interaction_h;
  char ui_interaction[15*4];
  int ui_medecine_w;
  int ui_medecine_h;
  char ui_medecine[15*4];
  int ui_light_w;
  int ui_light_h;
  char ui_light[15*4];
  int ui_mood_w;
  int ui_mood_h;
  char ui_mood[15*4];
};

extern struct s_raw_data raw_data;

#endif /* !RAW_DATA_H_ */
