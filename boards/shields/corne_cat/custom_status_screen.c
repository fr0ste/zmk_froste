#include <zephyr/kernel.h>
#include <lvgl.h>

LV_FONT_DECLARE(lv_font_unscii_8);

lv_obj_t *zmk_display_status_screen(void) {
    lv_obj_t *screen = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen, lv_color_black(), 0);
    lv_obj_set_style_bg_opa(screen, LV_OPA_COVER, 0);
    lv_obj_set_style_pad_all(screen, 0, 0);
    lv_obj_set_style_border_width(screen, 0, 0);

    lv_obj_t *cat = lv_label_create(screen);
    lv_label_set_text(cat,
                      "/\\_/\\\n"
                      "( o.o )\n"
                      " > ^ <");
    lv_obj_set_style_text_font(cat, &lv_font_unscii_8, 0);
    lv_obj_set_style_text_color(cat, lv_color_white(), 0);
    lv_obj_set_style_bg_opa(cat, LV_OPA_TRANSP, 0);
    lv_obj_set_x(cat, 4);
    lv_obj_set_y(cat, 32);

    static lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, cat);
    lv_anim_set_values(&a, 32, 8);
    lv_anim_set_duration(&a, 1500);
    lv_anim_set_playback_duration(&a, 1500);
    lv_anim_set_playback_delay(&a, 2000);
    lv_anim_set_repeat_delay(&a, 5000);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_path_cb(&a, lv_anim_path_ease_in_out);
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_obj_set_y);
    lv_anim_start(&a);

    return screen;
}
