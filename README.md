# 🏥 Health Monitoring System Using Arduino

## Objective
To design and implement a **Health Monitoring System** using an **Arduino microcontroller** that can **measure temperature, detect nearby objects, and monitor distance**.  
The system also **controls a servo motor** based on IR sensor input and displays real-time data on a **16x2 LCD with I2C interface**.

---

## Components Used
- Arduino UNO  
- Temperature Sensor (LM35 / DHT11)  
- IR Sensor  
- Ultrasonic Sensor (HC-SR04)  
- Servo Motor  
- 16x2 LCD with I2C Module  
- Jumper Wires & Breadboard  

---

## Pin Configuration

| Component                  | Arduino Pin       |
|-----------------------------|-----------------|
| IR Sensor                  | D2               |
| Temperature Sensor (A0)    | A0               |
| Ultrasonic Trigger          | D6               |
| Ultrasonic Echo             | D7               |
| Servo Motor                 | D12              |
| LCD (SDA)                  | A4               |
| LCD (SCL)                  | A5               |

---

## Working Principle
1. **Temperature Measurement**  
   - Analog voltage from the temperature sensor is read and converted to °C.  
   - Temperature is displayed on the LCD and serial monitor.

2. **Distance Measurement**  
   - Ultrasonic sensor emits pulses and measures the echo time.  
   - Distance is calculated using the speed of sound and displayed in centimeters.

3. **Object Detection & Servo Control**  
   - IR sensor detects objects nearby.  
   - Servo rotates to **90°** when an object is detected; otherwise remains at **0°**.

4. **Display Output**  
   - LCD shows **Temp: XX C** and **Dist: XX cm** in real-time.

---

## How to Operate
1. Assemble the circuit and connect all sensors, servo, and LCD.  
2. Upload the Arduino code to the board.  
3. Open the Serial Monitor at **9600 baud** to see sensor readings.  
4. Observe real-time temperature and distance on the LCD.  
5. Place an object in front of the IR sensor to see the servo respond.

---

## Learning Outcomes
- Interfacing multiple sensors with Arduino  
- Controlling a servo motor based on sensor inputs  
- Using I2C protocol for LCD communication  
- Real-time monitoring and decision-making in embedded systems  
- Basics of smart health and safety automation  

---

## Limitations
- Only basic temperature, distance, and IR detection implemented  
- No wireless communication  
- No advanced health metrics like heart rate or SpO₂  

---

## Future Enhancements
- Add heart rate or SpO₂ sensors for full health monitoring  
- Send sensor data to a mobile app or cloud via Bluetooth/Wi-Fi  
- Trigger alarms or notifications for unsafe conditions  
- Implement data logging and predictive analytics  

---

## System Flow
1. Sensors measure environmental and object-related data.  
2. Arduino reads and processes sensor values.  
3. LCD displays real-time data.  
4. IR detection triggers servo motor response.  
5. Serial Monitor logs data for debugging and monitoring.  

---

## Author
**Kriti Soni**  
B.E. Electronics & Communication Engineering  
MBM University, Jodhpur
