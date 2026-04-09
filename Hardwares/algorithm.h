#ifndef __ALGORITHM_H
#define __ALGORITHM_H

#include <stdint.h>
#include <stdbool.h>
#include "cmsis_os.h"

typedef struct
{
    float hp_last_x;   // 高通：上一个输入
    float hp_last_y;   // 高通：上一个输出
    float lp_last_y;   // 低通：上一个输出
    float smooth_last; // 平滑：上一个输出
} FilterState;


#define MAX_HISTORY 5
#define BUF_SIZE 150


void Filter_Init(FilterState *st);

// 主处理函数，每次来一个采样点调用一次
float Filter_Process(FilterState *st, float x);

#endif // !__ALGORITHM_H
