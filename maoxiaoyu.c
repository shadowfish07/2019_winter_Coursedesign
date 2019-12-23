#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "MarkingSystemLib.h"
//void PrintalternativeAnswer(char**p,int n);

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
void PrintQuestion(const question*fromQuestion)
{
	int i;
	puts(fromQuestion->description);
	printf("\n");
	//PrintalternativeAnswer(fromQuestion->alternativeAnswer,4);
	for(i=0;i<4;i++)
		printf("%s\n",fromQuestion->alternativeAnswer[i]);
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
