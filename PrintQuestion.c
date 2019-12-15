#include<stdio.h>
#include<string.h>
#include "MarkingSystemLib.h"
void PrintalternativeAnswer(char**p,int n);
void PrintQuestoion(const question*fromQuestion)
{
	puts(fromQuestion->description);
	printf("\n");
	PrintalternativeAnswer(fromQuestion->alternativeAnswer,4);

}
void PrintalternativeAnswer(char**p,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%s\n",p[i]);
}