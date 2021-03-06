#ifndef _maoxiaoyu
#define _maoxiaoyu

#include "MarkingSystemLib.h"

//检测传入的文件后缀是否为".tk",是返回1，否返回0.
int IstkFile(const char*s);
//返回一个问题的输出字符串（用于主程序输出）。
void PrintQuestion(const question fromQuestion,int Index);
//在当前目录下新建一个空的.tk文件。
void AddTkFile(char*name);
//输入一个带.tk后缀的文件名，输出去掉.tk后的文件名。（仅返回一个去掉.tk后的文件名的字符串指针，不带输出功能）
char*RemoveTK(char*str);
//输入一个字符和一个合法字符列表，判断该字符是否在这个字符列表内，若在返回1，不在返回0.
int IsLegalInput(char input,char legalInputs[]);

#endif
