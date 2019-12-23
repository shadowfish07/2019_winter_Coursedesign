#ifndef _maoxiaoyu
#define _maoxiaoyu

#include "MarkingSystemLib.h"

//检测传入的文件后缀是否为".tk",是返回1，否返回0.
int IstkFile(const char*s);
//返回一个问题的输出字符串（用于主程序输出）。
void PrintQuestion(const question*fromQuestion);
void PrintalternativeAnswer(char**p,int n);//用于上函数
//在当前目录下新建一个空的.tk文件。
void AddTkFile(char*name);

#endif
