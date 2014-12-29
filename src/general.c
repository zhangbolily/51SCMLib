/******************************************
 * 定义函数
******************************************/

#include "general.h"
void DataToPort(unsigned char Port, unsigned int Num)
{
    switch (Port) {                                                                     //根据Port的值来决定数据发送到哪一个端口
        case 0:P0 = Num;break;                                                  //当Port为0时，输入的Num就发送到P0口
        case 1:P1 = Num;break;
        case 2:P2 = Num;break;
        case 3:P3 = Num;break;
    default:
        break;
    }
}

void DataToBit(unsigned char PortBit,unsigned char Num)
{
     unsigned char port, bitNum;
    if(Num != 0)                                                                        //Num只要是不为0就是1，每个位的值不是0就是1
    {
        Num = 1;
    }

    bitNum = PortBit%10;                                                        //用取模运算符取出PortBit中的个位数
    port = PortBit/10%10;
    switch (port)                                                                       //先确定该发送的端口
    {
    case 0:
        switch (bitNum) {                                                            //把数据发送到指定的位
            case 0:P00=Num;break;                                               //PortBit为00时，port为0，bitNum为0 数据发送到P00口
            case 1:P01=Num;break;
            case 2:P02=Num;break;
            case 3:P03=Num;break;
            case 4:P04=Num;break;
            case 5:P05=Num;break;
            case 6:P06=Num;break;
            case 7:P07=Num;break;
        default:
            break;
        };break;

    case 1:
        switch (bitNum) {
            case 0:P10=Num;break;
            case 1:P11=Num;break;
            case 2:P12=Num;break;
            case 3:P13=Num;break;
            case 4:P14=Num;break;
            case 5:P15=Num;break;
            case 6:P16=Num;break;
            case 7:P17=Num;break;
        default:
            break;
        };break;

    case 2:
        switch (bitNum) {
            case 0:P20=Num;break;
            case 1:P21=Num;break;
            case 2:P22=Num;break;
            case 3:P23=Num;break;
            case 4:P24=Num;break;
            case 5:P25=Num;break;
            case 6:P26=Num;break;
            case 7:P27=Num;break;
        default:
            break;
        };break;

    case 3:
        switch (bitNum) {
            case 0:P30=Num;break;
            case 1:P31=Num;break;
            case 2:P32=Num;break;
            case 3:P33=Num;break;
            case 4:P34=Num;break;
            case 5:P35=Num;break;
            case 6:P36=Num;break;
            case 7:P37=Num;break;
        default:
            break;
        };break;
    }
}

void DataToBits(const unsigned char* PortBits,const unsigned char* Num, unsigned char Length)
{
    Length -= 1;                                                                //Length说明了端口的数量，通过循环把数据发送到这些端口
    for(;Length >= 0;--Length)
    {
        DataToBit(PortBits[Length], Num[Length]);                 //调用几次上面的函数就可以实现
    }
}

unsigned char ReadPort(unsigned char Port)
{
    unsigned char Num;
    switch (Port) {                                                                     //根据Port的值来决定读取哪个端口的数据
        case 0:Num = P0;break;                                                  //当Port为0时，就读取P0的值
        case 1:Num = P1;break;
        case 2:Num = P2;break;
        case 3:Num = P3;break;
    default:
        Num = 0;
        break;
        }
    return Num;
}

unsigned char ReadBit(unsigned char PortBit)
{
    unsigned char port, bitNum, Num = 0;

   bitNum = PortBit%10;                                                        //用取模运算符取出PortBit中的个位数
   port = PortBit/10%10;
   switch (port)                                                                       //先确定该读取的端口
   {
   case 0:
       switch (bitNum) {                                                            //读取指定的位的数据
           case 0:Num = P00;break;                                               //PortBit为00时，port为0，bitNum为0 读取P00口的数据
           case 1:Num = P01;break;
           case 2:Num = P02;break;
           case 3:Num = P03;break;
           case 4:Num = P04;break;
           case 5:Num = P05;break;
           case 6:Num = P06;break;
           case 7:Num = P07;break;
       default:
           break;
       };break;

   case 1:
       switch (bitNum) {
           case 0:Num = P10;break;
           case 1:Num = P11;break;
           case 2:Num = P12;break;
           case 3:Num = P13;break;
           case 4:Num = P14;break;
           case 5:Num = P15;break;
           case 6:Num = P16;break;
           case 7:Num = P17;break;
       default:
           break;
       };break;

   case 2:
       switch (bitNum) {
           case 0:Num = P20;break;
           case 1:Num = P21;break;
           case 2:Num = P22;break;
           case 3:Num = P23;break;
           case 4:Num = P24;break;
           case 5:Num = P25;break;
           case 6:Num = P26;break;
           case 7:Num = P27;break;
       default:
           break;
       };break;

   case 3:
       switch (bitNum) {
           case 0:Num = P30;break;
           case 1:Num = P31;break;
           case 2:Num = P32;break;
           case 3:Num = P33;break;
           case 4:Num = P34;break;
           case 5:Num = P35;break;
           case 6:Num = P36;break;
           case 7:Num = P37;break;
       default:
           break;
       };break;
   }
   return Num;
}

void ReadBits(unsigned char *PortBits, unsigned char* Num, unsigned char Length)
{
    int i = 0;
    for(;i < Length;i++)
    {
        Num[i] = ReadBit(PortBits[i]);
    }
}

void Delay(unsigned int T)
{
    while(--T);                                                                     //很简单的循环，可以通过机器指令周期估算出循环一次的时间
}
