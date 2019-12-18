#include <stdio.h>
#include "MarkingSystemLib.h"


questionList InitQuestionList(int max)
{
    question* newQuestion = (question*)malloc(max*sizeof(question));
    questionList* newQuestionList = (questionList*)malloc(sizeof(questionList));
    newQuestionList->questions=newQuestion;
    newQuestionList->max=max;
    newQuestionList->size=0;
    return *newQuestionList;
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

databaseList InitDatabaseList(int max)
{
    database* newDatabase = (database*)malloc(max*sizeof(database));
    databaseList* newDatabaseList = (databaseList*)malloc(sizeof(databaseList));
    newDatabaseList->databases=newDatabase;
    newDatabaseList->max=max;
    newDatabaseList->size=0;
    return *newDatabaseList;
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