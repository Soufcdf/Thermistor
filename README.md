# Thermistor
# Thermistor Library

Author: SoufCDF
Date: November 21, 2024

## Description

This library provides a simple and efficient way to interface with thermistors in Arduino projects. It allows for accurate temperature readings using various thermistor configurations and supports output in Kelvin, Celsius, and Fahrenheit.

## Key Terms

- **Rref**: Reference resistance in ohms
- **R0**: Resistance of the thermistor at 25°C (or reference temperature) in ohms
- **Beta**: Beta coefficient of the thermistor
- **samplingBits**: Number of bits used by the ADC for sampling
- **Vcc**: Supply voltage (typically 5V for Arduino)
- **T0**: Reference temperature in Kelvin (usually 298.15K, which is 25°C)

## Example Usage

Here's a simple example demonstrating how to use the Thermistor library:

CPP:
#include <Arduino.h>
#include "Thermistor.h"

// Thermistor configuration
const double Rref = 50000;      // Reference resistance in ohms
const double R0 = 47000;        // Resistance at 25°C in ohms
const double Beta = 3950;       // Beta coefficient
const unsigned samplingBits = 10; // ADC converter bits
const int thermistorPin = A1;   // Analog pin for reading

Thermistor thermistor(Rref, R0, Beta, samplingBits);
![Capture d’écran 2024-11-21 150328](https://github.com/user-attachments/assets/e0bcd595-ceac-4310-9aa7-6c88089973a6)

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
