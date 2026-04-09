#include "CST816T.h"
#include "stm32f4xx_hal.h"

// I2C 句柄
extern I2C_HandleTypeDef hi2c1;
extern UART_HandleTypeDef huart1;
CST816T_Touch touch;
void CST816T_SendByte(uint8_t Addr, uint8_t Data)
{
    uint8_t Buffer[2] = {Addr, Data};
    HAL_I2C_Master_Transmit(&hi2c1, 0x2A, Buffer, 2, HAL_MAX_DELAY);
}

void CST816T_ReceiveByte(uint8_t Addr, uint8_t *Data)
{
    HAL_I2C_Mem_Read(&hi2c1, 0x2a, Addr, I2C_MEMADD_SIZE_8BIT, Data, 1, HAL_MAX_DELAY);
}

void CST816T_Init(void)
{

    HAL_GPIO_WritePin(I2C1_RST_GPIO_Port, I2C1_RST_Pin, GPIO_PIN_RESET);
    HAL_Delay(10);
    HAL_GPIO_WritePin(I2C1_RST_GPIO_Port, I2C1_RST_Pin, GPIO_PIN_SET);
    HAL_Delay(50);
}

// 读取触摸寄存器
HAL_StatusTypeDef CST816T_ReadReg(uint8_t reg, uint8_t *buf, uint8_t len)
{
    return HAL_I2C_Mem_Read(&hi2c1, CST816T_ADDR, reg, I2C_MEMADD_SIZE_8BIT, buf, len, 100);
}

// 写寄存器（复位或配置用）
HAL_StatusTypeDef CST816T_WriteReg(uint8_t reg, uint8_t *buf, uint8_t len)
{
    return HAL_I2C_Mem_Write(&hi2c1, CST816T_ADDR, reg, I2C_MEMADD_SIZE_8BIT, buf, len, 100);
}

uint8_t x_test()
{
    uint8_t xdata = 0;
    HAL_I2C_Mem_Read(&hi2c1, CST816T_ADDR, CST816T_X_L, I2C_MEMADD_SIZE_8BIT, &xdata, 1, 100);
    return xdata;
}
bool CST816T_GetPoint(void)
{
    uint8_t buf[5];
    uint8_t reg[1] = 0x02;
    HAL_I2C_Master_Transmit(&hi2c1, CST816T_ADDR, reg, 1, 100);

    HAL_I2C_Master_Receive(&hi2c1, CST816T_ADDR,  buf, 5, 100);
    if (buf[0] == 1)
    {
        touch.touched = buf[0] & 0x0F; // 0~2

        touch.x = ((buf[1] & 0x0F) << 8) | buf[2];
        touch.y = ((buf[3] & 0x0F) << 8) | buf[4];
        //printf("x=%d y=%d", touch.x, touch.y);
        return true;
    }
    else
    {
        return false;
    }
}
