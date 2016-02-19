#include <Wire.h>
#include <RelativeHMC6352.h>


RelativeHMC6352 compass = RelativeHMC6352();

void setup ()
{
  Serial.begin(115200);
  compass.set_north();
}

void loop ()
{
  Serial.println(compass.angle());
  delay(20);
}
