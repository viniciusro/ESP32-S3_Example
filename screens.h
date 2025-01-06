#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *alive_udp;
    lv_obj_t *calendar;
    lv_obj_t *clima;
    lv_obj_t *clima_description;
    lv_obj_t *clima_main;
    lv_obj_t *cpu;
    lv_obj_t *cpu_clock_bar;
    lv_obj_t *cpu_freq_mhz;
    lv_obj_t *cpu_load;
    lv_obj_t *cpu_load_arc;
    lv_obj_t *cpu_temp_bar;
    lv_obj_t *cpu_temperature_c;
    lv_obj_t *departure_time;
    lv_obj_t *dots;
    lv_obj_t *gpu;
    lv_obj_t *gpu_clock_bar;
    lv_obj_t *gpu_freq_mhz;
    lv_obj_t *gpu_load;
    lv_obj_t *gpu_load_arc;
    lv_obj_t *gpu_temp_bar;
    lv_obj_t *gpu_temperature;
    lv_obj_t *hdd;
    lv_obj_t *hdd0_usage;
    lv_obj_t *hdd0_usage_bar;
    lv_obj_t *hdd1_usage;
    lv_obj_t *hdd1_usage_bar;
    lv_obj_t *hdd2_usage;
    lv_obj_t *hdd2_usage_bar;
    lv_obj_t *hours;
    lv_obj_t *humidity;
    lv_obj_t *ip_text;
    lv_obj_t *key_board;
    lv_obj_t *mem_load;
    lv_obj_t *minutes;
    lv_obj_t *obj0;
    lv_obj_t *obj1;
    lv_obj_t *obj2;
    lv_obj_t *platform;
    lv_obj_t *quote_etf_0;
    lv_obj_t *quote_etf_1;
    lv_obj_t *quote_etf_2;
    lv_obj_t *quote_etf_3;
    lv_obj_t *quote_etf_4;
    lv_obj_t *quote_etf_5;
    lv_obj_t *ram_load_arc;
    lv_obj_t *recolor;
    lv_obj_t *status_bar;
    lv_obj_t *tab_1;
    lv_obj_t *tab_2;
    lv_obj_t *tab_3;
    lv_obj_t *tab_4;
    lv_obj_t *tab_5;
    lv_obj_t *temperature;
    lv_obj_t *textarea1;
    lv_obj_t *time;
    lv_obj_t *total_performance;
    lv_obj_t *value_etf_0;
    lv_obj_t *value_etf_1;
    lv_obj_t *value_etf_2;
    lv_obj_t *value_etf_3;
    lv_obj_t *value_etf_4;
    lv_obj_t *value_etf_5;
    lv_obj_t *weather_img;
    lv_obj_t *wind_speed;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
};

void create_screen_main();
void tick_screen_main();

void create_screens();
void tick_screen(int screen_index);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/