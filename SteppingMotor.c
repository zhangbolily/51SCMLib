#include "SteppingMotor.h"

unsigned char code mode1[4] = { 0x03, 0x06, 0x0c, 0x09 };
unsigned char code mode2[2] = { 0x0a, 0x05 };
unsigned char code mode3[8] = { 0x01, 0x03, 0x02, 0x06, 0x04, 0x0c, 0x08, 0x09 };
unsigned char code mode4[4] = { 0x01, 0x02, 0x04, 0x08 };

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
