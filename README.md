# STM32Utils
---
**STM32Utils** is an open-source library designed to streamline the development process for STM32 microcontrollers. This library provides reusable drivers, utilities, and helper functions for a wide range of peripherals, making it easier to integrate and use hardware features. Whether you're working on GPIO, UART, I2C, ADC, or advanced features like timers and PWM, STM32Utils is here to simplify your development.
---
**Table of Content**
---
[Features](#features)  
- [Peripheral Drivers](#peripheral-drivers)  
- [Advanced Features](#advanced-features)  

[Planned Additions](#planned-additions)  
[Getting Started](#getting-started)  

- [Requirements](#requirements)  
- [Installation](#installation)
- [Usage Examples](#usage-examples)
---
## Features
### Peripheral Drivers:
Simplified and reusable drivers for common peripherals, including:

**GPIO**: Easy configuration and control for input/output pins.
**UART**: Serial communication with minimal setup.
**I2C**: Master and slave communication.
**SPI**: Simplified data transmission for high-speed devices.
**ADC**: Analog-to-digital conversion for sensor data acquisition.
**EXTI**: External interrupt handling for real-time responses.

### Advanced Features:
Drivers and utilities for more complex STM32 features:
**Timers**: Time-based operations and event triggering.
**PWM**: Pulse-width modulation for motor control and LEDs.
**RTC**: Real-time clock for timekeeping applications.
**DMA**: High-speed data transfer without CPU intervention.

### Utility Functions:
Helper functions for debugging, error handling, and peripheral configuration.

### Modular and Expandable:
Add or remove modules as needed for your project.

### Broad Compatibility:
Supports multiple STM32 families (e.g., F0, F1, F3, F4, G0, L0, H7).

### Open Source:
Fully customizable and open for contributions from the community.

---

## Planned Additions
This library will continue to grow to include:

- [ ]  **CAN**: Communication for automotive and industrial applications.
- [ ]  **USB**: USB device and host functionality.
- [ ]  **Ethernet**: Networking capabilities for IoT and connected devices.
- [ ]  **SD/MMC**: Storage support for SD cards and multimedia cards.
- [ ]  **FreeRTOS Integration**: Task management for real-time systems.
- [ ]  **LCD/OLED Support**: Display control for graphical interfaces.
- [ ]  **Sensor Libraries**: Accelerometer, gyroscope, and temperature sensor drivers.

---

## Getting Started
## Requirements
**STM32CubeMX** for code generation and initialization.
**STM32 HAL or LL drivers** (pre-installed with STM32CubeIDE).
**ARM GCC compiler** or compatible toolchain.
STM32 development board (e.g., Nucleo, Discovery, or custom boards).

## Installation
1. Clone the repository:
```bash
git clone https://github.com/ilbeylia/STM32Utils.git
```

## Usage Examples
 ...