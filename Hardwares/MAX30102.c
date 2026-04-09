#include "MAX30102.h"

void max_ID()
{
    uint8_t id = 0;
    HAL_I2C_Mem_Read(&hi2c2, max_read_addr, 0xff, I2C_MEMADD_SIZE_8BIT, &id, 1, HAL_MAX_DELAY);
    printf("%x", id);
}

void max_Init()
{
    uint8_t data;

    // 复位设备
    data = 0x40; // RESET

    HAL_I2C_Mem_Write(&hi2c2, 0xAE, 0x09, I2C_MEMADD_SIZE_8BIT, &data, 1, HAL_MAX_DELAY);
    HAL_Delay(100);

    // FIFO 配置: sample avg = 4, FIFO rollover disable, almost full = 17
    data = 0x4F;
    HAL_I2C_Mem_Write(&hi2c2, 0xAE, 0x08, I2C_MEMADD_SIZE_8BIT, &data, 1, HAL_MAX_DELAY);

    // Mode 配置: SPO2模式（红光 + 红外）
    data = 0x03;
    HAL_I2C_Mem_Write(&hi2c2, 0xAE, 0x09, I2C_MEMADD_SIZE_8BIT, &data, 1, HAL_MAX_DELAY);

    // SPO2 配置: ADC range = 4096nA, sample rate = 100Hz, pulse width = 411us
    data = 0x27;
    HAL_I2C_Mem_Write(&hi2c2, 0xAE, 0x0A, I2C_MEMADD_SIZE_8BIT, &data, 1, HAL_MAX_DELAY);

    // 设置 LED 电流（最大值 0xFF）
    uint8_t red_led_amp = 0x24;
    uint8_t ir_led_amp = 0x24;
    HAL_I2C_Mem_Write(&hi2c2, 0xAE, 0x0C, I2C_MEMADD_SIZE_8BIT, &red_led_amp, 1, HAL_MAX_DELAY);
    HAL_I2C_Mem_Write(&hi2c2, 0xAE, 0x0D, I2C_MEMADD_SIZE_8BIT, &ir_led_amp, 1, HAL_MAX_DELAY);
}

void max_read_data(uint32_t *red_led, uint32_t *ir_led)
{
    uint8_t fifo_data[6];

    // 连续读取6字节 (RED + IR 各3字节)
    HAL_I2C_Mem_Read(&hi2c2, max_read_addr, 0x07,
                     I2C_MEMADD_SIZE_8BIT, fifo_data, 6, HAL_MAX_DELAY);

    // RED
    *red_led = ((uint32_t)(fifo_data[0] & 0x03) << 16) |
               ((uint32_t)fifo_data[1] << 8) |
               (uint32_t)fifo_data[2];

    // IR
    *ir_led = ((uint32_t)(fifo_data[3] & 0x03) << 16) |
              ((uint32_t)fifo_data[4] << 8) |
              (uint32_t)fifo_data[5];

    // printf("%d\r\n", *red_led);
}

uint32_t max_ir()
{
    uint8_t fifo_data[6];
    HAL_I2C_Mem_Read(&hi2c2, max_read_addr, 0x07,
                     I2C_MEMADD_SIZE_8BIT, fifo_data, 6, HAL_MAX_DELAY); // IR
    return ((uint32_t)(fifo_data[3] & 0x03) << 16) |
           ((uint32_t)fifo_data[4] << 8) |
           (uint32_t)fifo_data[5];

    
}

#define IR_FILTER_ALPHA 0.1f // 滑动平均系数，0~1 越小越平滑

float ir_filtered_value = 0; // 滤波后的IR值，初始化为0
float ir_dc_estimate = 0;    // 直流分量估计

float max_ir_filtered()
{
    uint8_t fifo_data[6];
    HAL_I2C_Mem_Read(&hi2c2, max_read_addr, 0x07,
                     I2C_MEMADD_SIZE_8BIT, fifo_data, 6, HAL_MAX_DELAY);

    // 原始IR数据
    uint32_t ir_raw = ((uint32_t)(fifo_data[3] & 0x03) << 16) |
                      ((uint32_t)fifo_data[4] << 8) |
                      (uint32_t)fifo_data[5];

    // -----------------------------
    // 1. 去直流（简单低通滤波估计DC）
    // -----------------------------
    ir_dc_estimate = ir_dc_estimate * (1.0f - IR_FILTER_ALPHA) + ir_raw * IR_FILTER_ALPHA;
    float ir_ac = ir_raw - ir_dc_estimate;

    // -----------------------------
    // 2. 一阶平滑滤波
    // -----------------------------
    ir_filtered_value = ir_filtered_value * (1.0f - IR_FILTER_ALPHA) + ir_ac * IR_FILTER_ALPHA;

    return ir_filtered_value;
}
