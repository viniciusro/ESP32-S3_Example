#include "actions.h"
#include <stdbool.h>

/* Array to hold up to 20 highlighted days */
lv_calendar_date_t highlighted_days[20] = { 0 };  // Initialized to 0
uint8_t highlighted_count = 0;                    // Tracks the number of highlighted dates

// Make an object draggable
void action_drag_event_handler(lv_event_t *e) {
  lv_obj_t *obj = lv_event_get_target(e);

  lv_indev_t *indev = lv_indev_get_act();
  if (indev == NULL)
    return;

  lv_point_t vect;
  lv_indev_get_vect(indev, &vect);

  lv_coord_t x = lv_obj_get_x(obj) + vect.x;
  lv_coord_t y = lv_obj_get_y(obj) + vect.y;
  lv_obj_set_pos(obj, x, y);
}

void action_color_wheel_event(lv_event_t *e) {
  lv_obj_t *colorwheel = lv_event_get_target(e);             // Get the colorwheel object
  lv_color_t new_color = lv_colorwheel_get_rgb(colorwheel);  // Get the selected color

  // Get the label object to apply the style to
  //lv_obj_t *label = lv_event_get_user_data(e);  // Assumes the label is passed as user data

  // Update the label's style with the new color
  lv_style_t *style = get_style_label_title_MAIN_DEFAULT();
  lv_style_set_text_color(style, new_color);  // Set the new text color

  // Apply the updated style to the label
  //lv_obj_refresh_style(label, LV_PART_MAIN, LV_STYLE_PROP_ALL);  // Refresh to apply the new style
}

void action_reset_color_event(lv_event_t *e) {
  lv_style_t *style = get_style_label_title_MAIN_DEFAULT();
  lv_style_set_text_color(style, lv_color_hex(0xffffffff));
}

/* Helper function to check if a date is already highlighted */
static int find_highlighted_day(lv_calendar_date_t *date) {
  for (uint8_t i = 0; i < highlighted_count; i++) {
    if (highlighted_days[i].year == date->year && highlighted_days[i].month == date->month && highlighted_days[i].day == date->day) {
      return i;  // Return index if the date is found
    }
  }
  return -1;  // Return -1 if the date is not found
}

/* Event handler for the calendar */
void action_calendar_selected_event(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *obj = lv_event_get_current_target(e);

  //lv_obj_t *calendar = lv_event_get_target(e);

  /* Create a date variable to store the clicked date */
  lv_calendar_date_t date;

  lv_res_t result;

  if (code == LV_EVENT_VALUE_CHANGED) {
    //lv_calendar_date_t date;
    if (lv_calendar_get_pressed_date(obj, &date)) {
      LV_LOG_USER("Clicked date: %02d.%02d.%d", date.day, date.month, date.year);
      /* Get the pressed date from the calendar */
      result = lv_calendar_get_pressed_date(obj, &date);
    }
  }

  /* Get the pressed date from the calendar */
  //lv_res_t result = lv_calendar_get_pressed_date(calendar, &date);

  /* Check if a valid date was pressed */
  if (result == LV_RES_OK) {
    // Serial.println("Calendar: Pressed date: %04d-%02d-%02d", date.year, date.month, date.day);

    /* Check if the date is already highlighted */
    int index = find_highlighted_day(&date);

    if (index >= 0) {
      /* Date is already highlighted, so remove it */
      for (uint8_t i = index; i < highlighted_count - 1; i++) {
        highlighted_days[i] = highlighted_days[i + 1];  // Shift the array left
      }
      highlighted_count--;  // Reduce the count
                            // Serial.println("Calendar: Removed date from highlighted days.");
    } else if (highlighted_count < 20) {
      /* Date is not highlighted, so add it if there's room */
      highlighted_days[highlighted_count].year = date.year;
      highlighted_days[highlighted_count].month = date.month;
      highlighted_days[highlighted_count].day = date.day;
      highlighted_count++;
      // Serial.println("Calendar: Added date to highlighted days.");
    } else {
      // Serial.println("Calendar: No space to add more highlighted days.");
    }

    /* Update the calendar with the new highlighted dates */
    // lv_calendar_set_highlighted_dates(calendar, highlighted_days, highlighted_count);
    lv_calendar_set_highlighted_dates(obj, highlighted_days, highlighted_count);
  }
}

void action_clear_highlighted_days(lv_event_t *e) {
  lv_obj_t *obj = lv_event_get_current_target(e);
  /* Reset the array to zero */
  memset(highlighted_days, 0, sizeof(highlighted_days));  // Clear the array
  highlighted_count = 0;                                  // Reset the count of highlighted days

  /* Update the calendar with an empty list of highlighted dates */
  lv_calendar_set_highlighted_dates(obj, highlighted_days, 20);  // Pass 0 for count
}