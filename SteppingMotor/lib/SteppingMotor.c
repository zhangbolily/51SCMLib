#include "SteppingMotor.h"

void delay(unsigned int t)
{
      while(--t);
}

void driveMotor(unsigned char* mode, unsigned char port, char length)
{
    length -= 1;
    for(;length >= 0;--length)
    {
        dataToPort(port, mode[length]);
        delay(200);
    }
}

void driveMotorOnce(unsigned char num, unsigned char port)
{
    dataToPort(port, num);
    delay(200);
}
