/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif


static void Home_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Step, guider_ui.Step_del, &guider_ui.Home_del, setup_scr_Step, LV_SCR_LOAD_ANIM_OVER_TOP, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void Home_settings_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Setting, guider_ui.Setting_del, &guider_ui.Home_del, setup_scr_Setting, LV_SCR_LOAD_ANIM_OVER_TOP, 200, 200, true, false);
        break;
    }
    default:
        break;
    }
}

void events_init_Home (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Home_img_1, Home_img_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Home_settings, Home_settings_event_handler, LV_EVENT_ALL, ui);
}

static void Step_img_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Home, guider_ui.Home_del, &guider_ui.Step_del, setup_scr_Home, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 200, true, false);
        break;
    }
    default:
        break;
    }
}

void events_init_Step (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Step_img_2, Step_img_2_event_handler, LV_EVENT_ALL, ui);
}

static void Heart_img_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Home, guider_ui.Home_del, &guider_ui.Heart_del, setup_scr_Home, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 200, true, false);
        break;
    }
    default:
        break;
    }
}

void events_init_Heart (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Heart_img_3, Heart_img_3_event_handler, LV_EVENT_ALL, ui);
}

static void Setting_list_1_item0_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Home, guider_ui.Home_del, &guider_ui.Setting_del, setup_scr_Home, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void Setting_list_1_item1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Heart, guider_ui.Heart_del, &guider_ui.Setting_del, setup_scr_Heart, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void Setting_list_1_item2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Step, guider_ui.Step_del, &guider_ui.Setting_del, setup_scr_Step, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void Setting_list_1_item3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Bluetooth, guider_ui.Bluetooth_del, &guider_ui.Setting_del, setup_scr_Bluetooth, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void Setting_list_1_item4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.NFC, guider_ui.NFC_del, &guider_ui.Setting_del, setup_scr_NFC, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void Setting_list_1_item5_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Battery, guider_ui.Battery_del, &guider_ui.Setting_del, setup_scr_Battery, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_Setting (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Setting_list_1_item0, Setting_list_1_item0_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Setting_list_1_item1, Setting_list_1_item1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Setting_list_1_item2, Setting_list_1_item2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Setting_list_1_item3, Setting_list_1_item3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Setting_list_1_item4, Setting_list_1_item4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Setting_list_1_item5, Setting_list_1_item5_event_handler, LV_EVENT_ALL, ui);
}

static void Bluetooth_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Home, guider_ui.Home_del, &guider_ui.Bluetooth_del, setup_scr_Home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_Bluetooth (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Bluetooth_img_1, Bluetooth_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void NFC_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Home, guider_ui.Home_del, &guider_ui.NFC_del, setup_scr_Home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_NFC (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->NFC_img_1, NFC_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void Battery_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Home, guider_ui.Home_del, &guider_ui.Battery_del, setup_scr_Home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_Battery (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Battery_img_1, Battery_img_1_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
