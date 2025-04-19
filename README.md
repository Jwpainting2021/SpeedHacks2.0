# 🌱 AutoSeedBot: Autonomous Eco-Friendly Seed Planting Robot  
### Created by Team MEtecha | SpeedHacks 2.0 @ George Mason University  

## 🚀 Overview  
AutoSeedBot is a battery-powered, 2WD autonomous robot car designed to assist with **reforestation efforts** by autonomously planting seeds in areas exposed to sunlight. Built for the theme *"Tech for Environmental Good"*, the project aims to reduce deforestation by supporting seed dispersal in deforested regions using low-cost, accessible robotics.

## 🌍 Purpose & Impact  
Our goal was to create an autonomous solution that identifies viable planting spots and dispenses seeds without human intervention. By planting seeds in open, sunlit areas, AutoSeedBot contributes to ecosystem restoration and supports natural reforestation.

## 🛠️ Key Features  
- **Autonomous Navigation**  
  Equipped with an **ultrasonic sensor** at the front, the robot detects obstacles and adjusts its path to avoid collisions while navigating through forested areas.

- **Seed Planting Mechanism**  
  A custom-built **seed dispenser** at the rear of the car releases a seed when ideal conditions are met.

- **Photoresistor-Based Sunlight Detection**  
  The onboard **photoresistor (light sensor)** detects sunlight intensity. If sunlight is sufficient (indicating an open space ideal for planting), the robot activates the seed dispenser to plant a seed.

- **Battery Powered Mobility**  
  The robot runs on a battery pack powering **two DC motors**, allowing efficient and eco-friendly movement.

- **Shovel Mount**  
  A flat shovel is installed at the back to assist in lightly disturbing the soil before planting, increasing the chances of seed germination.

## 🔧 Tech Stack  
- **Microcontroller**: Arduino UNO  
- **Sensors**:  
  - Photoresistor (Light Sensor)  
  - Ultrasonic Distance Sensor  
- **Actuators**:  
  - 2 x DC Motors (for movement)  
  - Servo Motor (for seed dispensing mechanism)  
- **Power Source**: Battery Pack  
- **Chassis**: 2WD Robot Car Frame  

## 📸 How It Works  
1. The robot begins navigating a predefined area.  
2. As it moves, the **ultrasonic sensor** scans for obstacles. Upon detection, it turns to avoid them.  
3. Meanwhile, the **photoresistor** constantly monitors light levels.  
4. When **sufficient sunlight** is detected (indicating an ideal planting spot), the **seed dispenser** activates to drop a seed into the soil.  
5. The process continues autonomously, creating an efficient, environment-friendly planting system.

## 🤖 Future Improvements  
- Add GPS support for location-based tracking of planted seeds.  
- Incorporate soil moisture sensors for better planting decisions.  
- Enable remote monitoring via IoT integration.  

## 👨‍💻 Team MEtecha  
A passionate team of innovators from George Mason University, driven to build tech for social and environmental good.
