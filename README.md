# OMOWatch

OMOWatch 是一个基于 `STM32F407`、`FreeRTOS` 和 `LVGL` 的嵌入式智能手表项目。

## 项目简介

本仓库包含以下内容：

- 由 STM32CubeMX 生成的单片机初始化代码
- 基于 FreeRTOS 的应用任务
- LVGL 图形界面页面及自动生成的界面资源
- 显示、触摸、心率和运动传感器等硬件驱动
- Keil MDK 与 EIDE 工程文件

## 硬件模块

- 主控：`STM32F407`
- 显示屏：`ST7789`
- 触摸芯片：`CST816T`
- 心率传感器：`MAX30102`
- 运动 / 计步传感器：`LSM6DS3`

## 界面页面

- `Home`
- `Step`
- `Heart`
- `Bluetooth`
- `NFC`
- `Battery`
- `Setting`

## 目录结构

- `Core/`：STM32Cube 生成的核心启动与外设初始化代码
- `Drivers/`：CMSIS 与 STM32 HAL 驱动
- `Hardwares/`：板级硬件驱动
- `Middlewares/`：FreeRTOS 及相关中间件
- `lvgl/`：LVGL 图形库源码
- `src/`：LVGL 应用入口、自定义逻辑与自动生成的界面代码
- `MDK-ARM/`：Keil 工程文件
- `EIDE/`：EIDE 工程与工作区文件
- `patches/`：LVGL / Zephyr 相关补丁

## 构建说明

当前仓库同时包含两类工程入口：

- `src/main.c` 中的 Zephyr + LVGL 应用入口
- `Core/`、`Drivers/`、`Middlewares/` 与 `MDK-ARM/` 下的 STM32Cube + FreeRTOS 固件工程

请根据你的实际开发流程，选择对应的工具链与工程配置进行编译。

## 说明

该 README 已更新为中文版本，便于直接在 GitHub 仓库首页查看。
