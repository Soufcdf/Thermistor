const double ZERO_CELSIUS=273.15; 
class Thermistor
{ 
 private:
 double Rref, R0, Beta, T0 , Vcc;
 unsigned samplingBitsNumber;
 public:
 // CONSTRUCTOR 
 Thermistor(double Rref, double R0, double Beta , unsigned samplingBitsNumber=10 , 
 double Vcc=5, double T0=298.15);
 
 // GET TEMPERATURE (unit : 'K' for Kelvin, 'C' for Celsius, 'F' for Fahrenheit)
 double getTemperature(double adc, char unit='K'); 
};