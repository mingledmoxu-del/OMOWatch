#ifndef __ST7789_H
#define __ST7789_H
#include "stm32f4xx_hal.h"
#include "spi.h"
#include "stdbool.h"
#include "cmsis_os.h"

#define BLACK 0x0000
#define WHITE 0xFFFF
#define RED 0xF800
#define GREEN 0x07E0
#define BLUE 0x001F
#define YELLOW 0xFFE0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define ORANGE 0xFD20
#define PURPLE 0x8010
#define GRAY 0x8410
#define BROWN 0xA145
#define PINK 0xFC18
#define DARKGREEN 0x03E0
#define DARKBLUE 0x0010
#define LIGHTGRAY 0xC618
#define COLOR_DARKGRAY 0x4208

#define LCD_WIDTH 240
#define LCD_HEIGHT 280
#define LCD_X_OFFSET 0
#define LCD_Y_OFFSET 20
// #define LCD_BLOCK_LINES 16 // 每次 DMA 传输的行数，可根据需求调整
// 内部控制引脚
#define lcd_cs_low() HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, GPIO_PIN_RESET)
#define lcd_cs_high() HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, GPIO_PIN_SET)
#define lcd_dc_cmd() HAL_GPIO_WritePin(SPI1_DC_GPIO_Port, SPI1_DC_Pin, GPIO_PIN_RESET)
#define lcd_dc_data() HAL_GPIO_WritePin(SPI1_DC_GPIO_Port, SPI1_DC_Pin, GPIO_PIN_SET)

void lcd_Init();
void lcd_clear(uint16_t color);
void lcd_draw_pixel(uint16_t x, uint16_t y, uint16_t color);
void lcd_clear_dma(uint16_t color);
void lcd_set_window(uint16_t x1, uint16_t x2, uint16_t y1, uint16_t y2);
void lcd_sleep_in();
void lcd_sleep_out();
#endif
