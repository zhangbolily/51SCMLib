#include "general.h"

#ifndef _LCD_DIGITAL_TUBE_H_
#define _LCD_DIGITAL_TUBE_H_

/*声明和数字对应的数码管编码*/
extern unsigned char code num0;
extern unsigned char code num1;
extern unsigned char code num2;
extern unsigned char code num3;
extern unsigned char code num4;
extern unsigned char code num5;
extern unsigned char code num6;
extern unsigned char code num7;
extern unsigned char code num8;
extern unsigned char code num9;

/*声明和字母对应的数码管编码*/
extern unsigned char code letterA;
extern unsigned char code letterB;
extern unsigned char code letterC;
extern unsigned char code letterD;
extern unsigned char code letterE;
extern unsigned char code letterF;
extern unsigned char code letterG;
extern unsigned char code letterH;

/******************************************
 *声明这些函数
 ******************************************/
void showLCDNumber(unsigned char port, unsigned int num, unsigned char posPort, unsigned int time);
void showLCDLetter(unsigned char port, unsigned char letter, unsigned char posPort, unsigned int time);
void showLCDNumbers(unsigned char port, unsigned int num, unsigned char* posPort, unsigned char length, unsigned int time);
void showLCDLetters(unsigned char port, unsigned char letter[], unsigned char posPort[], unsigned char length, unsigned int time);

#endif
