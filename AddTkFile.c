#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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