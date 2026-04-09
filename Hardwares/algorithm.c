#include "algorithm.h"

// 初始化滤波器状态
void Filter_Init(FilterState *st)
{
    st->hp_last_x = 0.0f;
    st->hp_last_y = 0.0f;
    st->lp_last_y = 0.0f;
    st->smooth_last = 0.0f;
}

// 主处理函数，每次来一个采样点调用一次
float Filter_Process(FilterState *st, float x)
{
    // -------------------
    // Step 1: 高通滤波 (去直流，fc=0.5Hz)
    float alpha_hp = 0.969f; // 预先算好的系数，fs=100Hz
    float y_hp = alpha_hp * (st->hp_last_y + x - st->hp_last_x);
    st->hp_last_x = x;
    st->hp_last_y = y_hp;

    // -------------------
    // Step 2: 低通滤波 (fc=5Hz)
    float beta_lp = 0.76f; // fs=100Hz
    float y_lp = (1.0f - beta_lp) * y_hp + beta_lp * st->lp_last_y;
    st->lp_last_y = y_lp;

    // -------------------
    // Step 3: 平滑 (指数平滑)
    float gamma = 0.2f; // 越小越平滑，越大越跟随
    float y_smooth = gamma * y_lp + (1.0f - gamma) * st->smooth_last;
    st->smooth_last = y_smooth;

    return y_smooth;
}
