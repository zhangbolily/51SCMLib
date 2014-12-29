#ifndef _ULTRASONIC_RANGING_
#define _ULTRASONIC_RANGING_
#include "general.h"

/************************************************************
 * 声明一些需要使用的全局变量，使用extern关键字。
 ************************************************************/
extern unsigned char TimeH, TimeL, Flag;
extern unsigned char PortBits[2];

void Init(unsigned char* PortBits);
void Trigger(unsigned char* PortBits);
unsigned int Distance(unsigned float Frequency);
#endif
