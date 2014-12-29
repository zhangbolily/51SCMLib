#include "general.h"
#ifndef _STEPPING_MOTOR_H_
#define _STEPPING_MOTOR_H_
/************************************************************************************
 * 本文件中的函数针对的是两相四线步进电动机
 * 如果需要用于别的步进电动机请自行研究源代码
 ************************************************************************************/


/******************************************
 * 声明不同的励磁方式所需的代码
 * 这些代码将在定义文件中初始化
 ******************************************/
extern unsigned char code Mode1[4];
extern unsigned char code Mode2[2];
extern unsigned char code Mode3[8];
extern unsigned char code Mode4[4];

/************************************************************************************
 * 声明一些函数
 * driveMotor函数通过向指定的端口发送励磁编码实现对步进电动机的驱动
 * driveMotorOnce和上面的函数不同的是，这个函数一次只向一个端口发送一次编码
 ************************************************************************************/
void DriveMotor(unsigned char Port, unsigned char* Mode, char Length);

void DriveMotorOnce(unsigned char Num, unsigned char Port);

#endif
