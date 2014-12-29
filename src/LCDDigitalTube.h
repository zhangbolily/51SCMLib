#include "general.h"

#ifndef _LCD_DIGITAL_TUBE_H_
#define _LCD_DIGITAL_TUBE_H_

/************************************************************************************
 * 声明和数字对应的数码管编码，使用extern关键字，可作为外部变量使用
 ************************************************************************************/
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

/************************************************************************************
 * 声明和字母对应的数码管编码，使用extern关键字，可作为外部变量使用
 ************************************************************************************/
extern unsigned char code letterA;
extern unsigned char code letterB;
extern unsigned char code letterC;
extern unsigned char code letterD;
extern unsigned char code letterE;
extern unsigned char code letterF;
extern unsigned char code letterG;
extern unsigned char code letterH;

/************************************************************************************
 *声明这些函数
 * showLCDNumber函数通过输入的参数，把正确的数字编码发送到指定的端口上
 * showLCDLetter函数通过输入的参数，把正确的字母编码发送到指定的端口上
 * showLCDNumbers函数通过输入的参数，把正确的数字编码发送到指定的几个端口上
 * showLCDLetter函数通过输入的参数，把正确的字母编码发送到指定的几个端口上
 ************************************************************************************/
void ShowLCDNumber(unsigned char Port, unsigned int Num, unsigned char PosPort, unsigned int Time);
void ShowLCDLetter(unsigned char Port, unsigned char Letter, unsigned char PosPort, unsigned int Time);
void ShowLCDNumbers(unsigned char Port, unsigned int Num, unsigned char* PosPort, unsigned char Length, unsigned int Time);
void ShowLCDLetters(unsigned char Port, unsigned char Letter[], unsigned char PosPort[], unsigned char Length, unsigned int Time);

#endif
