#include<stdio.h>
#include<string.h>
int IstkFile(const char*s)
{
	char*pFile;
	pFile=strrchr(s,'.');
	printf("%s\n",pFile);
		if(strcmp(pFile,".tk")==0)
			return 1;
		else
			return 9;
}

