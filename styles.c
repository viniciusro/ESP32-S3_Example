#include "styles.h"
#include "images.h"
#include "fonts.h"

//
// Style: container
//

void init_style_container_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_border_color(style, lv_color_hex(0xffcdcdcd));
    lv_style_set_border_width(style, 1);
    lv_style_set_border_side(style, LV_BORDER_SIDE_FULL);
    lv_style_set_outline_width(style, 1);
    lv_style_set_outline_color(style, lv_color_hex(0xffffffff));
    lv_style_set_outline_opa(style, 255);
    lv_style_set_arc_width(style, 2);
    lv_style_set_arc_color(style, lv_color_hex(0xffffffff));
    lv_style_set_arc_opa(style, 255);
    lv_style_set_text_color(style, lv_color_hex(0xffffffff));
    lv_style_set_text_opa(style, 255);
    lv_style_set_text_font(style, &lv_font_montserrat_14);
    lv_style_set_radius(style, 5);
    lv_style_set_clip_corner(style, false);
    lv_style_set_opa(style, 255);
    lv_style_set_border_opa(style, 255);
};

lv_style_t *get_style_container_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_container_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_container(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_container_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_container(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_container_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: label_title
//

void init_style_label_title_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_color(style, lv_color_hex(0xffffffff));
    lv_style_set_text_font(style, &lv_font_montserrat_20);
    lv_style_set_text_letter_space(style, 2);
    lv_style_set_text_align(style, LV_TEXT_ALIGN_RIGHT);
    lv_style_set_bg_opa(style, 0);
};

lv_style_t *get_style_label_title_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_label_title_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_label_title(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_label_title_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_label_title(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_label_title_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: arc
//

void init_style_arc_KNOB_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_opa(style, 0);
    lv_style_set_bg_color(style, lv_color_hex(0xffffffff));
};

lv_style_t *get_style_arc_KNOB_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_arc_KNOB_DEFAULT(style);
    }
    return style;
};

void init_style_arc_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_arc_color(style, lv_color_hex(0xff6a6a6a));
    lv_style_set_arc_opa(style, 150);
    lv_style_set_arc_width(style, 8);
    lv_style_set_arc_rounded(style, false);
};

lv_style_t *get_style_arc_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_arc_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_arc_INDICATOR_DEFAULT(lv_style_t *style) {
    lv_style_set_arc_color(style, lv_color_hex(0xff999999));
    lv_style_set_arc_rounded(style, false);
    lv_style_set_arc_width(style, 8);
};

lv_style_t *get_style_arc_INDICATOR_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_arc_INDICATOR_DEFAULT(style);
    }
    return style;
};

void add_style_arc(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_arc_KNOB_DEFAULT(), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_arc_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_arc_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
};

void remove_style_arc(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_arc_KNOB_DEFAULT(), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_arc_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_arc_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
};

//
// Style: bar
//

void init_style_bar_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_border_opa(style, 80);
    lv_style_set_border_color(style, lv_color_hex(0xff6a6a6a));
    lv_style_set_border_width(style, 20);
    lv_style_set_border_side(style, LV_BORDER_SIDE_FULL);
    lv_style_set_bg_color(style, lv_color_hex(0xff6a6a6a));
    lv_style_set_bg_opa(style, 50);
};

lv_style_t *get_style_bar_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_bar_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_bar_INDICATOR_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xff999999));
    lv_style_set_bg_opa(style, 255);
};

lv_style_t *get_style_bar_INDICATOR_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_bar_INDICATOR_DEFAULT(style);
    }
    return style;
};

void add_style_bar(lv_obj_t *obj) {
    lv_obj_add_style(obj, get_style_bar_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_bar_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
};

void remove_style_bar(lv_obj_t *obj) {
    lv_obj_remove_style(obj, get_style_bar_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_bar_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
};

//
//
//

void add_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*AddStyleFunc)(lv_obj_t *obj);
    static const AddStyleFunc add_style_funcs[] = {
        add_style_container,
        add_style_label_title,
        add_style_arc,
        add_style_bar,
    };
    add_style_funcs[styleIndex](obj);
}

void remove_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*RemoveStyleFunc)(lv_obj_t *obj);
    static const RemoveStyleFunc remove_style_funcs[] = {
        remove_style_container,
        remove_style_label_title,
        remove_style_arc,
        remove_style_bar,
    };
    remove_style_funcs[styleIndex](obj);
}

