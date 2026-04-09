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
#include "LSM6DS3.h"
extern uint16_t step_goals;
uint16_t step_goals = 8000;

void setup_scr_Step(lv_ui *ui)
{
    // Write codes Step
    ui->Step = lv_obj_create(NULL);
    lv_obj_set_size(ui->Step, 240, 280);
    lv_obj_set_scrollbar_mode(ui->Step, LV_SCROLLBAR_MODE_OFF);

    // Write style for Step, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Step, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Step, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Step, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Step_curr_steps
    ui->Step_curr_steps = lv_arc_create(ui->Step);
    lv_arc_set_mode(ui->Step_curr_steps, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->Step_curr_steps, 0, 100);
    lv_arc_set_bg_angles(ui->Step_curr_steps, 135, 45);
    lv_arc_set_value(ui->Step_curr_steps, 70);
    lv_arc_set_rotation(ui->Step_curr_steps, 0);
    lv_obj_set_style_arc_rounded(ui->Step_curr_steps, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->Step_curr_steps, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Step_curr_steps, 60, 39);
    lv_obj_set_size(ui->Step_curr_steps, 120, 120);

    // Write style for Step_curr_steps, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Step_curr_steps, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Step_curr_steps, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->Step_curr_steps, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Step_curr_steps, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Step_curr_steps, lv_color_hex(0xe6e6e6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Step_curr_steps, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Step_curr_steps, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Step_curr_steps, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Step_curr_steps, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Step_curr_steps, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Step_curr_steps, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style for Step_curr_steps, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->Step_curr_steps, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Step_curr_steps, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Step_curr_steps, lv_color_hex(0x2195f6), LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // Write style for Step_curr_steps, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Step_curr_steps, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Step_curr_steps, lv_color_hex(0x2195f6), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Step_curr_steps, LV_GRAD_DIR_NONE, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->Step_curr_steps, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    // Write codes Step_img_1
    ui->Step_img_1 = lv_img_create(ui->Step);
    lv_obj_add_flag(ui->Step_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Step_img_1, &_stepcounter_alpha_40x40);
    lv_img_set_pivot(ui->Step_img_1, 50, 50);
    lv_img_set_angle(ui->Step_img_1, 0);
    lv_obj_set_pos(ui->Step_img_1, 100, 79);
    lv_obj_set_size(ui->Step_img_1, 40, 40);

    // Write style for Step_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Step_img_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Step_img_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Step_img_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Step_img_1, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Step_step_goals_set
    ui->Step_step_goals_set = lv_slider_create(ui->Step);
    lv_slider_set_range(ui->Step_step_goals_set, 0, 20000);
    lv_slider_set_mode(ui->Step_step_goals_set, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->Step_step_goals_set, 8000, LV_ANIM_OFF);
    lv_obj_set_pos(ui->Step_step_goals_set, 40, 159);
    lv_obj_set_size(ui->Step_step_goals_set, 160, 6);

    // Write style for Step_step_goals_set, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Step_step_goals_set, 60, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Step_step_goals_set, lv_color_hex(0x2195f6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Step_step_goals_set, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Step_step_goals_set, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->Step_step_goals_set, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Step_step_goals_set, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style for Step_step_goals_set, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Step_step_goals_set, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Step_step_goals_set, lv_color_hex(0x2195f6), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Step_step_goals_set, LV_GRAD_DIR_NONE, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Step_step_goals_set, 4, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // Write style for Step_step_goals_set, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Step_step_goals_set, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Step_step_goals_set, lv_color_hex(0x2195f6), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Step_step_goals_set, LV_GRAD_DIR_NONE, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Step_step_goals_set, 8, LV_PART_KNOB | LV_STATE_DEFAULT);

    // Write codes Step_step_goals
    ui->Step_step_goals = lv_label_create(ui->Step);
    lv_label_set_text(ui->Step_step_goals, "Label");
    lv_label_set_long_mode(ui->Step_step_goals, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Step_step_goals, 70, 191);
    lv_obj_set_size(ui->Step_step_goals, 100, 32);

    // Write style for Step_step_goals, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Step_step_goals, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Step_step_goals, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Step_step_goals, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Step_step_goals, &lv_font_CascadiaCode_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Step_step_goals, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Step_step_goals, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Step_step_goals, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Step_step_goals, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Step_step_goals, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Step_step_goals, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Step_step_goals, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Step_step_goals, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Step_step_goals, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Step_step_goals, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes Step_img_2
    ui->Step_img_2 = lv_img_create(ui->Step);
    lv_obj_add_flag(ui->Step_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Step_img_2, &_back_alpha_50x50);
    lv_img_set_pivot(ui->Step_img_2, 50, 50);
    lv_img_set_angle(ui->Step_img_2, 0);
    lv_obj_set_pos(ui->Step_img_2, 10, 10);
    lv_obj_set_size(ui->Step_img_2, 50, 50);

    // Write style for Step_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Step_img_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Step_img_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Step_img_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Step_img_2, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    // The custom code of Step.
    lv_slider_set_value(ui->Step_step_goals_set, step_goals, LV_ANIM_OFF);
    lv_label_set_text_fmt(ui->Step_step_goals, "%u", step_goals);
    lv_arc_set_range(ui->Step_curr_steps, 0, step_goals);
    //lv_arc_set_value(ui->Home_curr_steps, lsm_steps());
    //lv_label_set_text_fmt(ui->Home_curr_steps, "%u", lsm_steps());
    custom_init_StepPage(ui);

    // Update current screen layout.
    lv_obj_update_layout(ui->Step);

    // Init events for screen.
    events_init_Step(ui);
}
