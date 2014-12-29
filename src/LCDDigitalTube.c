#include "LCDDigitalTube.h"

/************************************************************************************
 * 定义和数字对应的数码管编码
 * 在LCDDigitalTube.h文件中已经用extern关键字声明了这些变量，现在在这里初始化它们
 * 声明和定义外部全局变量必须在不同的文件中进行，格式和这里一致
 ************************************************************************************/
unsigned char code num0 = 0x3F;
unsigned char code num1 = 0x06;
unsigned char code num2 = 0x5B;
unsigned char code num3 = 0x4F;
unsigned char code num4 = 0x66;
unsigned char code num5 = 0x6D;
unsigned char code num6 = 0x7D;
unsigned char code num7 = 0x07;
unsigned char code num8 = 0x7F;
unsigned char code num9 = 0x6F;

/************************************************************************************
 * 定义和字母对应的数码管编码
 * 在LCDDigitalTube.h文件中已经用extern关键字声明了这些变量，现在在这里初始化它们
 ************************************************************************************/
unsigned char code letterA = 0x77 ;
unsigned char code letterB = 0x7F ;
unsigned char code letterC = 0x39 ;
unsigned char code letterD = 0x3F ;
unsigned char code letterE = 0x79 ;
unsigned char code letterF = 0x71 ;
unsigned char code letterG = 0x3D ;
unsigned char code letterH = 0x76 ;

void ShowLCDNumber(unsigned char Port, unsigned int Num, unsigned char PosPort, unsigned int Time)
{
    int i, j;
    unsigned char DisplayNum = Num%10;                              //提取出需要显示的数字，不管数字多少位都只显示个位

    switch (DisplayNum)                                                           //将需要显示的数字变换为液晶管编码
    {
        case 0: DisplayNum = num0;break;
        case 1: DisplayNum = num1;break;
        case 2: DisplayNum = num2;break;
        case 3: DisplayNum = num3;break;
        case 4: DisplayNum = num4;break;
        case 5: DisplayNum = num5;break;
        case 6: DisplayNum = num6;break;
        case 7: DisplayNum = num7;break;
        case 8: DisplayNum = num8;break;
        case 9: DisplayNum = num9;break;
    }

   DataToPort(Port, ~DisplayNum);                                           //根据一般经验，绝大部分的液晶数码管控制信号都是低电平。所以正常的液晶管编码要按位取反
   DataToBit(PosPort, 0);                                                           //同上，向指定的引脚发出低电平的控制信号

    for(i = 0;i <= (Time*100);i++)                                              //设置一个定时循环
    {
        Delay(100);                                                                      //调用了Delay函数，简化代码
    }

    DataToPort(Port, 255);                                                         //刚刚用过的端口数据清除掉，以免造成干扰
    DataToBit(PosPort, 1);                                                          //清除数据，不影响下一次显示
}

void ShowLCDLetter(unsigned char Port, unsigned char Letter, unsigned char PosPort, unsigned int Time)
{
    int i, j;

    switch (Letter) {                                                                   //我们把要显示的字母转换为液晶管显示码
         case 1:Letter = letterA;break;
         case 65:Letter = letterA;break;
         case 2:Letter = letterB;break;
         case 66:Letter = letterB;break;
         case 3:Letter = letterC;break;
         case 67:Letter = letterC;break;
         case 4:Letter = letterD;break;
         case 68:Letter = letterD;break;
         case 5:Letter = letterE;break;
         case 69:Letter = letterE;break;
         case 6:Letter = letterF;break;
         case 70:Letter = letterF;break;
         case 7:Letter = letterG;break;
         case 71:Letter = letterG;break;
         case 8:Letter = letterH;break;
         case 72:Letter = letterH;break;
    default:Letter = letterE;
        break;
    }

   DataToPort(Port, ~Letter);                                                    //根据一般经验，绝大部分的液晶数码管控制信号都是低电平。所以正常的液晶管编码要按位取反
   DataToBit(PosPort, 0);                                                          //同上，向指定的引脚发出低电平的控制信号

    for(i = 0;i <= (Time*100);i++)                                             //设置一个定时循环
        Delay(100);                                                                     //使用了更简洁的形式简化了代码，同时调用delay函数

    DataToPort(Port, 255);                                                        //刚刚用过的端口数据清除掉，以免造成干扰
    DataToBit(PosPort, 1);                                                         //清除数据，不影响下一次显示

}

void ShowLCDNumbers(unsigned char Port, unsigned int Num, unsigned char* PosPort, unsigned char Length, unsigned int Time)
{
    unsigned int i, DisplayNum;
    int j;
    for(i = 0;i <= (Time*100);i++)
    {
        DisplayNum = Num;
        for(j = Length - 1;j >= 0;--j)
        {
            ShowLCDNumber(Port, DisplayNum, PosPort[j], 0);
            DisplayNum /= 10;                                                     //每次循环截掉一位，这样上面调用的ShowLCDNumber函数就可以把每一位都显示出来
        }
    }
}

void ShowLCDLetters(unsigned char Port, unsigned char Letter[], unsigned char PosPort[], unsigned char Length, unsigned int Time)
{
    int i, j;

    for(i = 0;i <= (Time*100);i++)
    {
        for(j = Length -1;j >= 0;--j)
        {
            ShowLCDLetter(Port, Letter[j], PosPort[j], 0);                //使用数组和循环，通过多次调用ShowLCDLetter函数把每个字母在对应的位置显示出来
        }
    }
}
