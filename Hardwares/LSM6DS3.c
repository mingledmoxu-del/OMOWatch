#include "LSM6DS3.h"

void device_ID()
{
    uint8_t buf = 0;
    HAL_I2C_Mem_Read(&hi2c3, lsm_read_addr, 0x0f, I2C_MEMADD_SIZE_8BIT, &buf, 1, HAL_MAX_DELAY);
    printf("%x", buf);
}

void lsm_Init()
{
    uint8_t buf;

    /* Step 1: 开启 FUNC_CFG_ACCESS，进入 Page 1 */
    buf = 0x80;
    HAL_I2C_Mem_Write(&hi2c3, lsm_write_addr, 0x01, I2C_MEMADD_SIZE_8BIT, &buf, 1, HAL_MAX_DELAY);
    HAL_Delay(10);

    /* Step 2: 启用嵌入式功能中的 Pedometer */
    buf = 0x14;                                                                                    // PEDO_EN = 1
    HAL_I2C_Mem_Write(&hi2c3, lsm_write_addr, 0x04, I2C_MEMADD_SIZE_8BIT, &buf, 1, HAL_MAX_DELAY); // Page 1: EMB_FUNC_EN_B
    HAL_Delay(10);

    /* Step 3: 退出 FUNC_CFG_ACCESS，回到主寄存器页 */
    buf = 0x00;
    HAL_I2C_Mem_Write(&hi2c3, lsm_write_addr, 0x01, I2C_MEMADD_SIZE_8BIT, &buf, 1, HAL_MAX_DELAY);
    HAL_Delay(10);

    /* Step 4: 设置加速度计 ODR 和量程（CTRL1_XL） */
    buf = 0x40; // 104Hz, ±2g
    HAL_I2C_Mem_Write(&hi2c3, lsm_write_addr, 0x10, I2C_MEMADD_SIZE_8BIT, &buf, 1, HAL_MAX_DELAY);
    HAL_Delay(10);

    /* Step 5: 开启传感器处理链（TAP_CFG） */
    buf = 0x40; // Enable embedded functions routing to sensor hub
    HAL_I2C_Mem_Write(&hi2c3, lsm_write_addr, 0x58, I2C_MEMADD_SIZE_8BIT, &buf, 1, HAL_MAX_DELAY);
    HAL_Delay(10);

    /* Step 6: 启用 Pedometer 引擎（CTRL10_C） */
    buf = 0x3C; // FUNC_EN (bit5) | PEDO_EN (bit2) | SIGN_MOTION_EN (bit4)
    HAL_I2C_Mem_Write(&hi2c3, lsm_write_addr, 0x19, I2C_MEMADD_SIZE_8BIT, &buf, 1, HAL_MAX_DELAY);
    HAL_Delay(10);

    /* Step 7: 启用嵌入式功能引擎（CTRL9_XL） */
    buf = 0x20; // DEN_XL_EN，允许嵌入式功能访问加速度计
    HAL_I2C_Mem_Write(&hi2c3, lsm_write_addr, 0x11, I2C_MEMADD_SIZE_8BIT, &buf, 1, HAL_MAX_DELAY);
    HAL_Delay(10);

    buf = 0x20; // MD1_CFG: SIGN_MOTION_INT1 = 1
    HAL_I2C_Mem_Write(&hi2c3, lsm_write_addr, 0x0B, I2C_MEMADD_SIZE_8BIT, &buf, 1, HAL_MAX_DELAY);
}

uint16_t lsm_steps()
{
    uint8_t buf[2] = 0;
    uint16_t steps;
    HAL_I2C_Mem_Read(&hi2c3, lsm_read_addr, 0x4b, I2C_MEMADD_SIZE_8BIT, buf, 2, HAL_MAX_DELAY);
    steps = (buf[1] << 8) + buf[0];
    return steps;
}