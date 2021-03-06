/**
 * @file Serial Sensor example
 * This example reads data from a sensor (default choice is the serial SDS011)
 * and sends it to a computer using USB serial communications.
 *
 * This example is part of the hackAIR Arduino Library and is available
 * in the Public Domain.
 */

#include "hackair.h"

// Specify your sensor
hackAIR sensor(SENSOR_SDS011);

void setup() {
  // Initialize the sensor
  sensor.begin();

  // Open serial port
  Serial.begin(9600);
}

void loop() {
  // Take a reading
  struct hackAirData data;
  sensor.readData(data);

  // If it was invalid, print error
  if (data.error != 0) {
    Serial.println("Error!");
  } else {
    // Print the values to serial
    Serial.print("PM2.5: ");
    Serial.println(data.pm25);
    Serial.print("PM10: ");
    Serial.println(data.pm10);
    Serial.println("---");
  }

  // Wait a bit so the data is readable
  delay(2500);
}
