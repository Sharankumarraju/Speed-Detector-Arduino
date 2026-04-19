# 🚗 IR Sensor Based Speed Detector using Arduino

## 📌 Project Overview
This project presents a **Speed Detection System** using Arduino and IR sensors. The system measures the speed of a moving vehicle or object by calculating the time taken to travel between two sensors placed at a fixed distance.

The calculated speed is displayed on an LCD screen, and a buzzer alert is triggered when the speed exceeds a predefined limit. This project demonstrates the practical application of embedded systems, sensor interfacing, and real-time data processing.

---

## ⚙️ Components Used
- Arduino UNO  
- IR Sensors (2)  
- 16×2 LCD Display with I2C Module  
- Buzzer  
- Breadboard  
- Jumper Wires  
- Power Supply (USB / Power Bank)  

---

## 🔧 Working Principle
- Two IR sensors are placed at a fixed distance (**assumed to be 1 meter in the code but placed at a distance of 10cm on breadboard because the sensors can't be practically placed 1 meter apart on breadboard**).
- When a vehicle passes the first sensor, the timer starts.
- When it reaches the second sensor, the timer stops.
- Speed is calculated using the distance–time relationship:

**Speed = Distance / Time**

- The result is converted into **km/h**.
- The speed is displayed on the LCD.
- If the speed exceeds **50 km/h**, the buzzer is activated for 5 seconds.
- If only one sensor is triggered, the system displays **"No Vehicle Detected"**.

---

## 🧠 Features
- Contactless speed detection  
- Real-time speed display  
- Overspeed alert system  
- Handles incomplete detection cases  
- Simple and low-cost design  

---

## 📷 Project Preview

### 🔧 Hardware Setup
![Setup](images/setup.jpg)

### 🚗 Speed Detection Output
![Speed Output](images/speed.jpg)

### ⚠️ Over Speed Detection
![Over Speed](images/over_speeding.jpg)

### 🚫 No Vehicle Detected
![No Vehicle](images/no_vehicle.jpg)

---

## 🔌 Connections

### 📟 LCD (I2C)
- VCC → 5V  
- GND → GND  
- SDA → A4  
- SCL → A5  

### 🔴 IR Sensors
- Sensor 1 OUT → A0  
- Sensor 2 OUT → A1  
- VCC → 5V  
- GND → GND  

### 🔔 Buzzer
- Positive → Pin 13  
- Negative → GND  

---

## 💻 Code
The Arduino code for this project is available in this repository.

---

## 📊 Output
- Displays speed in km/h  
- Shows "No Vehicle Detected" if only one sensor is triggered  
- Activates buzzer when speed exceeds the set limit  

---

## 🚀 Applications
- Traffic monitoring systems  
- Speed control systems  
- Industrial automation  
- Smart surveillance systems  

---

## 📂 Files Included
- Arduino Code (.ino)  
- Project Report (PDF)  
- Presentation (PPT/PDF)  
- Project Images  

---

## 👨‍💻 Author
Addepalli Sharan Kumar Raju

---

## ⭐ Conclusion
This project successfully demonstrates a simple and effective method for speed detection using Arduino and IR sensors. It highlights how basic electronic components can be integrated to build a real-time monitoring system with practical applications.
