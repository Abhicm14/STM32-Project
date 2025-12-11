# Wi-Fi-Scanning-and-Connection-System-Using-ESP32-and-STM32

![Project Banner](images/banner.jpg)
[![Demo Video](https://img.youtube.com/vi/YOUR_VIDEO_ID/0.jpg)](https://www.youtube.com/watch?v=YOUR_VIDEO_ID)

A complete embedded system that allows users to **scan nearby Wi-Fi networks** and **connect to the desired one** using only three buttons and an OLED display.

Developed during my **Embedded Systems Internship at Loginware Softwares**.

## Demo (Must Watch!)

https://github.com/user-attachments/assets/your-video-id-or-gif-here  
*(Replace the above line with your actual demo GIF or video)*

![Demo GIF](images/demo.gif)

## Features

- Real-time Wi-Fi scanning using ESP32  
- Beautiful scrolling menu on 0.96" OLED display  
- Smooth navigation with **Up ↓**, **Down ↑**, and **Select ✔** buttons  
- Bidirectional UART communication between STM32 and ESP32  
- Auto-connect to selected network  
- Clean, responsive, and non-blocking UI  

## Hardware Used

| Component              | Model                          | Interface |
|------------------------|-------------------------------|-----------|
| Main MCU               | STM32F103C8T6 (Blue Pill)     | -         |
| Wi-Fi Module           | ESP32 DevKitC / NodeMCU       | UART      |
| Display                | 0.96" I2C OLED SSD1306        | I2C       |
| Buttons                | 3× Tactile Push Buttons       | GPIO      |

### Circuit Connection Diagram
![Circuit Diagram](images/circuit.jpg)

### Actual Hardware Photos
| Front View                  | Side View                     |
|-----------------------------|-------------------------------|
| ![Front](images/front.jpg)  | ![Side](images/side.jpg)      |

## Pin Connections

```plaintext
STM32F103                ESP32
PA9  (USART1_TX)    →    GPIO3 (RX)
PA10 (USART1_RX)    →    GPIO1 (TX)
GND                 →    GND

STM32                    OLED (SSD1306)
PB6 (I2C1_SCL)      →    SCL
PB7 (I2C1_SDA)      →    SDA
3.3V                →    VCC
GND                 →    GND

Buttons (Active Low with internal pull-up):
PC13 → Select Button
PA0  → Up Button
PA1  → Down Button
