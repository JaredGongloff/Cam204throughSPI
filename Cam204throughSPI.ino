/*
 Arduino to CAM204 for Resonant Inductive Sensor
 
 Shows the output of a Resonant Inductive Sensor through a
 SPI library. 

 Circuit:
 SCP1000 sensor attached to pins 6, 7, 10 - 13:
 DRDY: pin 6
 CSB: pin 7
 MOSI: pin 11
 MISO: pin 12
 SCK: pin 13
 */

// the sensor communicates using SPI, so include the library:
#include <SPI.h>

//const int  dataOut = 11;  //MOSI
//const int   dataIn = 12;  //MISO - not used, but part of builtin SPI
//const int spiClock = 13;  //sck
const int SS1 = 10;  //SS

const byte REG0 = B00000000; //Register 0 Write command
const byte REG1 = B00010000; //Register 1 Write command


void setup() {
  //byte clr;
  //pinMode(dataOut, OUTPUT);
  pinMode(SS1, OUTPUT);  //Set pin direction for SS
  
  digitalWrite(SS1, HIGH);
  
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);  //Output at 0,0 clock edge for CAM204 (also Arduino Default mode)
  SPI.setClockDivider(SPI_CLOCK_DIV16); //SPI.setClockDivider() Min (or max?) at 1.1kHz
  
} //End setup function

// Start loop function
void loop() {

  serial.println();
} //End of Loop function

float readAdc(int value, int channel) {
  byte dacRegister = 0b00010000; //arduino tells dac to read with 4th bit, rest makes way for 1st 4 bits of 12 bit value
  int dacSecondaryByteMask = 0b0001000000000010;
  byte dacPrimaryByte = (value >> 8) | dacRegister;
  byte dacSecondaryByte = value & dacSecondaryByteMask;
  00000010
  digitalWrite(SS1, LOW);
  SPI.transfer(REG0);
  SPI.transfer(REG1);
  digitalWrite(SS1, HIGH);
  
  return value;
}
  
