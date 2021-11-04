#include <Arduino.h>

int MOTOR_PIN = 32;
int RESISTOR_PIN = 25;

// Setting PWM properties
const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;

void setup()
{

  Serial.begin(9600);

  pinMode(MOTOR_PIN, OUTPUT);
  // configure LED PWM functionalitites
  ledcSetup(pwmChannel, freq, resolution);

  // attach the channel to the GPIO to be controlled
  ledcAttachPin(MOTOR_PIN, pwmChannel);
}

void loop()
{
  int analogValue = analogRead(RESISTOR_PIN);

  int brightness = map(analogValue, 0, 1023, 0, 255);

  ledcWrite(pwmChannel, brightness);

  // print out the value
  Serial.print("Analog: ");
  Serial.print(analogValue);
  Serial.print(", Brightness: ");
  Serial.println(brightness);
  delay(100);
}
