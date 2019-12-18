#include <stdio.h>
#include <stdlib.h>
#include "MarkingSystemLib.h"
#include <time.h>
#include <string.h>
#include <io.h>
#include "zhangqianyuLib.h"
#include "IstkFile.h"

extern databaseList* databases;
//读入路径为path的.tk文件并返回存储它的database,若路径下无该文件则返回NULL
database* ReadtkFile(const char* path)
{
    FILE* infile = fopen(path,"rb");
    if (infile == NULL)
    {
        return NULL;
    }
    database* result = (database*)malloc(sizeof(database));
    result->path = path;
    result->questionList=*readQuestionList(infile);
    fclose(infile);
    return result;
}

//向一个题库添加题目
// void AddQuestion(char* description,char* alternativeAnswer[4],int rightAnswer,database* toDatabase)
// {
//     FILE* outfile = fopen(toDatabase->path,"wb");
//     if (outfile == NULL)
//         exit(1);
//     question* newQuestion= (question*)malloc(sizeof(question));
//     newQuestion->alternativeAnswer[0] = alternativeAnswer[0];
//     newQuestion->alternativeAnswer[1] = alternativeAnswer[1];
//     newQuestion->alternativeAnswer[2] = alternativeAnswer[2];
//     newQuestion->alternativeAnswer[3] = alternativeAnswer[3];
//     newQuestion->description = description;
//     newQuestion->rightAnswer = rightAnswer;
//     AddToQuestionList(newQuestion,toDatabase->questionList);
//     fwrite(toDatabase->questionList,sizeof(questionList),1,outfile);
//     fclose(outfile);
// }

//向一个题库文件添加题目
void AddQuestionToFileAndList(question newQuestion,database* toDatabase)
{
    FILE* outfile = fopen(toDatabase->path,"wb");
    if (outfile == NULL)
        exit(1);
    AddToQuestionList(newQuestion,&toDatabase->questionList);
    fwrite(&toDatabase->questionList,sizeof(questionList),1,outfile);
    for(int i=0;i<toDatabase->questionList.size;i++)
    {
        fwrite(&(toDatabase->questionList.questions[i]),sizeof(question),1,outfile);
    }
    fclose(outfile);
}

//从一个题库中抽取num个题目，返回值为抽到的题目数组,num大于题库题目量时返回NULL
question* GetRandomQuestion(database* fromDatabase,int num)
{
    if (num>fromDatabase->questionList.size)
        return NULL;
    question* result = (question*)malloc(num*sizeof(question));
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
        result[i]=fromDatabase->questionList.questions[randnums[i]];
    }
    
	return result;
}

//读取目录下所有.tk文件并输出
void ReadPathTkFiles()
{
    char* filepath = "*.tk";
    struct _finddata_t fileinfo;
    long handle;
    handle=_findfirst(filepath,&fileinfo);
    int done;
    if(handle==-1)
    {
        printf("当前目录下无任何题库\n");
        return;
    }
    do
    {
        FILE* tkFile =fopen(fileinfo.name,"rb");
        database* newDatabase=ReadtkFile(fileinfo.name);
        AddToDatabaseList(*newDatabase,databases);
        fclose(tkFile);
    }while(!_findnext(handle,&fileinfo));
    _findclose(handle);
}

