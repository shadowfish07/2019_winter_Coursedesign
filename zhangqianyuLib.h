#ifndef _zhangqianyuLib
#define _zhangqianyuLib

#include "MarkingSystemLib.h"

//读入路径为path的.tk文件并返回存储它的database,若路径下无该文件则返回NULL
database* ReadtkFile(const char* path);
//向一个题库添加题目
// void AddQuestion(char* description,char* alternativeAnswer[4],int rightAnswer,database* toDatabase);
//向一个题库添加题目
void AddQuestionToFileAndList(question newQuestion,database* toDatabase);
//从一个题库中抽取num个题目，返回值为抽到的题目数组,num大于题库题目量时返回NULL
question* GetRandomQuestion(database* fromDatabase,int num);
//读取目录下所有.tk文件并输出
void ReadPathTkFiles();

#endif