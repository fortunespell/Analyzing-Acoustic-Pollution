#include <SPI.h>
const int irSensorPin = 27;
const int buzzerPin = 22;
const int redLedPin = 8;
const int blueLedPin = 7;
const int greenLedPin = 27;
const int microphone = 26;
const int button = 13;
const int tempSensorclk = 5;
const int tempSensordata = 4;

const int adcMaxValue = 1023;  // Maximum value of the ADC (10-bit resolution)
const float referenceVoltage = 3.3;  // Reference voltage of the ADC

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(microphone,OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:


  int Mic = analogRead(microphone);
  //int mic_out=(Mic-500)/10.93374569274515;
  float decibels = adcToDecibels(Mic, adcMaxValue);

  
  //Serial.println(Mic);
  if (decibels<-10)
  {
    digitalWrite(greenLedPin, HIGH);
  }
  if (decibels<-20)
  {
    digitalWrite(blueLedPin, HIGH);
  }
  if (decibels<-35)
  {
    digitalWrite(redLedPin, HIGH);
  }

  else
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
    digitalWrite(blueLedPin, LOW);
  Serial.println(decibels);
  delay(100);
}

float adcToDecibels(int adcValue, int adcMaxValue) {
  float voltage = (adcValue / (float)adcMaxValue) * referenceVoltage;
  float decibels = 20 * log10(voltage);
  return decibels;
}
