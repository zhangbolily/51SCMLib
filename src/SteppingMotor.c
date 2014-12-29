#include "SteppingMotor.h"

/************************************************************************************
 * 定义和数字对应的励磁模式编码
 * 在SteppingMotor.h文件中已经用extern关键字声明了这些变量，现在在这里初始化它们
 * 声明和定义外部全局变量必须在不同的文件中进行，格式和这里一致
 ************************************************************************************/

unsigned char code Mode1[4] = { 0x03, 0x06, 0x0c, 0x09 };                                               //两相励磁
unsigned char code Mode2[2] = { 0x0a, 0x05 };                                                                  //两相励磁
unsigned char code Mode3[8] = { 0x01, 0x03, 0x02, 0x06, 0x04, 0x0c, 0x08, 0x09 };         //一二相混合励磁
unsigned char code Mode4[4] = { 0x01, 0x02, 0x04, 0x08 };                                               //单相励磁

void DriveMotor(unsigned char Port, unsigned char* Mode, char Length)
{
    Length -= 1;
    for(;Length >= 0;--Length)
    {
        DataToPort(Port, Mode[length]);                                                                                   //通过循环把编码发送到特定的端口上，实现磁场旋转一周
        Delay(200);                                                                                                                  //机械运动是需要时间的，我们稍微延时一小会就行了，否则电动机是不会转动的
    }
}

void DriveMotorOnce(unsigned char Num, unsigned char Port)
{
    DataToPort(port, num);                                                                                                     //为了实现更加精准的控制，该函数允许你只将一个代码发送到指定的端口
    Delay(200);                                                                                                                       //这个函数很像是DataToPort的孪生兄弟，但是加上了Delay便使得它与众不同，成为了可以驱步进电动机的函数
}
