#include <reg52.h>

#ifndef _GENERAL_H_
#define _GENERAL_H_

/************************************************************************************
 *把所有的引脚定义出来，方便函数使用
 * 这些指令操作符定义的变量不需要extern关键字就可以被外部文件使用
*************************************************************************************/
sbit P00 = P0^0;
sbit P01 = P0^1;
sbit P02 = P0^2;
sbit P03 = P0^3;
sbit P04 = P0^4;
sbit P05 = P0^5;
sbit P06 = P0^6;
sbit P07 = P0^7;
sbit P10 = P1^0;
sbit P11 = P1^1;
sbit P12 = P1^2;
sbit P13 = P1^3;
sbit P14 = P1^4;
sbit P15 = P1^5;
sbit P16 = P1^6;
sbit P17 = P1^7;
sbit P20 = P2^0;
sbit P21 = P2^1;
sbit P22 = P2^2;
sbit P23 = P2^3;
sbit P24 = P2^4;
sbit P25 = P2^5;
sbit P26 = P2^6;
sbit P27 = P2^7;
sbit P30 = P3^0;
sbit P31 = P3^1;
sbit P32 = P3^2;
sbit P33 = P3^3;
sbit P34 = P3^4;
sbit P35 = P3^5;
sbit P36 = P3^6;
sbit P37 = P3^7;

/************************************************************************************
 *声明一些通用函数
 * DataToPort()函数用来把数据发送到对应的端口
 * DataToBit()函数把数据发送到某一个引脚上
 * DataToBits()函数把数据发送到一些引脚上
 * ReadPort()函数读取某一个端口的数据，返回读取值
 * ReadBit()函数读取某一个引脚的数据，返回读取值
 * ReadBits()函数读取给定的引脚的数据，返回读取值数组的指针
 * Dalay()是一个简单的延时函数，用来做很短的延时
 ************************************************************************************/

void DataToPort(unsigned char Port, unsigned int Num);
void DataToBit(unsigned char PortBit,unsigned char Num);
void DataToBits(const unsigned char* PortBits,const unsigned char* Num, unsigned char Length);
unsigned char ReadPort(unsigned char Port);
unsigned char ReadBit(unsigned char PortBit);
void ReadBits(unsigned char *PortBits, unsigned char* Num, unsigned char Length);
void Delay(unsigned int T);
#endif
