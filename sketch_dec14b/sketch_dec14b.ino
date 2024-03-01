#include <SPI.h>
const int irSensorPin = 27;
const int buzzerPin = 22;
const int redLedPin = 8;
const int blueLedPin = 7;
const int greenLedPin = 9;
const int microphone = 26;
const int button = 13;
const int tempSensorclk = 5;
const int tempSensordata = 4;
void setup() {
  // put your setup code here, to run once:
  // put your setup code here, to run once:

  pinMode(microphone,OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int Mic = analogRead(microphone);
int decibels=(Mic)/10.24;

  if (decibels < 40) {
    blinkLED(blueLedPin);
  } 
  else if (decibels > 60) {
    blinkLED(redLedPin);
    blinkLED(buzzerPin);
  } 
  else {
    blinkLED(9);
    
  }
  Serial.println(decibels);
  delay(100);
}

// Function to blink the specified LED
void blinkLED(int ledPin) {
  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW);
  delay(100);
}
