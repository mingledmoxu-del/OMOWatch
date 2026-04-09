/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *Home;
	bool Home_del;
	lv_obj_t *Home_digital_clock_1;
	lv_obj_t *Home_curr_steps;
	lv_obj_t *Home_img_1;
	lv_obj_t *Home_settings;
	lv_obj_t *Home_step_value;
	lv_obj_t *Step;
	bool Step_del;
	lv_obj_t *Step_curr_steps;
	lv_obj_t *Step_img_1;
	lv_obj_t *Step_step_goals_set;
	lv_obj_t *Step_step_goals;
	lv_obj_t *Step_img_2;
	lv_obj_t *Heart;
	bool Heart_del;
	lv_obj_t *Heart_img_2;
	lv_obj_t *Heart_label_1;
	lv_obj_t *Heart_label_2;
	lv_obj_t *Heart_img_3;
	lv_obj_t *Setting;
	bool Setting_del;
	lv_obj_t *Setting_list_1;
	lv_obj_t *Setting_list_1_item0;
	lv_obj_t *Setting_list_1_item1;
	lv_obj_t *Setting_list_1_item2;
	lv_obj_t *Setting_list_1_item3;
	lv_obj_t *Setting_list_1_item4;
	lv_obj_t *Setting_list_1_item5;
	lv_obj_t *Bluetooth;
	bool Bluetooth_del;
	lv_obj_t *Bluetooth_img_1;
	lv_obj_t *NFC;
	bool NFC_del;
	lv_obj_t *NFC_img_1;
	lv_obj_t *Battery;
	bool Battery_del;
	lv_obj_t *Battery_img_1;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_Home(lv_ui *ui);
void setup_scr_Step(lv_ui *ui);
void setup_scr_Heart(lv_ui *ui);
void setup_scr_Setting(lv_ui *ui);
void setup_scr_Bluetooth(lv_ui *ui);
void setup_scr_NFC(lv_ui *ui);
void setup_scr_Battery(lv_ui *ui);
LV_IMG_DECLARE(_stepcounter_alpha_40x40);
LV_IMG_DECLARE(_settings_alpha_40x40);
LV_IMG_DECLARE(_stepcounter_alpha_40x40);
LV_IMG_DECLARE(_back_alpha_50x50);
LV_IMG_DECLARE(_heart_alpha_40x40);
LV_IMG_DECLARE(_back_alpha_50x50);
LV_IMG_DECLARE(_back_alpha_50x50);
LV_IMG_DECLARE(_back_alpha_50x50);
LV_IMG_DECLARE(_back_alpha_50x50);

LV_FONT_DECLARE(lv_font_CascadiaCode_30)
LV_FONT_DECLARE(lv_font_CascadiaCode_16)
LV_FONT_DECLARE(lv_font_CascadiaCode_12)


#ifdef __cplusplus
}
#endif
#endif
