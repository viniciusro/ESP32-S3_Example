#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_main_calendar(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_calendar_selected_event(e);
    }
    if (event == LV_EVENT_LONG_PRESSED_REPEAT) {
        e->user_data = (void *)0;
        action_clear_highlighted_days(e);
    }
}

static void event_handler_cb_main_time(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_PRESSING) {
        e->user_data = (void *)0;
        action_drag_event_handler(e);
    }
}

static void event_handler_cb_main_clima(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_PRESSING) {
        e->user_data = (void *)0;
        action_drag_event_handler(e);
    }
}

static void event_handler_cb_main_cpu(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_PRESSING) {
        e->user_data = (void *)0;
        action_drag_event_handler(e);
    }
}

static void event_handler_cb_main_gpu(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_PRESSING) {
        e->user_data = (void *)0;
        action_drag_event_handler(e);
    }
}

static void event_handler_cb_main_hdd(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_PRESSING) {
        e->user_data = (void *)0;
        action_drag_event_handler(e);
    }
}

static void event_handler_cb_main_obj0(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_PRESSING) {
        e->user_data = (void *)0;
        action_drag_event_handler(e);
    }
}

static void event_handler_cb_main_recolor(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_VALUE_CHANGED) {
        e->user_data = (void *)0;
        action_color_wheel_event(e);
    }
}

static void event_handler_cb_main_obj1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        action_reset_color_event(e);
    }
}

