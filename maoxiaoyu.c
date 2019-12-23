#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "MarkingSystemLib.h"
//void PrintalternativeAnswer(char**p,int n);

//��⴫����ļ���׺�Ƿ�Ϊ".tk",�Ƿ���1���񷵻�0.
int IstkFile(const char*s)
{
	char*pFile;
	pFile=strrchr(s,'.');
		if(strcmp(pFile,".tk")==0)
			return 1;
		else
			return 0;
}

//����һ�����������ַ����������������������
void PrintQuestion(const question*fromQuestion)
{
	int i;
	puts(fromQuestion->description);
	printf("\n");
	//PrintalternativeAnswer(fromQuestion->alternativeAnswer,4);
	for(i=0;i<4;i++)
		printf("%s\n",fromQuestion->alternativeAnswer[i]);
}

//�ڵ�ǰĿ¼���½�һ���յ�.tk�ļ���
void AddTkFile(char*name)
{
	FILE*fp;
	char fileName[100]={0};
	strcpy(fileName,"C:\\");
	strcat(fileName,name);
	strcat(fileName,".tk");
	fp=fopen(fileName,"w+");
	if(!fp)
	{
		printf("can't open file %s\n",fileName);
		exit(1);
	}
	fclose(fp);
}
