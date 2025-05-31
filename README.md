# 🌱 ESP32 Soil Moisture Monitoring System

An academic prototype for greenhouse automation using the **DFRobot Analog Waterproof Soil Moisture Sensor**, **ESP32**, and **Raspberry Pi**.

This project demonstrates how to monitor soil moisture levels and automate irrigation using low-power wireless communication with **Bluetooth Low Energy (BLE)**. Designed for use in smart agriculture, this system can be extended for research in embedded systems, IoT, and environmental sensing.

---

## 📖 Project Overview

The system continuously measures soil moisture percentage using the DFRobot sensor connected to an ESP32 microcontroller. Moisture data is sent via BLE to a **Raspberry Pi**, which evaluates the data and either:

- **Automatically triggers a relay** to activate a water pump when moisture drops below a set threshold, or
- **Allows manual watering** via a user interface (UI) hosted on the Raspberry Pi.

---

## 🧩 System Architecture

```
┌──────────────┐     BLE      ┌───────────────┐      GPIO       ┌──────────────┐
│  ESP32 Dev   │ ───────────► │  Raspberry Pi │ ──────────────► │ Relay Module │
│ Moisture     │              │ + UI Display  │                 │ Valve Control│
│ Sensor Input │              │               │                 └──────────────┘
└──────────────┘              └───────────────┘
```

## 📱 ESP32 wiring with DFRobot Sensor

DFRobot sensor comes with 4 wires (2 Black, Red and Yellow) in order to connect it I have used following PINs.

1 black --- right side of the ESP32 GND pin
2 black --- left side of the ESP32 GND pin
1 red --- left side of ESP32 3v3 pin
1 yellow --- left side of ESP32 G34 pin
