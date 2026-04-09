/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : freertos.c
 * Description        : Code for freertos applications
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ST7789.h"
#include "algorithm.h"
#include "MAX30102.h"
#include "../generated/gui_guider.h"
#include "../generated/events_init.h"
#include "queue.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
extern bool screen_on;

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
    .name = "defaultTask",
    .stack_size = 512 * 4,
    .priority = (osPriority_t)osPriorityNormal,
};
/* Definitions for heartrate */
osThreadId_t heartrateHandle;
const osThreadAttr_t heartrate_attributes = {
    .name = "heartrate",
    .stack_size = 256 * 4,
    .priority = (osPriority_t)osPriorityHigh,
};
/* Definitions for heartrt */
osMessageQueueId_t heartrtHandle;
const osMessageQueueAttr_t heartrt_attributes = {
    .name = "heartrt"};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void hearttask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* Hook prototypes */
void vApplicationTickHook(void);

/* USER CODE BEGIN 3 */
void vApplicationTickHook(void)
{
  /* This function will be called by each tick interrupt if
  configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h. User code can be
  added here, but the tick hook is called from an interrupt context, so
  code must not attempt to block, and only the interrupt safe FreeRTOS API
  functions can be used (those that end in FromISR()). */
  lv_tick_inc(1);
}
/* USER CODE END 3 */

/**
 * @brief  FreeRTOS initialization
 * @param  None
 * @retval None
 */
void MX_FREERTOS_Init(void)
{
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* creation of heartrt */
  heartrtHandle = osMessageQueueNew(1, sizeof(uint8_t), &heartrt_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of heartrate */
  heartrateHandle = osThreadNew(hearttask, NULL, &heartrate_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */
}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
 * @brief  Function implementing the defaultTask thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for (;;)
  {

    lv_timer_handler();
    osDelay(5);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_hearttask */
/**
 * @brief Function implementing the heartrate thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_hearttask */
void hearttask(void *argument)
{
  /* USER CODE BEGIN hearttask */
  FilterState filter;
  Filter_Init(&filter);

  TickType_t xLastWakeTime;
  // 初始化上一次唤醒时间
  xLastWakeTime = xTaskGetTickCount();
  uint8_t i = 0;
  float buf[BUF_SIZE];
  float heartrate = 0;
  uint8_t hearttt;
  // 10ms 周期（10个节拍，当 configTICK_RATE_HZ = 1000 时）
  const TickType_t x10msPeriod = 10;
  /* Infinite loop */
  for (;;)
  {
    float ir = (float)max_ir(); // 你的采样函数
    float out = Filter_Process(&filter, ir);
    // printf("%f\n", out);
    buf[i] = out;
    i++;
    uint8_t peak1 = 0, peak2 = 0;
    vTaskDelayUntil(&xLastWakeTime, x10msPeriod);
    if (i == BUF_SIZE)
    {
      for (uint8_t j = 2; j < BUF_SIZE - 2; j++)
      {
        if (buf[j] < buf[j - 1] && buf[j] < buf[j - 2] &&
            buf[j] < buf[j + 1] && buf[j] < buf[j + 2])
        {
          if (peak1 == 0)
          {
            peak1 = j;
            // printf("波谷在位置 %d，值为 %f\n", peak1, buf[j]); /* code */
          }
          else
          {
            peak2 = j;
            if (abs(peak1 - peak2) <= 75)
            {
              peak2 = 0;
            }
            else
            {
              peak2 = j;
              heartrate = 60 / (((float)peak2 - (float)peak1) / 100);
              hearttt = (uint8_t)heartrate;
              // printf("%d\n", heartrate);
              // printf("波谷在位置 %d，值为 %f\n", peak2, buf[j]); /* code */
               printf("%d\n", (uint8_t)heartrate);
              // lv_label_set_text_fmt(ui->Heart_label_1, "%d", (uint8_t)heartrate);
              xQueueOverwrite(
                  heartrtHandle,
                  &hearttt);
              break;
            }
          }
        }
      }
      i = 0;
    }
  }
  /* USER CODE END hearttask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
