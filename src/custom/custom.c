/*
 * Copyright 2023 NXP
 * NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"
//#include "LSM6DS3.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
extern uint16_t step_goals;
static void step_goals_values(lv_event_t *e)
{
    lv_ui *ui = lv_event_get_user_data(e);
    lv_label_set_text_fmt(ui->Step_step_goals, "%u", lv_slider_get_value(ui->Step_step_goals_set));
    step_goals = lv_slider_get_value(ui->Step_step_goals_set);
    lv_arc_set_range(ui->Step_curr_steps, 0, step_goals);
    lv_arc_set_range(ui->Home_curr_steps, 0, step_goals);
    //lv_label_set_text_fmt(ui->Home_curr_steps, "%u", lsm_steps());
}
/**
 * Create a demo application
 */

void custom_init(lv_ui *ui)
{

    /* Add your codes here */
}

void custom_init_StepPage(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Step_step_goals_set, step_goals_values, LV_EVENT_VALUE_CHANGED, ui);
}