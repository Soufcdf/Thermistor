#include <Arduino.h>
#include "Thermistor.h"

// Configuration of the thermistor
const double Rref = 50000;      // Reference resistance in ohms
const double R0 = 47000;        // Resistance at 25°C in ohms
const double Beta = 3950;       // Beta coefficient 
const unsigned samplingBits = 10; // ADC converter bits
const int thermistorPin = A1;   // Analog pin for reading

Thermistor thermistor(Rref, R0, Beta, samplingBits);

void setup() {
  Serial.begin(9600);
  pinMode(thermistorPin, INPUT);
}

void loop() {
  // Read ADC value
  int adcValue = analogRead(thermistorPin);
  
  // Convert to temperature
  double tempC = thermistor.getTemperature(adcValue, 'C');
  
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println(" °C");
  
  delay(5000); // Measure every 5 seconds
}