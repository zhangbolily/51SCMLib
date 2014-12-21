#include "LCDDigitalTube.h"

/*定义和数字对应的数码管编码*/
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

/*定义和字母对应的数码管编码*/
unsigned char code letterA = 0x77 ;
unsigned char code letterB = 0x7F ;
unsigned char code letterC = 0x39 ;
unsigned char code letterD = 0x3F ;
unsigned char code letterE = 0x79 ;
unsigned char code letterF = 0x71 ;
unsigned char code letterG = 0x3D ;
unsigned char code letterH = 0x76 ;

void showLCDNumber(unsigned char port, unsigned int num, unsigned char posPort, unsigned int time)
{
    int i, j;
    unsigned char displayNum = num%10;                  //提取出需要显示的数字，只显示个位

    switch (displayNum)                                                 //将需要显示的数字变换为液晶管编码
    {
        case 0: displayNum = num0;break;
        case 1: displayNum = num1;break;
        case 2: displayNum = num2;break;
        case 3: displayNum = num3;break;
        case 4: displayNum = num4;break;
        case 5: displayNum = num5;break;
        case 6: displayNum = num6;break;
        case 7: displayNum = num7;break;
        case 8: displayNum = num8;break;
        case 9: displayNum = num9;break;
    }

    displayNum = ~displayNum;
   dataToPort(port, displayNum);
   dataToBit(posPort, 0);

    for(i = 0;i <= (time*100);i++)                       //设置一个定时循环
    {
        for(j = 0;j < 100;j++);
    }

    dataToPort(port, 255);
    dataToBit(posPort, 1);
}

void showLCDLetter(unsigned char port, unsigned char letter, unsigned char posPort, unsigned int time)
{
    int i, j;

    switch (letter) {                                                       //我们把要显示的字母转换为液晶管显示码
         case 1:letter = letterA;break;
         case 65:letter = letterA;break;
         case 2:letter = letterB;break;
         case 66:letter = letterB;break;
         case 3:letter = letterC;break;
         case 67:letter = letterC;break;
         case 4:letter = letterD;break;
         case 68:letter = letterD;break;
         case 5:letter = letterE;break;
         case 69:letter = letterE;break;
         case 6:letter = letterF;break;
         case 70:letter = letterF;break;
         case 7:letter = letterG;break;
         case 71:letter = letterG;break;
         case 8:letter = letterH;break;
         case 72:letter = letterH;break;
    default:letter = letterE;
        break;
    }

   dataToPort(port, ~letter);
   dataToBit(posPort, 0);

    for(i = 0;i <= (time*100);i++)                       //设置一个定时循环
        for(j = 0;j < (100);j++);

    dataToPort(port, 255);
    dataToBit(posPort, 1);

}

void showLCDNumbers(unsigned char port, unsigned int num, unsigned char* posPort, unsigned char length, unsigned int time)
{
    unsigned int i, displayNum;
    int j;
    for(i = 0;i <= (time*100);i++)
    {
        displayNum = num;
        for(j = length - 1;j >= 0;--j)
        {
            showLCDNumber(port, displayNum, posPort[j], 0);
            displayNum /= 10;
        }
    }
}

void showLCDLetters(unsigned char port, unsigned char letter[], unsigned char posPort[], unsigned char length, unsigned int time)
{
    int i, j;

    for(i = 0;i <= (time*100);i++)
    {
        for(j = length -1;j >= 0;--j)
        {
            showLCDLetter(port, letter[j], posPort[j], 0);
        }
    }
}
