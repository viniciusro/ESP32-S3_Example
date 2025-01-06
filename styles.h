#ifndef EEZ_LVGL_UI_STYLES_H
#define EEZ_LVGL_UI_STYLES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Style: container
lv_style_t *get_style_container_MAIN_DEFAULT();
void add_style_container(lv_obj_t *obj);
void remove_style_container(lv_obj_t *obj);

// Style: label_title
lv_style_t *get_style_label_title_MAIN_DEFAULT();
void add_style_label_title(lv_obj_t *obj);
void remove_style_label_title(lv_obj_t *obj);

// Style: arc
lv_style_t *get_style_arc_KNOB_DEFAULT();
lv_style_t *get_style_arc_MAIN_DEFAULT();
lv_style_t *get_style_arc_INDICATOR_DEFAULT();
void add_style_arc(lv_obj_t *obj);
void remove_style_arc(lv_obj_t *obj);

// Style: bar
lv_style_t *get_style_bar_MAIN_DEFAULT();
lv_style_t *get_style_bar_INDICATOR_DEFAULT();
void add_style_bar(lv_obj_t *obj);
void remove_style_bar(lv_obj_t *obj);



#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_STYLES_H*/