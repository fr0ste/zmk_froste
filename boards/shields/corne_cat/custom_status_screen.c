#include <zephyr/kernel.h>
#include <lvgl.h>

lv_obj_t *zmk_display_status_screen(void) {
    lv_obj_t *screen = lv_obj_create(NULL);

    lv_obj_t *label = lv_label_create(screen);
    lv_label_set_text(label, "CAT");
    lv_obj_align(label, LV_ALIGN_TOP_LEFT, 2, 2);

    return screen;
}
