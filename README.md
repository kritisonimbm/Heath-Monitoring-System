# Health Monitoring System using Arduino

This project is a basic **Health Monitoring System** developed using **Arduino**, which integrates multiple sensors to measure temperature, detect objects, measure distance, and control a servo motor. The system displays real-time data on a 16×2 I2C LCD.

---

## 🔧 Components Used
- Arduino UNO
- LM35 Temperature Sensor
- IR Sensor
- Ultrasonic Sensor (HC-SR04)
- Servo Motor
- 16×2 LCD with I2C Module
- Jumper Wires
- Breadboard

---

## ⚙️ System Description

- The **temperature sensor (LM35)** measures ambient/body temperature and displays it on the LCD.
- The **ultrasonic sensor** calculates distance using echo pulse timing.
- The **IR sensor** detects the presence of an object.
- Based on IR sensor detection, the **servo motor rotates** to a predefined angle.
- All sensor values are continuously displayed on the **LCD screen**.
- Serial Monitor is used for debugging and monitoring sensor values.

---

## 🧠 Working Principle

1. Arduino reads analog data from the LM35 sensor and converts it to temperature in °C.
2. Ultrasonic sensor measures distance using time-of-flight calculation.
3. IR sensor provides digital input for object detection.
4. If an object is detected, the servo rotates to 90°; otherwise, it remains at 0°.
5. Temperature and distance values are updated on the LCD in real time.

---

## 📌 Pin Configuration

| Component | Arduino Pin |
|---------|------------|
| IR Sensor | D2 |
| Ultrasonic Trigger | D6 |
| Ultrasonic Echo | D7 |
| Temperature Sensor | A0 |
| Servo Motor | D12 |
| LCD (I2C) | SDA, SCL |

---

## 🛠️ Software Used
- Arduino IDE
- Embedded C / Arduino Programming

---

## 🚀 Applications
- Basic health monitoring systems
- Contactless sensing applications
- Embedded systems learning projects
- Sensor interfacing demonstrations

---

## 🔮 Future Improvements
- Integration of pulse or SpO₂ sensor
- Wireless data transmission (Bluetooth / Wi-Fi)
- Data logging and visualization
- Mobile app integration

---

## 👩‍💻 Author
**Kriti Soni**  
B.E. Electronics & Communication Engineering  
MBM University, Jodhpur  

🔗 GitHub: https://github.com/kritisonimbm
