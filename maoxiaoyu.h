#ifndef _maoxiaoyu
#define _maoxiaoyu

#include "MarkingSystemLib.h"

//��⴫����ļ���׺�Ƿ�Ϊ".tk",�Ƿ���1���񷵻�0.
int IstkFile(const char*s);
//����һ�����������ַ����������������������
void PrintQuestion(const question*fromQuestion);
void PrintalternativeAnswer(char**p,int n);//�����Ϻ���
//�ڵ�ǰĿ¼���½�һ���յ�.tk�ļ���
void AddTkFile(char*name);

#endif
