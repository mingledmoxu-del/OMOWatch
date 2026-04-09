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



void setup_scr_Bluetooth(lv_ui *ui)
{
    //Write codes Bluetooth
    ui->Bluetooth = lv_obj_create(NULL);
    lv_obj_set_size(ui->Bluetooth, 240, 280);
    lv_obj_set_scrollbar_mode(ui->Bluetooth, LV_SCROLLBAR_MODE_OFF);

    //Write style for Bluetooth, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Bluetooth, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Bluetooth, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Bluetooth, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Bluetooth_img_1
    ui->Bluetooth_img_1 = lv_img_create(ui->Bluetooth);
    lv_obj_add_flag(ui->Bluetooth_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Bluetooth_img_1, &_back_alpha_50x50);
    lv_img_set_pivot(ui->Bluetooth_img_1, 50,50);
    lv_img_set_angle(ui->Bluetooth_img_1, 0);
    lv_obj_set_pos(ui->Bluetooth_img_1, 10, 10);
    lv_obj_set_size(ui->Bluetooth_img_1, 50, 50);

    //Write style for Bluetooth_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Bluetooth_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Bluetooth_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Bluetooth_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Bluetooth_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Bluetooth.


    //Update current screen layout.
    lv_obj_update_layout(ui->Bluetooth);

    //Init events for screen.
    events_init_Bluetooth(ui);
}
