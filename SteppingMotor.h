#include "general.h"
#ifndef _STEPPING_MOTOR_H_
#define _STEPPING_MOTOR_H_

/******************************************
 * 定义不同的励磁方式所需的代码
 * 这些代码将在定义文件中初始化
 ******************************************/
extern unsigned char code mode1[4];
extern unsigned char code mode2[2];
extern unsigned char code mode3[8];
extern unsigned char code mode4[4];

/******************************************
 * 声明一些函数
 ******************************************/
void driveMotor(unsigned char* mode, unsigned char port, char length);

void driveMotorOnce(unsigned char num, unsigned char port);

#endif
