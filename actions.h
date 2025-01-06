#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_drag_event_handler(lv_event_t * e);
extern void action_color_wheel_event(lv_event_t * e);
extern void action_reset_color_event(lv_event_t * e);
extern void action_calendar_selected_event(lv_event_t * e);
extern void action_clear_highlighted_days(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/