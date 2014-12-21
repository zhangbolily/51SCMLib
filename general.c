/******************************************
 * 定义这些函数
******************************************/

#include "general.h"
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

void delay(unsigned int t)
{
    while(--t);
}
