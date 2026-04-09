#include "ST7789.h"
#include "stm32f4xx_hal.h"

extern SPI_HandleTypeDef hspi1;
bool screen_on = true;
extern osThreadId_t defaultTaskHandle;
// 分块缓冲大小

// 发送命令
void lcd_send_cmd(uint8_t cmd)
{
    lcd_cs_low();
    lcd_dc_cmd();
    HAL_SPI_Transmit(&hspi1, &cmd, 1, HAL_MAX_DELAY);
    lcd_cs_high();
}

// 发送数据
void lcd_send_data(uint8_t *data, uint16_t size)
{
    lcd_cs_low();
    lcd_dc_data();
    HAL_SPI_Transmit(&hspi1, data, size, HAL_MAX_DELAY);
    lcd_cs_high();
}

void lcd_16bytes(uint16_t bytes)
{
    uint8_t buf[2];
    buf[0] = bytes >> 8;
    buf[1] = bytes & 0xFF;
    lcd_send_data(buf, 2);
}

// 设置绘制区域（含偏移）
void lcd_set_window(uint16_t x1, uint16_t x2, uint16_t y1, uint16_t y2)
{
    x1 += LCD_X_OFFSET;
    x2 += LCD_X_OFFSET;
    y1 += LCD_Y_OFFSET;
    y2 += LCD_Y_OFFSET;

    uint8_t buf[4];

    lcd_send_cmd(0x2A);
    buf[0] = x1 >> 8;
    buf[1] = x1 & 0xFF;
    buf[2] = x2 >> 8;
    buf[3] = x2 & 0xFF;
    lcd_send_data(buf, 4);

    lcd_send_cmd(0x2B);
    buf[0] = y1 >> 8;
    buf[1] = y1 & 0xFF;
    buf[2] = y2 >> 8;
    buf[3] = y2 & 0xFF;
    lcd_send_data(buf, 4);

    lcd_send_cmd(0x2C);
}

// 内部函数：发送下一块

// 外部调用：开始全屏刷新

// 初始化
void lcd_Init(void)
{
    uint8_t buf[1];
    HAL_GPIO_WritePin(SPI1_BLK_GPIO_Port, SPI1_BLK_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(SPI1_RST_GPIO_Port, SPI1_RST_Pin, GPIO_PIN_RESET);
    HAL_Delay(10);
    HAL_GPIO_WritePin(SPI1_RST_GPIO_Port, SPI1_RST_Pin, GPIO_PIN_SET);
    HAL_Delay(120);

    lcd_send_cmd(0x11);
    HAL_Delay(120);

    lcd_send_cmd(0x3A);
    buf[0] = 0x05;
    lcd_send_data(buf, 1);
    lcd_send_cmd(0xB7);
    buf[0] = 0x35;
    lcd_send_data(buf, 1);
    lcd_send_cmd(0xBB);
    buf[0] = 0x19;
    lcd_send_data(buf, 1);
    lcd_send_cmd(0xC0);
    buf[0] = 0x2C;
    lcd_send_data(buf, 1);
    lcd_send_cmd(0xC2);
    buf[0] = 0x01;
    lcd_send_data(buf, 1);
    lcd_send_cmd(0xC3);
    buf[0] = 0x12;
    lcd_send_data(buf, 1);
    lcd_send_cmd(0xC4);
    buf[0] = 0x20;
    lcd_send_data(buf, 1);
    lcd_send_cmd(0x36);
    buf[0] = 0x00;
    lcd_send_data(buf, 1);
    lcd_send_cmd(0x21);
    lcd_send_cmd(0x29);

    HAL_GPIO_WritePin(SPI1_BLK_GPIO_Port, SPI1_BLK_Pin, GPIO_PIN_SET);
    // lcd_clearsrc(WHITE);
}

// 画点（阻塞）
void lcd_draw_pixel(uint16_t x, uint16_t y, uint16_t color)
{
    lcd_set_window(x, x, y, y);
    uint8_t data[2] = {color >> 8, color & 0xFF};
    lcd_send_data(data, 2);
}

void lcd_clear(uint16_t color)
{
    lcd_set_window(0, 239, 0, 279);
    for (uint32_t i = 0; i < 240 * 280; i++)
    {
        lcd_16bytes(color);
    }
}

void lcd_sleep_in()
{
    lcd_send_cmd(0x28);
    lcd_send_cmd(0x10);
    HAL_GPIO_WritePin(SPI1_BLK_GPIO_Port, SPI1_BLK_Pin, GPIO_PIN_RESET);
    screen_on = false;
    vTaskSuspend(defaultTaskHandle);
}

void lcd_sleep_out()
{
    lcd_send_cmd(0x11); // 先退出睡眠
    HAL_Delay(120);     // 等待至少120ms（手册要求）
    lcd_send_cmd(0x29); // 再开启显示
    HAL_GPIO_WritePin(SPI1_BLK_GPIO_Port, SPI1_BLK_Pin, GPIO_PIN_SET);
    screen_on = true;
    vTaskResume(defaultTaskHandle);
}
