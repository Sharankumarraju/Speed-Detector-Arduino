#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int sensor1 = A0;
const int sensor2 = A1;
const int buzzer  = 13;

unsigned long startTime = 0;
float distance = 1.0;   // meters between sensors

int firstSensor = 0;     // 0 = none, 1 = sensor1, 2 = sensor2

void setup() {
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(buzzer, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Speed Detector");
  delay(2000);
  lcd.clear();
}

void loop() {

  // Detect first sensor
  if (firstSensor == 0) {
    if (digitalRead(sensor1) == LOW) {
      startTime = millis();
      firstSensor = 1;
    }
    else if (digitalRead(sensor2) == LOW) {
      startTime = millis();
      firstSensor = 2;
    }
  }

  // If first was sensor1, wait for sensor2
  else if (firstSensor == 1) {

    if (digitalRead(sensor2) == LOW) {
      calculateSpeed();
    }

    // Timeout 3 seconds
    else if (millis() - startTime > 3000) {
      showNoVehicle();
    }
  }

  // If first was sensor2, wait for sensor1
  else if (firstSensor == 2) {

    if (digitalRead(sensor1) == LOW) {
      calculateSpeed();
    }

    // Timeout 3 seconds
    else if (millis() - startTime > 3000) {
      showNoVehicle();
    }
  }
}

void calculateSpeed() {

  unsigned long endTime = millis();
  unsigned long timeTaken = endTime - startTime;

  if (timeTaken > 0) {

    float speed = distance / (timeTaken / 1000.0);
    float speedKmph = speed * 3.6;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Speed:");
    lcd.setCursor(0, 1);
    lcd.print(speedKmph);
    lcd.print(" km/h");

    if (speedKmph > 50) {
      digitalWrite(buzzer, HIGH);
      delay(5000);   // Buzzer ON for 5 sec
      digitalWrite(buzzer, LOW);
    }
    else {
      delay(3000);
    }

    lcd.clear();
  }

  firstSensor = 0;   // Reset
}

void showNoVehicle() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("No Vehicle");
  lcd.setCursor(0, 1);
  lcd.print("Detected");
  delay(2000);
  lcd.clear();

  firstSensor = 0;   // Reset
}