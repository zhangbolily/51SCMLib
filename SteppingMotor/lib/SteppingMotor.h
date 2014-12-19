#ifndef _STEPPING_MOTOR_H_
#define _STEPPING_MOTOR_H_
#include "E:\Users\BallChang\Documents\GitHub\51SCMLib\General\general.h"

/*
 * 定义不同的励磁方式所需的代码
 */
unsigned char code mode1[4] = { 0x03, 0x06, 0x0c, 0x09 };
unsigned char code mode2[2] = { 0x0a, 0x05 };
unsigned char code mode3[8] = { 0x01, 0x03, 0x02, 0x06, 0x04, 0x0c, 0x08, 0x09 };
unsigned char code mode4[4] = { 0x01, 0x02, 0x04, 0x08 };

/*
 * 声明一些函数
 */
void driveMotor(unsigned char* mode, unsigned char port, char length);

void driveMotorOnce(unsigned char num, unsigned char port);

#endif
