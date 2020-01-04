#include <stdio.h>
#include <stdlib.h>
#include "MarkingSystemLib.h"
#include <time.h>
#include <string.h>
#include <io.h>
#include "zhangqianyuLib.h"
#include "maoxiaoyu.h"

extern databaseList databases;
//����·��Ϊpath��.tk�ļ������ش洢����database,��·�����޸��ļ��򷵻�NULL
database* ReadtkFile(const char* path)
{
    FILE* infile = fopen(path,"rb");
    if (infile == NULL)
    {
        return NULL;
    }
    database* result = (database*)malloc(sizeof(database));
    result->path=(char*)malloc(256*sizeof(char));
    strcpy(result->path,path);
    result->questionList=*readQuestionList(infile);
    fclose(infile);
    return result;
}

//��һ����������Ŀ
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

//��һ������ļ������Ŀ
void AddQuestionToFileAndList(question newQuestion,database* toDatabase)
{
    FILE* outfile = fopen(toDatabase->path,"wb+");
    if (outfile == NULL)
        exit(1);
    AddToQuestionList(newQuestion,&toDatabase->questionList);
    writeQuestionList(outfile,&toDatabase->questionList);
    fclose(outfile);
}


int isIn(int in,int arr[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(in==arr[i])
        {
            return 1;
        }
    }
    return 0;
}

//��һ������г�ȡnum����Ŀ������ֵΪ�鵽����Ŀ����,num���������Ŀ��ʱ����NULL
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
    for(i=0;i<num;i++)
    {
        randnums[i]=-1;
    }
    for(i=0;i<num;i++)
    {

        tmp=rand()%num;
        while(isIn(tmp,randnums,num))
        {
            tmp=rand()%num;
        }
        randnums[i]=tmp;
    }


    for (i = 0; i < num; i++)
    {
        result[i]=fromDatabase->questionList.questions[randnums[i]];
    }
    
	return result;
}

//��ȡĿ¼������.tk�ļ������
void ReadPathTkFiles()
{

    char* filepath = "*.tk";
    struct _finddata_t fileinfo;
    long handle;
    handle=_findfirst(filepath,&fileinfo);
    int done;
    if(handle==-1)
    {
        printf("��ǰĿ¼�����κ����\n");
        return;
    }
    printf("----����б�----\n");
    printf("���\t�ļ���\n");
    do
    {
        FILE* tkFile =fopen(fileinfo.name,"rb");
        database* newDatabase=ReadtkFile(fileinfo.name);
        AddToDatabaseList(*newDatabase,&databases);
        fclose(tkFile);
        printf("%d\t%s\n",databases.size,fileinfo.name);
    }while(!_findnext(handle,&fileinfo));
    _findclose(handle);
    printf("--����������--\n");
}

