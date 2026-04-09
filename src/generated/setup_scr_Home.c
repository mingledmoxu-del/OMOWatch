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
#include "src/extra/widgets/dclock/lv_dclock.h"
#include "src/extra/widgets/analogclock/lv_analogclock.h"
#include "LSM6DS3.h"
extern uint16_t step_goals;

int Home_digital_clock_1_min_value = 25;
int Home_digital_clock_1_hour_value = 11;
int Home_digital_clock_1_sec_value = 50;
void setup_scr_Home(lv_ui *ui)
{
    // Write codes Home
    ui->Home = lv_obj_create(NULL);
    lv_obj_set_size(ui->Home, 240, 280);
    lv_obj_set_scrollbar_mode(ui->Home, LV_SCROLLBAR_MODE_OFF);

    // Write style for Home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Home_digital_clock_1
    static bool Home_digital_clock_1_timer_enabled = false;
    ui->Home_digital_clock_1 = lv_dclock_create(ui->Home, "11:25");
    if (!Home_digital_clock_1_timer_enabled)
    {
        lv_timer_create(Home_digital_clock_1_timer, 1000, NULL);
        Home_digital_clock_1_timer_enabled = true;
    }
    lv_obj_set_pos(ui->Home_digital_clock_1, 70, 50);
    lv_obj_set_size(ui->Home_digital_clock_1, 100, 40);

    // Write style for Home_digital_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->Home_digital_clock_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_digital_clock_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_digital_clock_1, &lv_font_CascadiaCode_30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_digital_clock_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_digital_clock_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_digital_clock_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_digital_clock_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_digital_clock_1, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_digital_clock_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_digital_clock_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_digital_clock_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_digital_clock_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Home_curr_steps
    ui->Home_curr_steps = lv_arc_create(ui->Home);
    lv_arc_set_mode(ui->Home_curr_steps, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->Home_curr_steps, 0, 100);
    lv_arc_set_bg_angles(ui->Home_curr_steps, 135, 45);
    lv_arc_set_value(ui->Home_curr_steps, 70);
    lv_arc_set_rotation(ui->Home_curr_steps, 0);
    lv_obj_set_style_arc_rounded(ui->Home_curr_steps, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->Home_curr_steps, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Home_curr_steps, 0, 126);
    lv_obj_set_size(ui->Home_curr_steps, 120, 120);

    // Write style for Home_curr_steps, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_curr_steps, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_curr_steps, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->Home_curr_steps, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Home_curr_steps, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Home_curr_steps, lv_color_hex(0xe6e6e6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_curr_steps, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_curr_steps, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_curr_steps, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_curr_steps, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_curr_steps, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_curr_steps, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style for Home_curr_steps, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->Home_curr_steps, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Home_curr_steps, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Home_curr_steps, lv_color_hex(0x2195f6), LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // Write style for Home_curr_steps, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_curr_steps, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_curr_steps, lv_color_hex(0x2195f6), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_curr_steps, LV_GRAD_DIR_NONE, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->Home_curr_steps, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    // Write codes Home_img_1
    ui->Home_img_1 = lv_img_create(ui->Home);
    lv_obj_add_flag(ui->Home_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Home_img_1, &_stepcounter_alpha_40x40);
    lv_img_set_pivot(ui->Home_img_1, 50, 50);
    lv_img_set_angle(ui->Home_img_1, 0);
    lv_obj_set_pos(ui->Home_img_1, 40, 166);
    lv_obj_set_size(ui->Home_img_1, 40, 40);

    // Write style for Home_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Home_img_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Home_img_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_img_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Home_img_1, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Home_settings
    ui->Home_settings = lv_img_create(ui->Home);
    lv_obj_add_flag(ui->Home_settings, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Home_settings, &_settings_alpha_40x40);
    lv_img_set_pivot(ui->Home_settings, 50, 50);
    lv_img_set_angle(ui->Home_settings, 0);
    lv_obj_set_pos(ui->Home_settings, 160, 166);
    lv_obj_set_size(ui->Home_settings, 40, 40);

    // Write style for Home_settings, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Home_settings, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Home_settings, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_settings, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Home_settings, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Home_step_value
    ui->Home_step_value = lv_label_create(ui->Home);
    lv_label_set_text(ui->Home_step_value, "Label");
    lv_label_set_long_mode(ui->Home_step_value, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_step_value, 35, 224);
    lv_obj_set_size(ui->Home_step_value, 50, 20);

    // Write style for Home_step_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_step_value, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_step_value, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_step_value, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_step_value, &lv_font_CascadiaCode_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_step_value, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_step_value, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_step_value, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_step_value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_step_value, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_step_value, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_step_value, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_step_value, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_step_value, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_step_value, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // The custom code of Home.
    lv_label_set_text_fmt(ui->Home_step_value, "%u", step_goals);
    lv_arc_set_range(ui->Home_curr_steps, 0, step_goals);

    lv_label_set_text_fmt(ui->Home_step_value, "%u", lsm_steps());

    // Update current screen layout.
    lv_obj_update_layout(ui->Home);

    // Init events for screen.
    events_init_Home(ui);
}
