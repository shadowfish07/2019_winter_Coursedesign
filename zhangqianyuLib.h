#ifndef _zhangqianyuLib
#define _zhangqianyuLib

#include "MarkingSystemLib.h"

//����·��Ϊpath��.tk�ļ������ش洢����database,��·�����޸��ļ��򷵻�NULL
database* ReadtkFile(const char* path);
//��һ����������Ŀ
// void AddQuestion(char* description,char* alternativeAnswer[4],int rightAnswer,database* toDatabase);
//��һ����������Ŀ
void AddQuestionToFileAndList(question newQuestion,database* toDatabase);
//��һ������г�ȡnum����Ŀ������ֵΪ�鵽����Ŀ����,num���������Ŀ��ʱ����NULL
question* GetRandomQuestion(database* fromDatabase,int num);
//��ȡĿ¼������.tk�ļ������
void ReadPathTkFiles();

#endif