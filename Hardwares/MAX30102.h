#ifndef __MAX30102_H
#define __MAX30102_H

#include "stm32f4xx_hal.h"
#include "stdio.h"
#include "cmsis_os.h"
extern I2C_HandleTypeDef hi2c2;

#define max_read_addr 0xaf
#define max_write_addr 0xae
#define FS 100          // 采样率 100Hz
#define BUFFER_SIZE 100 // 存 5 秒数据
#define MIN_HR_BPM 40
#define MAX_HR_BPM 180

void max_ID();
void max_Init();
void max_read_data(uint32_t *red_led, uint32_t *ir_led);
uint32_t max_ir();
void max_heartrate();
float max_ir_filtered();
#endif // !__MAX30102_H
