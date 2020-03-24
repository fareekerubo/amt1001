#include <amt1001_ino.h>// incude the amt1001 library
uint16_t humidity;
uint16_t temperature;
// Assign anaogue pins of the arduino for the hum and temp pins from the amt_1001
int tempPin=A0;
int humPin=A1;


void setup() {
  // put your setup code here, to run once:
pinMode(tempPin,INPUT);
pinMode(humPin,INPUT);
Serial.begin(9600);
}


void loop() {

 uint16_t step = analogRead(tempPin); 
float temperature = amt1001_gettemperature(step);
Serial.print(temperature);
Serial.print(" ");
uint16_t step1 = analogRead(humPin);
double volt = (double)step1 * (5.0 / 1023.0);
humidity = amt1001_gethumidity(volt);
Serial.print(humidity);
Serial.println(" ");
}
