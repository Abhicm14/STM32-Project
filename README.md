# Wi-Fi-Scanning-and-Connection-System-Using-ESP32-and-STM32

![ESP32-STM32 Wi-Fi Network Selector Banner](https://files.catbox.moe/3m0p8k.jpg)
![Project Video](images/Workflow_of_Project.mp4)

A complete embedded system that allows users to **scan nearby Wi-Fi networks** and **connect to the desired one** using only three buttons and an OLED display.

Developed during my **Embedded Systems Internship at Loginware Softwares**.

## Features

- Real-time Wi-Fi scanning using ESP32  
- Beautiful scrolling menu on 0.96" OLED display  
- Smooth navigation with **Up ↓**, **Down ↑**, and **Select ✔** buttons  
- Bidirectional UART communication between STM32 and ESP32  
- Auto-connect to selected network  
- Clean, responsive, and non-blocking UI  

## Hardware Used

| Component              | Model                         | Interface |
|------------------------|-------------------------------|-----------|
| Main MCU               | STM32F407VGT6 (Blue Pill)     | -         |
| Wi-Fi Module           | ESP32 DevKitC / NodeMCU       | UART      |
| Display                | 0.96" I2C OLED SSD1306        | I2C       |
| Buttons                | 3× Tactile Push Buttons       | GPIO      |

### Circuit Connection Diagram
![Circuit Diagram](images/Project_Image.jpg)

| ![OLED](images/OLED_Display.jpg)  | ![ESP](images/ESP_Serial_Monitor_Image.png)      |

## Pin Connections

```plaintext
STM32F103                ESP32
PA2  (USART1_TX)    →    GPIO3 (RX)
PA3 (USART1_RX)     →    GPIO1 (TX)
GND                 →    GND

STM32                    OLED (SSD1306)
PB10 (I2C1_SCL)     →    SCL
PB11 (I2C1_SDA)     →    SDA
3.3V                →    VCC
GND                 →    GND

Buttons (Active Low with internal pull-up):
PA10 → Select Button
PA8  → Up Button
PA9  → Down Button