void create_screen_main() {
    void *flowState = getFlowState(0, 0);
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff424242), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_tabview_create(parent_obj, LV_DIR_LEFT, 80);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 464);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_ON);
            lv_obj_set_scroll_snap_x(obj, LV_DIR_TOP);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_tabview_get_tab_btns(parent_obj);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff424242), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffe9e9e9), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 250, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff0047b0), LV_PART_ITEMS | LV_STATE_CHECKED);
                    lv_obj_set_style_border_opa(obj, 220, LV_PART_ITEMS | LV_STATE_CHECKED);
                    lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_LEFT, LV_PART_ITEMS | LV_STATE_CHECKED);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_ITEMS | LV_STATE_CHECKED);
                    lv_obj_set_style_bg_opa(obj, 50, LV_PART_ITEMS | LV_STATE_CHECKED);
                }
                {
                    lv_obj_t *obj = lv_tabview_get_content(parent_obj);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_radius(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // Tab 2
                            lv_obj_t *obj = lv_tabview_add_tab(lv_obj_get_parent(parent_obj), "Info");
                            objects.tab_2 = obj;
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_bg_img_src(obj, &img_black_vector, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_recolor(obj, lv_color_hex(0xff2e009a), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_recolor_opa(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Info");
                                    add_style_label_title(obj);
                                }
                                {
                                    // calendar
                                    lv_obj_t *obj = lv_calendar_create(parent_obj);
                                    objects.calendar = obj;
                                    lv_obj_set_pos(obj, 356, 50);
                                    lv_obj_set_size(obj, 314, 315);
                                    lv_calendar_header_arrow_create(obj);
                                    lv_calendar_set_today_date(obj, 2024, 9, 25);
                                    lv_calendar_set_showed_date(obj, 2024, 9);
                                    lv_obj_add_event_cb(obj, event_handler_cb_main_calendar, LV_EVENT_ALL, flowState);
                                }
                                {
                                    // Time
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.time = obj;
                                    lv_obj_set_pos(obj, 0, 50);
                                    lv_obj_set_size(obj, 315, 145);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_add_event_cb(obj, event_handler_cb_main_time, LV_EVENT_ALL, flowState);
                                    add_style_container(obj);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 6, 6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "Time (GMT+2)");
                                            add_style_label_title(obj);
                                        }
                                        {
                                            // hours
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.hours = obj;
                                            lv_obj_set_pos(obj, 38, 50);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "00");
                                            add_style_label_title(obj);
                                            lv_obj_set_style_text_font(obj, &ui_font_tox_typewriter, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                        {
                                            // dots
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.dots = obj;
                                            lv_obj_set_pos(obj, 140, 50);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, ":");
                                            add_style_label_title(obj);
                                            lv_obj_set_style_text_font(obj, &ui_font_tox_typewriter, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                        {
                                            // minutes
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.minutes = obj;
                                            lv_obj_set_pos(obj, 170, 50);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "00");
                                            add_style_label_title(obj);
                                            lv_obj_set_style_text_font(obj, &ui_font_tox_typewriter, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                    }
                                }
                                {
                                    // Clima
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.clima = obj;
                                    lv_obj_set_pos(obj, 0, 220);
                                    lv_obj_set_size(obj, 315, 145);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_add_event_cb(obj, event_handler_cb_main_clima, LV_EVENT_ALL, flowState);
                                    add_style_container(obj);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            // clima_description
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.clima_description = obj;
                                            lv_obj_set_pos(obj, 7, 34);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "Weather Description");
                                            add_style_label_title(obj);
                                        }
                                        {
                                            // clima_main
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.clima_main = obj;
                                            lv_obj_set_pos(obj, 7, 6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "Weather Main");
                                            add_style_label_title(obj);
                                        }
                                        {
                                            // temperature
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.temperature = obj;
                                            lv_obj_set_pos(obj, 7, 63);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "Temp °C");
                                            add_style_label_title(obj);
                                        }
                                        {
                                            // humidity
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.humidity = obj;
                                            lv_obj_set_pos(obj, 7, 91);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "Humidity 00%");
                                            add_style_label_title(obj);
                                        }
                                        {
                                            // wind_speed
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.wind_speed = obj;
                                            lv_obj_set_pos(obj, 7, 119);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "Wind Speed");
                                            add_style_label_title(obj);
                                        }
                                        {
                                            // weather_img
                                            lv_obj_t *obj = lv_img_create(parent_obj);
                                            objects.weather_img = obj;
                                            lv_obj_set_pos(obj, 247, 77);
                                            lv_obj_set_size(obj, 60, 60);
                                            lv_img_set_src(obj, &img_weather);
                                            lv_img_set_pivot(obj, 0, 0);
                                        }
                                    }
                                }
                            }
                        }
                        {
                            // Tab 1
                            lv_obj_t *obj = lv_tabview_add_tab(lv_obj_get_parent(parent_obj), "Monitor");
                            objects.tab_1 = obj;
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_bg_img_src(obj, &img_black_vector, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Monitor");
                                    add_style_label_title(obj);
                                }
                                {
                                    // CPU
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.cpu = obj;
                                    lv_obj_set_pos(obj, 0, 50);
                                    lv_obj_set_size(obj, 315, 145);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_add_event_cb(obj, event_handler_cb_main_cpu, LV_EVENT_ALL, flowState);
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                    add_style_container(obj);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 6, 6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "CPU");
                                            add_style_label_title(obj);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                        {
                                            // cpu_load_arc
                                            lv_obj_t *obj = lv_arc_create(parent_obj);
                                            objects.cpu_load_arc = obj;
                                            lv_obj_set_pos(obj, 6, 35);
                                            lv_obj_set_size(obj, 97, 88);
                                            lv_arc_set_value(obj, 25);
                                            lv_arc_set_bg_start_angle(obj, 80);
                                            lv_arc_set_bg_end_angle(obj, 10);
                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                            add_style_arc(obj);
                                        }
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 61, 111);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "Load");
                                            add_style_label_title(obj);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                        {
                                            // cpu_load
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.cpu_load = obj;
                                            lv_obj_set_pos(obj, 27, 72);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "000%");
                                            add_style_label_title(obj);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                        {
                                            // cpu_temp_bar
                                            lv_obj_t *obj = lv_bar_create(parent_obj);
                                            objects.cpu_temp_bar = obj;
                                            lv_obj_set_pos(obj, 114, 35);
                                            lv_obj_set_size(obj, 181, 18);
                                            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
                                            add_style_bar(obj);
                                        }
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 114, 53);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "Teperature");
                                            add_style_label_title(obj);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                        {
                                            // cpu_temperature_c
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.cpu_temperature_c = obj;
                                            lv_obj_set_pos(obj, 244, 53);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "00°C");
                                            add_style_label_title(obj);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                        {
                                            // cpu_clock_bar
                                            lv_obj_t *obj = lv_bar_create(parent_obj);
                                            objects.cpu_clock_bar = obj;
                                            lv_obj_set_pos(obj, 114, 90);
                                            lv_obj_set_size(obj, 181, 18);
                                            lv_bar_set_range(obj, 0, 4800);
                                            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
                                            add_style_bar(obj);
                                        }
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 114, 108);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "Clock");
                                            add_style_label_title(obj);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                        {
                                            // cpu_freq_mhz
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.cpu_freq_mhz = obj;
                                            lv_obj_set_pos(obj, 215, 108);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "0000MHz");
                                            add_style_label_title(obj);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                    }
                                }
                                {
                                    // GPU
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.gpu = obj;
                                    lv_obj_set_pos(obj, 0, 220);
                                    lv_obj_set_size(obj, 315, 145);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_add_event_cb(obj, event_handler_cb_main_gpu, LV_EVENT_ALL, flowState);
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                    add_style_container(obj);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 6, 6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "GPU");
                                            add_style_label_title(obj);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                        {
                                            // gpu_load_arc
                                            lv_obj_t *obj = lv_arc_create(parent_obj);
                                            objects.gpu_load_arc = obj;
                                            lv_obj_set_pos(obj, 6, 35);
                                            lv_obj_set_size(obj, 97, 88);
                                            lv_arc_set_value(obj, 25);
                                            lv_arc_set_bg_start_angle(obj, 80);
                                            lv_arc_set_bg_end_angle(obj, 10);
                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                            add_style_arc(obj);
                                        }
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 61, 111);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "Load");
                                            add_style_label_title(obj);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                        {
                                            // gpu_load
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.gpu_load = obj;
                                            lv_obj_set_pos(obj, 27, 72);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "000%");
                                            add_style_label_title(obj);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                        {
                                            // gpu_temp_bar
                                            lv_obj_t *obj = lv_bar_create(parent_obj);
                                            objects.gpu_temp_bar = obj;
                                            lv_obj_set_pos(obj, 114, 35);
                                            lv_obj_set_size(obj, 181, 18);
                                            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
                                            add_style_bar(obj);
                                        }
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 114, 53);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "Teperature");
                                            add_style_label_title(obj);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                        {
                                            // gpu_temperature
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.gpu_temperature = obj;
                                            lv_obj_set_pos(obj, 244, 53);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "00°C");
                                            add_style_label_title(obj);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                        {
                                            // gpu_clock_bar
                                            lv_obj_t *obj = lv_bar_create(parent_obj);
                                            objects.gpu_clock_bar = obj;
                                            lv_obj_set_pos(obj, 114, 90);
                                            lv_obj_set_size(obj, 181, 18);
                                            lv_bar_set_range(obj, 0, 5000);
                                            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
                                            add_style_bar(obj);
                                        }
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 114, 108);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "Clock");
                                            add_style_label_title(obj);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                        {
                                            // gpu_freq_mhz
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.gpu_freq_mhz = obj;
                                            lv_obj_set_pos(obj, 215, 108);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "0000MHz");
                                            add_style_label_title(obj);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                    }
                                }
                                {
                                    // HDD
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.hdd = obj;
                                    lv_obj_set_pos(obj, 350, 50);
                                    lv_obj_set_size(obj, 345, 145);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_add_event_cb(obj, event_handler_cb_main_hdd, LV_EVENT_ALL, flowState);
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                    add_style_container(obj);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 6, 6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "HDD & MEM");
                                            add_style_label_title(obj);
                                        }
                                        {
                                            // hdd2_usage_bar
                                            lv_obj_t *obj = lv_bar_create(parent_obj);
                                            objects.hdd2_usage_bar = obj;
                                            lv_obj_set_pos(obj, 151, 98);
                                            lv_obj_set_size(obj, 181, 18);
                                            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
                                            add_style_bar(obj);
                                        }
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 151, 116);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "HDD2");
                                            add_style_label_title(obj);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                        {
                                            // hdd2_usage
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.hdd2_usage = obj;
                                            lv_obj_set_pos(obj, 285, 116);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "000%");
                                            add_style_label_title(obj);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                        {
                                            // hdd1_usage_bar
                                            lv_obj_t *obj = lv_bar_create(parent_obj);
                                            objects.hdd1_usage_bar = obj;
                                            lv_obj_set_pos(obj, 151, 58);
                                            lv_obj_set_size(obj, 181, 18);
                                            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
                                            add_style_bar(obj);
                                        }
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 151, 76);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "HDD1");
                                            add_style_label_title(obj);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                        {
                                            // hdd1_usage
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.hdd1_usage = obj;
                                            lv_obj_set_pos(obj, 285, 76);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "000%");
                                            add_style_label_title(obj);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                        {
                                            // hdd0_usage_bar
                                            lv_obj_t *obj = lv_bar_create(parent_obj);
                                            objects.hdd0_usage_bar = obj;
                                            lv_obj_set_pos(obj, 151, 19);
                                            lv_obj_set_size(obj, 181, 18);
                                            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
                                            add_style_bar(obj);
                                        }
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 151, 37);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "HDD0");
                                            add_style_label_title(obj);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                        {
                                            // hdd0_usage
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.hdd0_usage = obj;
                                            lv_obj_set_pos(obj, 285, 37);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "000%");
                                            add_style_label_title(obj);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                        {
                                            // ram_load_arc
                                            lv_obj_t *obj = lv_arc_create(parent_obj);
                                            objects.ram_load_arc = obj;
                                            lv_obj_set_pos(obj, 6, 35);
                                            lv_obj_set_size(obj, 97, 88);
                                            lv_arc_set_value(obj, 25);
                                            lv_arc_set_bg_start_angle(obj, 80);
                                            lv_arc_set_bg_end_angle(obj, 10);
                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                            add_style_arc(obj);
                                        }
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 61, 111);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "Load");
                                            add_style_label_title(obj);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                        {
                                            // mem_load
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.mem_load = obj;
                                            lv_obj_set_pos(obj, 27, 72);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "000%");
                                            add_style_label_title(obj);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                    }
                                }
                            }
                        }
                        {
                            // Tab 3
                            lv_obj_t *obj = lv_tabview_add_tab(lv_obj_get_parent(parent_obj), "ETFs");
                            objects.tab_3 = obj;
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_bg_img_src(obj, &img_black_vector, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_recolor(obj, lv_color_hex(0xff00ff12), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_recolor_opa(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // total_performance
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.total_performance = obj;
                                    lv_obj_set_pos(obj, 0, 407);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text(obj, "Total Performance: [...]");
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 22);
                                    lv_obj_set_size(obj, 315, 100);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    add_style_container(obj);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 6, 6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "EUWAX Gold II");
                                            add_style_label_title(obj);
                                        }
                                        {
                                            // quote_etf_0
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.quote_etf_0 = obj;
                                            lv_obj_set_pos(obj, 20, 45);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "quote_etf_0");
                                        }
                                        {
                                            // value_etf_0
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.value_etf_0 = obj;
                                            lv_obj_set_pos(obj, 20, 70);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "value_etf_0");
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 152);
                                    lv_obj_set_size(obj, 315, 100);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    add_style_container(obj);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 6, 6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "Core MSCI World");
                                            add_style_label_title(obj);
                                        }
                                        {
                                            // quote_etf_1
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.quote_etf_1 = obj;
                                            lv_obj_set_pos(obj, 20, 45);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "quote_etf_1");
                                        }
                                        {
                                            // value_etf_1
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.value_etf_1 = obj;
                                            lv_obj_set_pos(obj, 20, 70);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "value_etf_1");
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 350, 22);
                                    lv_obj_set_size(obj, 315, 100);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    add_style_container(obj);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 6, 6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "MSCI Global Semicon.");
                                            add_style_label_title(obj);
                                        }
                                        {
                                            // quote_etf_2
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.quote_etf_2 = obj;
                                            lv_obj_set_pos(obj, 20, 45);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "quote_etf_2");
                                        }
                                        {
                                            // value_etf_2
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.value_etf_2 = obj;
                                            lv_obj_set_pos(obj, 20, 70);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "value_etf_2");
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 282);
                                    lv_obj_set_size(obj, 315, 100);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    add_style_container(obj);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 6, 6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "Vanguard FTSE All-World");
                                            add_style_label_title(obj);
                                        }
                                        {
                                            // quote_etf_4
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.quote_etf_4 = obj;
                                            lv_obj_set_pos(obj, 20, 45);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "quote_etf_4");
                                        }
                                        {
                                            // value_etf_4
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.value_etf_4 = obj;
                                            lv_obj_set_pos(obj, 20, 70);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "value_etf_4");
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 350, 152);
                                    lv_obj_set_size(obj, 315, 100);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    add_style_container(obj);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 6, 6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "STOXX Europe 600");
                                            add_style_label_title(obj);
                                        }
                                        {
                                            // value_etf_3
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.value_etf_3 = obj;
                                            lv_obj_set_pos(obj, 20, 70);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "value_etf_3");
                                        }
                                        {
                                            // quote_etf_3
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.quote_etf_3 = obj;
                                            lv_obj_set_pos(obj, 20, 45);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "quote_etf_3");
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 350, 282);
                                    lv_obj_set_size(obj, 315, 100);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    add_style_container(obj);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 6, 6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "Xtrackers AI");
                                            add_style_label_title(obj);
                                        }
                                        {
                                            // quote_etf_5
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.quote_etf_5 = obj;
                                            lv_obj_set_pos(obj, 20, 45);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "quote_etf_5");
                                        }
                                        {
                                            // value_etf_5
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.value_etf_5 = obj;
                                            lv_obj_set_pos(obj, 20, 70);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "value_etf_5");
                                        }
                                    }
                                }
                            }
                        }
                        {
                            // Tab 4
                            lv_obj_t *obj = lv_tabview_add_tab(lv_obj_get_parent(parent_obj), "UBAHN");
                            objects.tab_4 = obj;
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_bg_img_recolor(obj, lv_color_hex(0xff0004ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_recolor_opa(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_src(obj, &img_black_vector, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.obj0 = obj;
                                    lv_obj_set_pos(obj, 0, 50);
                                    lv_obj_set_size(obj, 315, 145);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_add_event_cb(obj, event_handler_cb_main_obj0, LV_EVENT_ALL, flowState);
                                    add_style_container(obj);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 6, 6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "U3 - ");
                                            add_style_label_title(obj);
                                        }
                                        {
                                            // departure_time
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.departure_time = obj;
                                            lv_obj_set_pos(obj, 6, 40);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "Departure [...] time");
                                            add_style_label_title(obj);
                                        }
                                        {
                                            // platform
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.platform = obj;
                                            lv_obj_set_pos(obj, 58, 6);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "Platform");
                                            add_style_label_title(obj);
                                        }
                                    }
                                }
                            }
                        }
                        {
                            // Tab 5
                            lv_obj_t *obj = lv_tabview_add_tab(lv_obj_get_parent(parent_obj), "Notes");
                            objects.tab_5 = obj;
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_bg_img_src(obj, &img_black_vector, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_recolor(obj, lv_color_hex(0xfff1ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_img_recolor_opa(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // textarea1
                                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                                    objects.textarea1 = obj;
                                    lv_obj_set_pos(obj, 242, -11);
                                    lv_obj_set_size(obj, 450, 256);
                                    lv_textarea_set_max_length(obj, 128);
                                    lv_textarea_set_one_line(obj, false);
                                    lv_textarea_set_password_mode(obj, false);
                                    lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_PRESSED);
                                    lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN | LV_STATE_PRESSED);
                                }
                                {
                                    // keyBoard
                                    lv_obj_t *obj = lv_keyboard_create(parent_obj);
                                    objects.key_board = obj;
                                    lv_obj_set_pos(obj, 242, 248);
                                    lv_obj_set_size(obj, 450, 190);
                                    lv_obj_set_style_clip_corner(obj, true, LV_PART_ITEMS | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 10, LV_PART_ITEMS | LV_STATE_DEFAULT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                                {
                                    // recolor
                                    lv_obj_t *obj = lv_colorwheel_create(parent_obj, false);
                                    objects.recolor = obj;
                                    lv_obj_set_pos(obj, 39, 136);
                                    lv_obj_set_size(obj, 150, 150);
                                    lv_obj_add_event_cb(obj, event_handler_cb_main_recolor, LV_EVENT_ALL, flowState);
                                }
                                {
                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                    objects.obj1 = obj;
                                    lv_obj_set_pos(obj, 7, 87);
                                    lv_obj_set_size(obj, 215, 42);
                                    lv_obj_add_event_cb(obj, event_handler_cb_main_obj1, LV_EVENT_ALL, flowState);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff424242), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text(obj, "Label Style Color");
                                            add_style_label_title(obj);
                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        {
            // Status Bar
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.status_bar = obj;
            lv_obj_set_pos(obj, 0, 464);
            lv_obj_set_size(obj, 800, 16);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 2, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "System Tick:");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj2 = obj;
                    lv_obj_set_pos(obj, 96, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 495, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Alive:");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // alive_udp
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.alive_udp = obj;
                    lv_obj_set_pos(obj, 537, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "---");
                    add_style_label_title(obj);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 567, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "WIFI IP:");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // ip_text
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.ip_text = obj;
                    lv_obj_set_pos(obj, 629, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "000.000.000.000");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
    lv_keyboard_set_textarea(objects.key_board, objects.textarea1);
}

void tick_screen_main() {
    void *flowState = getFlowState(0, 0);
    {
        const char *new_val = evalTextProperty(flowState, 96, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(objects.obj2);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = objects.obj2;
            lv_label_set_text(objects.obj2, new_val);
            tick_value_change_obj = NULL;
        }
    }
}


extern void add_style(lv_obj_t *obj, int32_t styleIndex);
extern void remove_style(lv_obj_t *obj, int32_t styleIndex);

static const char *screen_names[] = { "Main" };
static const char *object_names[] = { "main", "alive_udp", "calendar", "clima", "clima_description", "clima_main", "cpu", "cpu_clock_bar", "cpu_freq_mhz", "cpu_load", "cpu_load_arc", "cpu_temp_bar", "cpu_temperature_c", "departure_time", "dots", "gpu", "gpu_clock_bar", "gpu_freq_mhz", "gpu_load", "gpu_load_arc", "gpu_temp_bar", "gpu_temperature", "hdd", "hdd0_usage", "hdd0_usage_bar", "hdd1_usage", "hdd1_usage_bar", "hdd2_usage", "hdd2_usage_bar", "hours", "humidity", "ip_text", "key_board", "mem_load", "minutes", "obj0", "obj1", "obj2", "platform", "quote_etf_0", "quote_etf_1", "quote_etf_2", "quote_etf_3", "quote_etf_4", "quote_etf_5", "ram_load_arc", "recolor", "status_bar", "tab_1", "tab_2", "tab_3", "tab_4", "tab_5", "temperature", "textarea1", "time", "total_performance", "value_etf_0", "value_etf_1", "value_etf_2", "value_etf_3", "value_etf_4", "value_etf_5", "weather_img", "wind_speed" };
static const char *style_names[] = { "container", "label_title", "arc", "bar" };

void create_screens() {
    eez_flow_init_styles(add_style, remove_style);
    
    eez_flow_init_screen_names(screen_names, sizeof(screen_names) / sizeof(const char *));
    eez_flow_init_object_names(object_names, sizeof(object_names) / sizeof(const char *));
    eez_flow_init_style_names(style_names, sizeof(style_names) / sizeof(const char *));
    
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
