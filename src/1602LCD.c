#include "1602LCD.h"

/************************************************************************************
 * 定义指令码
 * 在1602LCD.h文件中已经用extern关键字声明了这些变量，现在在这里初始化它们
 * 声明和定义外部全局变量必须在不同的文件中进行，格式和这里一致
 ************************************************************************************/

extern const unsigned char code Clear = 1;                      //指令1 Clear：清显示，指令码01H，光标回复到地址00H位置。
extern const unsigned char code CursorReset = 2;            //指令2 CursorReset：光标复位，光标返回到地址0H位置。
extern const unsigned char code EntryModeSet = 4;    //指令3 EntryModeSet：光标和显示模式设置I/D：光标移动方向，使用时指令码加2为右移，不加则为左移。
                                                                                         //显示模式设置S：屏幕上所有文字是否和光标一起左移或者右移。使用时指令码加1为有效，不加为无效。
extern const unsigned char code DisplaySwitch = 8;         //指令4 DisplaySwitch：显示开关控制。D：控制整体显示的开与关，指令码加4为开显示，不加则为关显示。
                                                                                         //C：控制光标的开与关，指令码加2表示有光标，不加表示无光标。B：控制光标是否闪烁，加1闪烁，不加不闪烁。
extern const unsigned char code CursorDisplayMove = 16;//指令5 CursorDisplayMove：光标或显示移位S/C：指令码加8移动显示的文字，不加移动光标。移动方向R/L：指令码加4向右移动，不加向左移动，同时光标跟随移动。
extern const unsigned char code FunctionSet = 32;            //指令6 FunctionSet：功能设置命令DL：指令码加16为8位总线，不加为4位总线。N：指令码加8为双行显示，不加为单行显示。F：指令码加4显示5×10的点阵字符，不加为5×7的点阵字符。
extern const unsigned char code CharRAMSet = 64;           //指令7 CharRAMSet：字符发生器RAM地址设置。加上6位字符发生存贮器地址即可。
extern const unsigned char code DDRAMSet = 128;             //指令8 DDRAMSet：DDRAM地址设置。加上7位显示数据存贮器地址即可。
extern const unsigned char code ReadStatus = 0;                  //指令9 ReadStatus：读忙信号和光标地址。BF：为忙标志位，高电平表示忙，此时模块不能接受命令或者数据，如果为低电平表示不忙。

/************************************************************************************
 * 定义函数
 ************************************************************************************/
//NOTE：WriteCom函数需要先设置使能端为0
//NOTE：函数的延迟应该作出调整
//NOTE：对比修改后的Keil工程文件，初始化函数需要作出调整
void InitDisplay(unsigned char Port, unsigned char *RW)
{
    WriteCom(Port, RW, Clear);                                          //初始化第一步清除显示
    WriteCom(Port, RW, FunctionSet + 28 );                              //设置为默认显示模式
    WriteCom(Port, RW, DisplaySwitch + 4);                      //打开显示开关
    WriteCom(Port, RW, EntryModeSet + 2);
    WriteCom(Port, RW, DDRAMSet);                                   //设置数据存储器地址
}

void WriteChar(unsigned char Port, unsigned char *RW, unsigned char Char)
{
    DataToBit(RW[2], 0);                                                                    //设置使能端为0
    DataToBit(RW[0], 1);                                                                    //设置为写数据模式
    DataToBit(RW[1], 0);                                                                    //设置为写入模式
    DataToPort(Port, Char);                                                               //数据写入到指定的端口
    Delay(200);                                                                                     //短暂延时
    DataToBit(RW[2], 1);                                                                    //设置使能端为1
    Delay(200);                                                                                     //短暂延时
    DataToBit(RW[2], 0);                                                                    //将使能端设置为0触发写入
}

void WriteCom(unsigned char Port, unsigned char *RW, unsigned char Com)
{
    DataToBit(RW[2], 0);                                                                    //设置使能端为0
    DataToBit(RW[0], 0);                                                                    //设置为写命令模式
    DataToBit(RW[1], 0);                                                                    //设置为写入模式
    DataToPort(Port, Com);                                                                //命令写入到指定的端口
    Delay(200);                                                                                      //短暂延时
    DataToBit(RW[2], 1);                                                                     //设置使能端为1
    Delay(200);                                                                                       //短暂延时
    DataToBit(RW[2], 0);                                                                      //将使能端设置为0触发写入
}
