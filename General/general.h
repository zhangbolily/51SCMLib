#ifndef _GENERAL_H_
#define _GENERAL_H_
#include <reg52.h>

/*
 *把所有的引脚定义出来
*/
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

/*
 *声明一些通用函数
 */

void dataToPort(unsigned char port, unsigned int num);
void dataTobitNum(unsigned char portBit,unsigned char num);
void dataToBits(const unsigned char* portBits,const unsigned char* num, unsigned char length);

/*
 * 定义这些函数
 */

void dataToPort(unsigned char port, unsigned int num)
{
    switch (port) {
        case 0:P0 = num;break;
        case 1:P1 = num;break;
        case 2:P2 = num;break;
        case 3:P3 = num;break;
    default:
        break;
    }
}

void dataToBit(unsigned char portBit,unsigned char num)
{
     unsigned char port, bitNum;
    if(num != 0)
    {
        num = 1;
    }

    bitNum = portBit%10;
    port = portBit/10%10;
    switch (port)                        //先识别出端口号
    {
    case 0:
        switch (bitNum) {            //给对应的位低电平
            case 0:P00=num;break;
            case 1:P01=num;break;
            case 2:P02=num;break;
            case 3:P03=num;break;
            case 4:P04=num;break;
            case 5:P05=num;break;
            case 6:P06=num;break;
            case 7:P07=num;break;
        default:
            break;
        };break;

    case 1:
        switch (bitNum) {
            case 0:P10=num;break;
            case 1:P11=num;break;
            case 2:P12=num;break;
            case 3:P13=num;break;
            case 4:P14=num;break;
            case 5:P15=num;break;
            case 6:P16=num;break;
            case 7:P17=num;break;
        default:
            break;
        };break;

    case 2:
        switch (bitNum) {
            case 0:P20=num;break;
            case 1:P21=num;break;
            case 2:P22=num;break;
            case 3:P23=num;break;
            case 4:P24=num;break;
            case 5:P25=num;break;
            case 6:P26=num;break;
            case 7:P27=num;break;
        default:
            break;
        };break;

    case 3:
        switch (bitNum) {
            case 0:P30=num;break;
            case 1:P31=num;break;
            case 2:P32=num;break;
            case 3:P33=num;break;
            case 4:P34=num;break;
            case 5:P35=num;break;
            case 6:P36=num;break;
            case 7:P37=num;break;
        default:
            break;
        };break;
    }
}

void dataToBits(const unsigned char* portBits,const unsigned char* num, unsigned char length)
{
    length -= 1;
    for(;length >= 0;--length)
    {
        dataToBit(portBits[length], num[length]);
    }
}
#endif
