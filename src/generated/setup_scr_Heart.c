/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"
 #include "cmsis_os.h"
 extern osThreadId_t heartrateHandle;
 extern osMessageQueueId_t heartrtHandle;
 static uint8_t heart;

static void timer_cb(lv_timer_t *timer)
{
    lv_obj_t *my_label = (lv_obj_t *)timer->user_data;
     xQueuePeek(heartrtHandle,
        &heart
        );

    lv_label_set_text_fmt(my_label, "%d", heart);
}


void setup_scr_Heart(lv_ui *ui)
{
    //Write codes Heart
    ui->Heart = lv_obj_create(NULL);
    lv_obj_set_size(ui->Heart, 240, 280);
    lv_obj_set_scrollbar_mode(ui->Heart, LV_SCROLLBAR_MODE_OFF);

    //Write style for Heart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Heart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Heart, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Heart, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Heart_img_2
    ui->Heart_img_2 = lv_img_create(ui->Heart);
    lv_obj_add_flag(ui->Heart_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Heart_img_2, &_heart_alpha_40x40);
    lv_img_set_pivot(ui->Heart_img_2, 50,50);
    lv_img_set_angle(ui->Heart_img_2, 0);
    lv_obj_set_pos(ui->Heart_img_2, 100, 80);
    lv_obj_set_size(ui->Heart_img_2, 40, 40);

    //Write style for Heart_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Heart_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Heart_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Heart_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Heart_img_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Heart_label_1
    ui->Heart_label_1 = lv_label_create(ui->Heart);
    lv_label_set_text(ui->Heart_label_1, "100");
    lv_label_set_long_mode(ui->Heart_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Heart_label_1, 85, 153);
    lv_obj_set_size(ui->Heart_label_1, 70, 30);

    //Write style for Heart_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Heart_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Heart_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Heart_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Heart_label_1, &lv_font_CascadiaCode_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Heart_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Heart_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Heart_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Heart_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Heart_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Heart_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Heart_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Heart_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Heart_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Heart_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Heart_label_2
    ui->Heart_label_2 = lv_label_create(ui->Heart);
    lv_label_set_text(ui->Heart_label_2, "BPM");
    lv_label_set_long_mode(ui->Heart_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Heart_label_2, 161, 164);
    lv_obj_set_size(ui->Heart_label_2, 30, 14);

    //Write style for Heart_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Heart_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Heart_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Heart_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Heart_label_2, &lv_font_CascadiaCode_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Heart_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Heart_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Heart_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Heart_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Heart_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Heart_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Heart_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Heart_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Heart_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Heart_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Heart_img_3
    ui->Heart_img_3 = lv_img_create(ui->Heart);
    lv_obj_add_flag(ui->Heart_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Heart_img_3, &_back_alpha_50x50);
    lv_img_set_pivot(ui->Heart_img_3, 50,50);
    lv_img_set_angle(ui->Heart_img_3, 0);
    lv_obj_set_pos(ui->Heart_img_3, 10, 10);
    lv_obj_set_size(ui->Heart_img_3, 50, 50);

    //Write style for Heart_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Heart_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Heart_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Heart_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Heart_img_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Heart.
    lv_timer_create(timer_cb, 500, ui->Heart_label_1);

    //Update current screen layout.
    lv_obj_update_layout(ui->Heart);

    //Init events for screen.
    events_init_Heart(ui);
}
