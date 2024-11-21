#include "Thermistor.h"
#include <math.h>

// Constructor for the Thermistor class
// Initializes thermistor parameters for temperature calculation
Thermistor::Thermistor(double Rref, double R0, double Beta, 
                       unsigned samplingBitsNumber, double Vcc, double T0) {
    // Store reference resistance
    this->Rref = Rref;
    // Store resistance at reference temperature
    this->R0 = R0;
    // Store Beta coefficient for temperature calculation
    this->Beta = Beta;
    // Store number of sampling bits for ADC resolution
    this->samplingBitsNumber = samplingBitsNumber;
    // Store supply voltage
    this->Vcc = Vcc;
    // Store reference temperature
    this->T0 = T0;
}

// Method to calculate temperature from ADC reading
// Supports conversion to Kelvin, Celsius, and Fahrenheit
double Thermistor::getTemperature(double adc, char unit)
{
    // Calculate maximum possible ADC value based on sampling bits
    // Formula: 2^n - 1, where n is the number of sampling bits
    double Adc = pow(2, samplingBitsNumber) - 1;

    // Calculate temperature using the Steinhart-Hart equation
    // This is the inverse of the beta parameter equation for temperature
    double tempK = 1.0 / ((1.0 / T0) +
                          (1.0 / Beta) *log((R0 * (Adc / adc - 1)) / Rref));
    
    // Convert temperature based on requested unit
    if (unit == 'C') 
    {
        // Convert Kelvin to Celsius
        return tempK - ZERO_CELSIUS; 
    }
    else if (unit == 'F') {
        // Convert Kelvin to Fahrenheit
        return (tempK - ZERO_CELSIUS) * 9/5 + 32;
    }

    // Return temperature in Kelvin if no specific unit is specified
    return tempK;
}