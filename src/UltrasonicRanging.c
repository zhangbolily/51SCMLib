#include "UltrasonicRanging.h"

/*********************************************************************
 * 定义声明的变量
 *********************************************************************/
unsigned char TimeH = 0;
unsigned char TimeL = 0;
unsigned char Flag = 0;
unsigned char PortBits[2] = 0;                            //调用所有的函数以前，必须再次给这个数组初始化

void Init(unsigned char *PortBits)
{
    DataToBit(PortBits[0], 0);                                  //超声波模块两个端口先初始化为0
    DataToBit(PortBits[1], 0);
    TMOD = 0x09;                                                //设置定时器0工作模式为16位定时器，只有在INT0为高电平和TR0为1时才打开
    TH0 = 0;                                                          //给定时器初始化
    TL0 = 0;
    EX0 = 1;                                                          //打开INT0外部中断
    IT0 = 1;                                                          //设置INT0中断为下降沿中断
    EA = 1;                                                            //打开总中断
}

void Trigger(unsigned char *PortBits)
{
    DataToBit(PortBits[1], 0);                                  //先设定信号接收口为低电平，以免触发计时器
    TH0 = 0;                                                         //再次初始化计时器
    TL0 = 0;
    TR0 = 1;                                                          //打开定时器0中断
    Flag = 0;                                                         //初始化测量成功标志
    DataToBit(PortBits[0], 1);                                  //发出高电平激活模块
    Delay(20);
    DataToBit(PortBits[0], 0);
}

unsigned int Distance(unsigned float Frequency)
{
    unsigned int Distance = 0;                               //距离的单位是厘米
    unsigned int Time = TimeH;
    Time <<= 8;Time |= TimeL;                              //合并两个数据为一个
    Distance = Time/Frequency*0.204;                  //根据公式来求距离
    return Distance;
}

void Time() interrupt 0
{
    TR0 = 0;                                                          //关闭定时器0中断
    DataToBit(PortBits[1], 0);                                  //给信号接收引脚低电平以免再次触发中断
    TimeH = TH0;                                                 //提取时间的值
    TimeL = TL0;
    Flag = 1;                                                         //测量成功标志
}
