#ifndef __CST816T_H
#define __CST816T_H
#include "stm32f4xx_hal.h"
#include "spi.h"
#include "stdio.h"
#include "stdbool.h"

#define CST816T_ADDR 0x2b      // STM32 HAL 用 8 位地址
#define CST816T_REG_POINT 0x02 // 触摸坐标应答  寄存器
#define CST816T_X_L 0x04       // 触摸X轴坐标高八位
#define TOUCH_Y_OFFSET 20

typedef struct
{
    uint8_t touched;
    uint16_t x;
    uint16_t y;
} CST816T_Touch;

extern CST816T_Touch touch; // 声明，不是定义
uint8_t x_test();
void CST816T_Init(void);
bool CST816T_GetPoint(void);
#endif
