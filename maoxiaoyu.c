#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "MarkingSystemLib.h"


//检测传入的文件后缀是否为".tk",是返回1，否返回0.
int IstkFile(const char*s)
{
	char*pFile;
	pFile=strrchr(s,'.');
		if(strcmp(pFile,".tk")==0)
			return 1;
		else
			return 0;
}


//返回一个问题的输出字符串（用于主程序输出）。
void PrintQuestion(const question fromQuestion,int Index)
{
	int i;
	printf("%d��",Index);
	puts(fromQuestion.description);
	printf("\n");
	for(i=0;i<4;i++)
		printf("%s\n",fromQuestion.alternativeAnswer[i]);
}


//在当前目录下新建一个空的.tk文件。
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


//输入一个带.tk后缀的文件名，输出去掉.tk后的文件名。（仅返回一个去掉.tk后的文件名的字符串指针，不带输出功能）
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


//����һ���ַ���һ���Ϸ��ַ��б����жϸ��ַ��Ƿ�������ַ��б��ڣ����ڷ���1�����ڷ���0.
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