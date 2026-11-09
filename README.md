# Water Treatment & Turbidity Detection System

## Project Overview

This project involved the development of an automated water turbidity detection and renewal system using an Arduino Uno R3.

The system monitors water clarity through an analog turbidity sensor, detects the water level in a container and controls a water pump to simulate an automatic filtration or water renewal process.

A 16x2 I2C LCD displays the sensor readings and an estimated turbidity percentage, providing real-time information to the user.

## Project Objectives

- Monitor water turbidity using an analog sensor.
- Classify water quality according to predefined sensor thresholds.
- Monitor the water level to prevent the container from overflowing.
- Control a water pump automatically according to water quality and tank level.
- Display sensor readings and estimated turbidity on an LCD.

## Hardware Components

| Component | Function |
|---|---|
| Arduino Uno R3 | Main microcontroller |
| Analog Turbidity Sensor | Measures water turbidity |
| Water Level Sensor | Detects the water level |
| 16x2 I2C LCD | Displays system information |
| 5V Relay Module | Controls the pump circuit |
| Submersible Water Pump | Moves water between containers |
| External Power Supply | Powers the water pump |

## System Operation

The Arduino continuously reads the analog output of the turbidity sensor connected to pin A0.

Based on predefined thresholds, the water is classified into three conditions:

- **Clean:** sensor reading above 700.
- **Slightly Dirty:** sensor reading between 601 and 700.
- **Very Dirty:** sensor reading below 600.

When the water is classified as very dirty, the system checks the water level sensor. If the level condition allows it, the relay is activated, powering the water pump.

The LCD displays the sensor reading and an estimated turbidity percentage, while the Serial Monitor provides additional information about the water condition.

## Software Implementation

The system was programmed using Arduino C/C++.

The software implementation includes:

- Analog sensor reading and data acquisition.
- Threshold-based water quality classification.
- Digital water level monitoring.
- Conditional control logic for the relay and pump.
- I2C communication with the LCD.
- Serial communication for monitoring sensor readings.

## My Contribution

I took primary responsibility for the technical development and implementation of the project, covering the main hardware and software activities.

My contributions included:

- Developing the Arduino program and system control logic.
- Integrating the turbidity and water level sensors.
- Implementing the automatic pump control using a relay module.
- Integrating and programming the LCD interface.
- Assembling and testing the electronic circuit.
- Identifying hardware limitations and troubleshooting integration issues.

## Challenges and Solutions

**Insufficient Arduino output current for the water pump**

The pump required approximately 0.5–0.7 A, which exceeded the current available from an Arduino output pin. An external power supply and a relay module were therefore used to control the pump safely.

**Water level detection**

An external resistor configuration was implemented to establish the required HIGH and LOW input states, allowing the system to monitor the water level and control pump activation.

## Technologies and Tools

- Arduino Uno R3
- Arduino C/C++
- Analog and digital sensors
- Relay-based actuator control
- I2C communication
- LCD interfacing
- Electronic circuit assembly and testing

## Project Information

- **Course:** Microcontrollers and Interaction with Sensors and Actuators
- **Course Code:** 41994
- **Institution:** University of Aveiro
- **Academic Year:** 2023/2024
- **Instructor:** Rui Escadas Martins
- **Date:** April 2024

## Authors

- **Adriana Pires** — Electrical and Computer Engineering
- Rodrigo Fernandes — Electrical and Computer Engineering
- Carlos Afonso — Biomedical Engineering
- André Gonçalves — Computer Science and Engineering
- José Abreu — Industrial Engineering and Management
- Rúben Marques — Mechanical Engineering

---

*University of Aveiro — Portugal*
