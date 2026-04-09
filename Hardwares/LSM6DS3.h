#ifndef __LSM6DS3_H
#define __LSM6DS3_H

#include "stm32f4xx_hal.h"
#include "stdio.h"
extern I2C_HandleTypeDef hi2c3;

#define lsm_read_addr 0xd5
#define lsm_write_addr 0xd4

void device_ID();
void lsm_Init();
uint16_t lsm_steps();

#endif // !__LSM6DS3_H
