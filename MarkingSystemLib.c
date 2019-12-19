#include <stdio.h>
#include "MarkingSystemLib.h"


questionList* InitQuestionList(int max)
{
    question* newQuestion = (question*)malloc(max*sizeof(question));
    questionList* newQuestionList = (questionList*)malloc(sizeof(questionList));
    newQuestionList->questions=newQuestion;
    newQuestionList->max=max;
    newQuestionList->size=0;
    return newQuestionList;
}

void AddToQuestionList(question newQuestion,questionList* toQuestionList)
{
    if (toQuestionList->size==toQuestionList->max)
    {
        //原列表不够大就扩大
        question* tmpQuestions = (question*)malloc(toQuestionList->size*2*sizeof(question));
        int i;
        for(i=0;i<toQuestionList->size;i++)
        {
            tmpQuestions[i]=toQuestionList->questions[i];
        }
        free(toQuestionList->questions);
        toQuestionList->questions = tmpQuestions;
        toQuestionList->max = toQuestionList->size*2;
    }
    toQuestionList->questions[toQuestionList->size++]=newQuestion;
}

databaseList*InitDatabaseList(int max)
{
    databaseList* result = (databaseList*)malloc(sizeof(databaseList));
    database* newDatabase = (database*)malloc(max*sizeof(database));
    newDatabase->questionList=*InitQuestionList(50);
    result->databases=newDatabase;
    result->max=max;
    result->size=0;
    return result;
}

void AddToDatabaseList(database newDatabase,databaseList* toDatabaseList)
{
    if (toDatabaseList->size==toDatabaseList->max)
    {
        //原列表不够大就扩大
        database* tmpDatabases = (database*)malloc(toDatabaseList->size*2*sizeof(database*));
        int i;
        for(i=0;i<toDatabaseList->size;i++)
        {
            tmpDatabases[i]=toDatabaseList->databases[i];
        }
        free(toDatabaseList->databases);
        toDatabaseList->databases = tmpDatabases;
        toDatabaseList->max = toDatabaseList->size*2;
    }
    toDatabaseList->databases[toDatabaseList->size++]=newDatabase;//test
}

void writeQuestion(FILE* file,question* q,int num)
{
    fwrite(q,sizeof(question),num,file);
}

void writeQuestionList(FILE* file,questionList*ql)
{
    fwrite(&ql->size,sizeof(int),1,file);
    fwrite(&ql->max,sizeof(int),1,file);
    writeQuestion(file,ql->questions,ql->size);
}

question* readQuestion(FILE* file,int num)
{
    question* result=(question*)malloc(num*sizeof(question));
    fread(result,sizeof(question),num,file);
    return result;
}

questionList* readQuestionList(FILE* file)
{
    questionList* result =(questionList*)malloc(sizeof(questionList));
    fread(&result->size,sizeof(int),1,file);
    fread(&result->max,sizeof(int),1,file);
    result->questions= readQuestion(file,result->size);
    return result;
}