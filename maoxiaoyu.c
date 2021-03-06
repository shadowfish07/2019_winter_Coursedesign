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
	printf("%d、",Index);
	puts(fromQuestion.description);
	printf("A、%s\n",fromQuestion.alternativeAnswer[0]);
	printf("B、%s\n",fromQuestion.alternativeAnswer[1]);
	printf("C、%s\n",fromQuestion.alternativeAnswer[2]);
	printf("D、%s\n",fromQuestion.alternativeAnswer[3]);
}


//在当前目录下新建一个空的.tk文件。
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


//输入一个带.tk后缀的文件名，输出去掉.tk后的文件名。（仅返回一个去掉.tk后的文件名的字符串指针，不带输出功能）
char*RemoveTK(char*str)
{
	char*p;
	strcpy(p,str);
	int i;
	i=strlen(p);
	while(p[i]!='.')
		i--;
	if(p[i+1]!='t'&&p[i+2]!='k')
	{
		return p;
	}
	else
	{
		p[i]='\0'; 
	    return p;
	}
  
}


//输入一个字符和一个合法字符列表，判断该字符是否在这个字符列表内，若在返回1，不在返回0.
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