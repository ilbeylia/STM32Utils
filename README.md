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

### BASIC_GPIO_lib
```C
/* USER CODE BEGIN Includes */
    #include "BASIC_GPIO_lib.h"
/* USER CODE END Includes */

/* USER CODE BEGIN PV */
    Status_led_s statusLED;
/* USER CODE END PV */

/* USER CODE BEGIN Init */
  status_led_init(&statusLED, GPIOD, GPIO_PIN_12, GPIOD, GPIO_PIN_13, GPIOD, GPIO_PIN_14, GPIOD, GPIO_PIN_15);
/* USER CODE END Init */

while (1)
{
    status_led_process(&statusLED, LED_Mode4);
}
```



| **Mod**       | **Process**                   |
|---------------|-------------------------------|
| `LED_Mode1`   | LED1 ON                       |
| `LED_Mode2`   | LED1, LED2 ON                 |
| `LED_Mode3`   | LED1, LED2, LED3 ON           |
| `LED_Mode4`   | LED1, LED2, LED3, LED4 ON     |

### ADC_lib
```C
/* USER CODE BEGIN Includes */
    #include "ADC_lib.h"
/* USER CODE END Includes */

/* USER CODE BEGIN PV */
    uint32_t data=0;
/* USER CODE END PV */

while (1)
{
    data = ADC_read(&hadc1);
}
```
**ADC_lib** library will be expanded to include methods for utilizing ADC with **DMA** and **interrupt-based** ADC handling.


### STEP_MOTOR_lib
```C
/* USER CODE BEGIN Includes */
    #include "STEP_MOTOR_lib.h"
/* USER CODE END Includes */

/* USER CODE BEGIN PV */
    step_config step1;
/* USER CODE END PV */

/* USER CODE BEGIN 0 */
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef * htim)
{
	if (htim-> Instance == TIM1){

		if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
		{
			step1.step_set.sayac++;
		}
		step_durdur(&step1);
    }
}

/* USER CODE END 0 */

/* USER CODE BEGIN Init */
    step_init(&step1, &htim1, TIM_CHANNEL_1, dir_GPIO_Port, dir_Pin);
/* USER CODE END Init */

while (1)
{
    step(&step1, 200, Step_ILERI);
	HAL_Delay(1000);
	step(&step1, 200, Step_GERI);
	HAL_Delay(1000);
}
```

### FLASH_PROCESS_lib
```C
/* USER CODE BEGIN Includes */
    #include "FLASH_PROCESS_lib.h"
/* USER CODE END Includes */

/* USER CODE BEGIN PV */
    Status_led_s statusLED;

    uint32_t flash_rd;
    int test=0;
/* USER CODE END PV */

/* USER CODE BEGIN Init */
  status_led_init(&statusLED, GPIOD, GPIO_PIN_12, GPIOD, GPIO_PIN_13, GPIOD, GPIO_PIN_14, GPIOD, GPIO_PIN_15);

  /* USER CODE END Init */

/* USER CODE BEGIN 2 */
  
  flash_rd = Flash_RD(0x080E0000);

  if (flash_rd<=10){
	  flash_rd +=1;
//	  Flash_Erase(0x0080E0000, 4);
	  test=1;
	  Flash_WR(0x080E0000, flash_rd);
  }
  else {
	  Flash_WR(0x080E0000, 0x00);
  }

  /* USER CODE END 2 */

while (1)
{
    if(flash_rd < 5){
    status_led_process(&statusLED, LED_Mode1);   	
    }
}
```


