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



void setup_scr_Setting(lv_ui *ui)
{
    //Write codes Setting
    ui->Setting = lv_obj_create(NULL);
    lv_obj_set_size(ui->Setting, 240, 280);
    lv_obj_set_scrollbar_mode(ui->Setting, LV_SCROLLBAR_MODE_OFF);

    //Write style for Setting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Setting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Setting, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Setting, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_list_1
    ui->Setting_list_1 = lv_list_create(ui->Setting);
    ui->Setting_list_1_item0 = lv_list_add_btn(ui->Setting_list_1, LV_SYMBOL_HOME, "Home");
    ui->Setting_list_1_item1 = lv_list_add_btn(ui->Setting_list_1, LV_SYMBOL_PLUS, "Heart");
    ui->Setting_list_1_item2 = lv_list_add_btn(ui->Setting_list_1, LV_SYMBOL_GPS, "Step");
    ui->Setting_list_1_item3 = lv_list_add_btn(ui->Setting_list_1, LV_SYMBOL_BLUETOOTH, "Bluetooth");
    ui->Setting_list_1_item4 = lv_list_add_btn(ui->Setting_list_1, LV_SYMBOL_FILE, "NFC");
    ui->Setting_list_1_item5 = lv_list_add_btn(ui->Setting_list_1, LV_SYMBOL_BATTERY_FULL, "Battery");
    lv_obj_set_pos(ui->Setting_list_1, 0, 0);
    lv_obj_set_size(ui->Setting_list_1, 240, 280);
    lv_obj_set_scrollbar_mode(ui->Setting_list_1, LV_SCROLLBAR_MODE_OFF);

    //Write style state: LV_STATE_DEFAULT for &style_Setting_list_1_main_main_default
    static lv_style_t style_Setting_list_1_main_main_default;
    ui_init_style(&style_Setting_list_1_main_main_default);

    lv_style_set_pad_top(&style_Setting_list_1_main_main_default, 5);
    lv_style_set_pad_left(&style_Setting_list_1_main_main_default, 5);
    lv_style_set_pad_right(&style_Setting_list_1_main_main_default, 5);
    lv_style_set_pad_bottom(&style_Setting_list_1_main_main_default, 5);
    lv_style_set_bg_opa(&style_Setting_list_1_main_main_default, 255);
    lv_style_set_bg_color(&style_Setting_list_1_main_main_default, lv_color_hex(0x000000));
    lv_style_set_bg_grad_dir(&style_Setting_list_1_main_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_Setting_list_1_main_main_default, 0);
    lv_style_set_radius(&style_Setting_list_1_main_main_default, 3);
    lv_style_set_shadow_width(&style_Setting_list_1_main_main_default, 0);
    lv_obj_add_style(ui->Setting_list_1, &style_Setting_list_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_Setting_list_1_main_scrollbar_default
    static lv_style_t style_Setting_list_1_main_scrollbar_default;
    ui_init_style(&style_Setting_list_1_main_scrollbar_default);

    lv_style_set_radius(&style_Setting_list_1_main_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_Setting_list_1_main_scrollbar_default, 255);
    lv_style_set_bg_color(&style_Setting_list_1_main_scrollbar_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_Setting_list_1_main_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->Setting_list_1, &style_Setting_list_1_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_Setting_list_1_extra_btns_main_default
    static lv_style_t style_Setting_list_1_extra_btns_main_default;
    ui_init_style(&style_Setting_list_1_extra_btns_main_default);

    lv_style_set_pad_top(&style_Setting_list_1_extra_btns_main_default, 5);
    lv_style_set_pad_left(&style_Setting_list_1_extra_btns_main_default, 5);
    lv_style_set_pad_right(&style_Setting_list_1_extra_btns_main_default, 5);
    lv_style_set_pad_bottom(&style_Setting_list_1_extra_btns_main_default, 5);
    lv_style_set_border_width(&style_Setting_list_1_extra_btns_main_default, 3);
    lv_style_set_border_opa(&style_Setting_list_1_extra_btns_main_default, 255);
    lv_style_set_border_color(&style_Setting_list_1_extra_btns_main_default, lv_color_hex(0x7f7878));
    lv_style_set_border_side(&style_Setting_list_1_extra_btns_main_default, LV_BORDER_SIDE_BOTTOM);
    lv_style_set_text_color(&style_Setting_list_1_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_Setting_list_1_extra_btns_main_default, &lv_font_CascadiaCode_30);
    lv_style_set_text_opa(&style_Setting_list_1_extra_btns_main_default, 255);
    lv_style_set_radius(&style_Setting_list_1_extra_btns_main_default, 3);
    lv_style_set_bg_opa(&style_Setting_list_1_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_Setting_list_1_extra_btns_main_default, lv_color_hex(0x000000));
    lv_style_set_bg_grad_dir(&style_Setting_list_1_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->Setting_list_1_item5, &style_Setting_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->Setting_list_1_item4, &style_Setting_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->Setting_list_1_item3, &style_Setting_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->Setting_list_1_item2, &style_Setting_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->Setting_list_1_item1, &style_Setting_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->Setting_list_1_item0, &style_Setting_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_PRESSED for &style_Setting_list_1_extra_btns_main_pressed
    static lv_style_t style_Setting_list_1_extra_btns_main_pressed;
    ui_init_style(&style_Setting_list_1_extra_btns_main_pressed);

    lv_style_set_pad_top(&style_Setting_list_1_extra_btns_main_pressed, 5);
    lv_style_set_pad_left(&style_Setting_list_1_extra_btns_main_pressed, 5);
    lv_style_set_pad_right(&style_Setting_list_1_extra_btns_main_pressed, 5);
    lv_style_set_pad_bottom(&style_Setting_list_1_extra_btns_main_pressed, 5);
    lv_style_set_border_width(&style_Setting_list_1_extra_btns_main_pressed, 3);
    lv_style_set_border_opa(&style_Setting_list_1_extra_btns_main_pressed, 255);
    lv_style_set_border_color(&style_Setting_list_1_extra_btns_main_pressed, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_Setting_list_1_extra_btns_main_pressed, LV_BORDER_SIDE_BOTTOM);
    lv_style_set_radius(&style_Setting_list_1_extra_btns_main_pressed, 3);
    lv_style_set_text_color(&style_Setting_list_1_extra_btns_main_pressed, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_Setting_list_1_extra_btns_main_pressed, &lv_font_CascadiaCode_30);
    lv_style_set_text_opa(&style_Setting_list_1_extra_btns_main_pressed, 255);
    lv_style_set_bg_opa(&style_Setting_list_1_extra_btns_main_pressed, 255);
    lv_style_set_bg_color(&style_Setting_list_1_extra_btns_main_pressed, lv_color_hex(0x1e1e1e));
    lv_style_set_bg_grad_dir(&style_Setting_list_1_extra_btns_main_pressed, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->Setting_list_1_item5, &style_Setting_list_1_extra_btns_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_add_style(ui->Setting_list_1_item4, &style_Setting_list_1_extra_btns_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_add_style(ui->Setting_list_1_item3, &style_Setting_list_1_extra_btns_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_add_style(ui->Setting_list_1_item2, &style_Setting_list_1_extra_btns_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_add_style(ui->Setting_list_1_item1, &style_Setting_list_1_extra_btns_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_add_style(ui->Setting_list_1_item0, &style_Setting_list_1_extra_btns_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style state: LV_STATE_FOCUSED for &style_Setting_list_1_extra_btns_main_focused
    static lv_style_t style_Setting_list_1_extra_btns_main_focused;
    ui_init_style(&style_Setting_list_1_extra_btns_main_focused);

    lv_style_set_pad_top(&style_Setting_list_1_extra_btns_main_focused, 5);
    lv_style_set_pad_left(&style_Setting_list_1_extra_btns_main_focused, 5);
    lv_style_set_pad_right(&style_Setting_list_1_extra_btns_main_focused, 5);
    lv_style_set_pad_bottom(&style_Setting_list_1_extra_btns_main_focused, 5);
    lv_style_set_border_width(&style_Setting_list_1_extra_btns_main_focused, 3);
    lv_style_set_border_opa(&style_Setting_list_1_extra_btns_main_focused, 255);
    lv_style_set_border_color(&style_Setting_list_1_extra_btns_main_focused, lv_color_hex(0x7f7878));
    lv_style_set_border_side(&style_Setting_list_1_extra_btns_main_focused, LV_BORDER_SIDE_BOTTOM);
    lv_style_set_radius(&style_Setting_list_1_extra_btns_main_focused, 3);
    lv_style_set_text_color(&style_Setting_list_1_extra_btns_main_focused, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_Setting_list_1_extra_btns_main_focused, &lv_font_CascadiaCode_30);
    lv_style_set_text_opa(&style_Setting_list_1_extra_btns_main_focused, 255);
    lv_style_set_bg_opa(&style_Setting_list_1_extra_btns_main_focused, 255);
    lv_style_set_bg_color(&style_Setting_list_1_extra_btns_main_focused, lv_color_hex(0x000000));
    lv_style_set_bg_grad_dir(&style_Setting_list_1_extra_btns_main_focused, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->Setting_list_1_item5, &style_Setting_list_1_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_add_style(ui->Setting_list_1_item4, &style_Setting_list_1_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_add_style(ui->Setting_list_1_item3, &style_Setting_list_1_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_add_style(ui->Setting_list_1_item2, &style_Setting_list_1_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_add_style(ui->Setting_list_1_item1, &style_Setting_list_1_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_add_style(ui->Setting_list_1_item0, &style_Setting_list_1_extra_btns_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style state: LV_STATE_DEFAULT for &style_Setting_list_1_extra_texts_main_default
    static lv_style_t style_Setting_list_1_extra_texts_main_default;
    ui_init_style(&style_Setting_list_1_extra_texts_main_default);

    lv_style_set_pad_top(&style_Setting_list_1_extra_texts_main_default, 5);
    lv_style_set_pad_left(&style_Setting_list_1_extra_texts_main_default, 5);
    lv_style_set_pad_right(&style_Setting_list_1_extra_texts_main_default, 5);
    lv_style_set_pad_bottom(&style_Setting_list_1_extra_texts_main_default, 5);
    lv_style_set_border_width(&style_Setting_list_1_extra_texts_main_default, 0);
    lv_style_set_text_color(&style_Setting_list_1_extra_texts_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_Setting_list_1_extra_texts_main_default, &lv_font_CascadiaCode_12);
    lv_style_set_text_opa(&style_Setting_list_1_extra_texts_main_default, 255);
    lv_style_set_radius(&style_Setting_list_1_extra_texts_main_default, 3);
    lv_style_set_transform_width(&style_Setting_list_1_extra_texts_main_default, 0);
    lv_style_set_bg_opa(&style_Setting_list_1_extra_texts_main_default, 255);
    lv_style_set_bg_color(&style_Setting_list_1_extra_texts_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_Setting_list_1_extra_texts_main_default, LV_GRAD_DIR_NONE);

    //The custom code of Setting.


    //Update current screen layout.
    lv_obj_update_layout(ui->Setting);

    //Init events for screen.
    events_init_Setting(ui);
}
