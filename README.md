# OMOWatch

OMOWatch is an embedded smartwatch project based on STM32F407, FreeRTOS, and LVGL.

## Overview

This repository contains:

- STM32CubeMX-generated MCU initialization code
- FreeRTOS-based application tasks
- LVGL UI screens and generated GUI assets
- Hardware drivers for the display, touch, heart-rate, and motion sensors
- Keil MDK and EIDE project files

## Hardware-Related Modules

- MCU: STM32F407
- Display: ST7789
- Touch controller: CST816T
- Heart-rate sensor: MAX30102
- Motion sensor / step counting: LSM6DS3

## UI Pages

- Home
- Step
- Heart
- Bluetooth
- NFC
- Battery
- Setting

## Project Structure

- `Core/`: STM32Cube-generated core startup and peripheral code
- `Drivers/`: CMSIS and STM32 HAL drivers
- `Hardwares/`: board-level peripheral drivers
- `Middlewares/`: FreeRTOS and related middleware
- `lvgl/`: LVGL library source
- `src/`: LVGL application entry, custom code, and generated UI files
- `MDK-ARM/`: Keil project files
- `EIDE/`: Embedded IDE workspace files
- `patches/`: LVGL / Zephyr related patch files

## Build Notes

This repository currently includes both:

- a Zephyr/LVGL application entry in `src/main.c`
- an STM32Cube/FreeRTOS firmware project under `Core/`, `Drivers/`, `Middlewares/`, and `MDK-ARM/`

Use the toolchain and project configuration that matches your target workflow.

## Status

This README was added during the initial repository import to GitHub.
