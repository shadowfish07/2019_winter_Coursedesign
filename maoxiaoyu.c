#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "MarkingSystemLib.h"


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
void PrintQuestion(const question fromQuestion,int Index)
{
	int i;
	printf("%d��",Index);
	puts(fromQuestion.description);
	printf("A��%s\n",fromQuestion.alternativeAnswer[0]);
	printf("B��%s\n",fromQuestion.alternativeAnswer[1]);
	printf("C��%s\n",fromQuestion.alternativeAnswer[2]);
	printf("D��%s\n",fromQuestion.alternativeAnswer[3]);
}


//�ڵ�ǰĿ¼���½�һ���յ�.tk�ļ���
void AddTkFile(char*name)
{
	FILE*fp;
	char fileName[100]={0};
	strcat(fileName,name);
	strcat(fileName,".tk");
	fp=fopen(fileName,"w");
	if(!fp)
	{
		printf("can't open file %s\n",fileName);
		exit(1);
	}
	fclose(fp);
}


//����һ����.tk��׺���ļ��������ȥ��.tk����ļ�������������һ��ȥ��.tk����ļ������ַ���ָ�룬����������ܣ�
char*RemoveTK(char*str)
{
	int i;
	i=strlen(str);
	while(str[i]!='.')
		i--;
	if(str[i+1]!='t'&&str[i+2]!='k')
	{
		return str;
	}
	else
	{
		str[i]='\0'; 
	    return str;
	}
  
}


int IsLegalInput(char input,char legalInputs[])
{
	while(*legalInputs!='\0')
	{
		if(*legalInputs==input)
			return 1;
		legalInputs++;
	}
	return 0;
}