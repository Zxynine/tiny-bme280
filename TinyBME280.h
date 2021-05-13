/* TinyBME280 Library expanded
   CC BY 4.0
   Licensed under a Creative Commons Attribution 4.0 International license: 
   http://creativecommons.org/licenses/by/4.0/
*/

#include <stdint.h>
#include <Arduino.h>

#if !defined(SDA_PIN) && !defined(SCL_PIN) 
#define I2C_TIMEOUT 1000
#define I2C_PULLUP 1
//SDA pin is connected on D (ATtiny Pin 6) (PB1)
#define SDA_PORT PORTB
#define SDA_PIN 1
//SCL pin is connected on D6 (ATtiny Pin 3) (PB4)
#define SCL_PORT PORTB
#define SCL_PIN 4
#endif
#include <SoftWire.h>

#ifndef TINYBME280
#define TINYBME280

/* Function declarations */

// Can be called before BME280setup
void BME280setI2Caddress(uint8_t address);

// Sets Normal mode, no upsampling, and reads the chip calibrations
void BME280setup();

// Temperature in DegC, resolution is 0.01 DegC
// Output value of “5123” equals 51.23 DegC
int32_t BME280temperature();

// Pressure in Pa as unsigned 32 bit integer
// Output value of “96386” equals 96386 Pa = 963.86 hPa
uint32_t BME280pressure();

// Humidity in %RH, resolution is 0.01%RH
// Output value of “4653” represents 46.53 %RH
uint32_t BME280humidity();

// Altitude in m, resolution is based on multiple factors
float BME280altitude(float referencePressure);

// Apparent temperature (Heat index) in DegC
float BME280heatIndex(float T, float R);

// Dew Point in DegC
float BME280dewPoint(float T, float R);
#endif
