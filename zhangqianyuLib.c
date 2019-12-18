#include <stdio.h>
#include <stdlib.h>
#include "MarkingSystemLib.h"
#include <time.h>
#include <string.h>

//读入路径为path的.tk文件并返回存储它的database,若路径下无该文件则返回NULL
questionList* ReadtkFile(const char* path)
{
    database* result = (database*)malloc(sizeof(database));
    result->path = path;
    questionList* newQuestionList = (questionList*)malloc(sizeof(questionList));
    FILE* infile = fopen(path,"rb");
    if (fopen == NULL)
    {
        return NULL;
    }
    while (!feof(infile))
    {
        fread(newQuestionList,sizeof(questionList),1,infile);
    }
    fclose(infile);
    return newQuestionList;
}

//向一个题库添加题目
void AddQuestion(char* description,char* alternativeAnswer[4],int rightAnswer,database* toDatabase)
{
    FILE* outfile = fopen(toDatabase->path,"wb");
    if (outfile == NULL)
        exit(1);
    question* newQuestion= (question*)malloc(sizeof(question));
    newQuestion->alternativeAnswer[0] = alternativeAnswer[0];
    newQuestion->alternativeAnswer[1] = alternativeAnswer[1];
    newQuestion->alternativeAnswer[2] = alternativeAnswer[2];
    newQuestion->alternativeAnswer[3] = alternativeAnswer[3];
    newQuestion->description = description;
    newQuestion->rightAnswer = rightAnswer;
    AddToQuestionList(newQuestion,toDatabase->questionList);
    fwrite(toDatabase->questionList,sizeof(questionList),1,outfile);
    fclose(outfile);
}

//从一个题库中抽取num个题目，返回值为抽到的题目数组,num大于题库题目量时返回NULL
question** GetRandomQuestion(database* fromDatabase,int num)
{
    if (num>fromDatabase->questionList->size)
        return NULL;
    question** result = (question**)malloc(num*sizeof(question*));
    srand((unsigned)time(NULL));
    int i;
    int* randnums = (int*)malloc(num*sizeof(int));
    int tmp;
    int j;
    memset(randnums,-1,num);

    for(i=0;i<num;i++)
    {
        tmp=rand()%num;
        for(j=0;j<num;j++)
        {
            if (randnums[j]==tmp)
            {
                tmp=rand()%num;
                j=0;
            }
        }
        randnums[i]=tmp;
    }


    for (i = 0; i < num; i++)
    {
        result[i]=fromDatabase->questionList->questions[randnums[i]];
    }
    
	return result;
}
