#include <DHT11.h>

#include <Servo.h>
#include <Wire.h>  // Include the Wire library for I2C communication (for LCD)
#include <LiquidCrystal_I2C.h>  // Include the LCD I2C library

// Initialize the LCD with the address 0x27 (you might need to adjust this based on your LCD module)
LiquidCrystal_I2C lcd(0x27, 16, 2);  // 16x2 LCD

// Define pins for sensors and actuators
const int irSensorPin = 2;      // IR sensor pin
const int temperaturePin = A0;  // Temperature sensor pin (analog input)
const int triggerPin = 6;       // Ultrasonic sensor trigger pin
const int echoPin = 7;          // Ultrasonic sensor echo pin
const int servoPin = 12;         // Servo motor pin

// Initialize variables for sensor readings          // IR sensor value (0 or 1)
float temperature = 0.0;        // Temperature value
long duration;                  // Duration of sound wave travel (ultrasonic sensor)
int distance;                   // Distance measured by ultrasonic sensor
 int temp_adc_val;
int IR_sensor;
// Initialize the servo motor object
Servo myServo;

void setup() {
  // Start serial communication
  Serial.begin(9600);

  // Initialize LCD

  
  lcd.init();
  lcd.backlight();

  // Attach servo to the servo pin
  myServo.attach(servoPin);

  // Set pin modes
  pinMode(irSensorPin, INPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Print initial message to LCD
  lcd.setCursor(0, 0);
  lcd.print("Health Monitoring");
  lcd.setCursor(0, 1);
  lcd.print("System");

  // Delay for initialization
  delay(2000);
}

void loop() {

  // Read temperature sensor
  temperature = readTemperature();

  // Read distance from ultrasonic sensor
  distance = readDistance();

  // Display data on LCD
  displayData();

  // Check conditions and control servo motor based on sensor values
  servoIR();
  // Delay before next loop iteration
  delay(500);
}

float readTemperature() {
  // Read analog value from temperature sensor
 temp_adc_val = analogRead(temperaturePin);

  // Convert analog value to temperature in degrees Celsius
   temperature = (temp_adc_val * 4.88); /* Convert adc value to equivalent voltage */
  temperature = (temperature/10); /* LM35 gives output of 10mv/°C */
  Serial.print("Temperature = ");
   Serial.print(temperature);
  Serial.print(" Degree Celsius\n");
  return temperature;
}

int readDistance() {
  // Send ultrasonic pulse
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Measure the duration of the echo pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters
  int distance = duration * 0.034 / 2;

  return distance;
}

void displayData() {
  // Clear LCD
  lcd.clear();

  // Display temperature
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  // Display distance
  lcd.setCursor(0, 1);
  lcd.print("Dist: ");
  lcd.print(distance);
  lcd.print(" cm");
}




void servoIR() {
  int irSensorValue = digitalRead(irSensorPin);  // Read IR sensor state

  Serial.print("IR Sensor Value: ");
  Serial.println(irSensorValue);

  if (irSensorValue == HIGH) {
    Serial.println("Object detected!");
    myServo.write(90);  // Rotate servo motor to 90 degrees position
    delay(500);  // Delay for stability
  } else {
    Serial.println("No object detected.");
    myServo.write(0);  // Rotate servo motor to 0 degrees position
    delay(500);  // Delay for stability
  }
}
