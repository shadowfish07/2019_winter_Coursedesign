#ifndef _maoxiaoyu
#define _maoxiaoyu

#include "MarkingSystemLib.h"

//��⴫����ļ���׺�Ƿ�Ϊ".tk",�Ƿ���1���񷵻�0.
int IstkFile(const char*s);
//����һ�����������ַ����������������������
void PrintQuestion(const question fromQuestion,int Index);
//�ڵ�ǰĿ¼���½�һ���յ�.tk�ļ���
void AddTkFile(char*name);
//����һ����.tk��׺���ļ��������ȥ��.tk����ļ�������������һ��ȥ��.tk����ļ������ַ���ָ�룬����������ܣ�
char*RemoveTK(char*str);

#endif
