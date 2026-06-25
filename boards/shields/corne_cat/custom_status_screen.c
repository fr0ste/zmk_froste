#include <zephyr/kernel.h>
#include <lvgl.h>

lv_obj_t *zmk_display_status_screen(void) {
    lv_obj_t *screen = lv_obj_create(NULL);

    lv_obj_t *cat = lv_label_create(screen);
    lv_label_set_text(cat, "=^.^=");
    lv_obj_center(cat);

    return screen;
}
