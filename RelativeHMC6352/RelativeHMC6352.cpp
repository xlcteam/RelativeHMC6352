
#include "RelativeHMC6352.h"

RelativeHMC6352::RelativeHMC6352()
{
    _north = 0.0;
}

float RelativeHMC6352::angle_raw()
{

    int HMC6352Address = 0x42;
    int slaveAddress, i;
    slaveAddress = HMC6352Address >> 1;
    byte headingData[2];
    int val;
    Wire.beginTransmission(slaveAddress);
    Wire.write("A");              // The "Get Data" command
    Wire.endTransmission();
    delay(10);

    Wire.requestFrom(slaveAddress, 2);
    i = 0;
    while(Wire.available() && i < 2)
    {
      headingData[i] = Wire.read();
      i++;
    }
    val = headingData[0]*256 + headingData[1];

    return (int(val / 10) + float((val % 10) / 10.0));
}

float RelativeHMC6352::angle()
{
    float relative_angle = fmod(RelativeHMC6352::angle_raw() - _north + 360, 360.0);

    if (relative_angle < 0.0)
        relative_angle += 360.0;

    return relative_angle;
}

void RelativeHMC6352::set_north()
{
    Wire.begin();
    _north = RelativeHMC6352::angle_raw();
}

float RelativeHMC6352::real_north()
{
    return _north;
}


