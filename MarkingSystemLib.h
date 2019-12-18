#ifndef _markingSystemLib
#define _markingSystemLib


typedef struct 
{
    char description[1024];
    char alternativeAnswer[4][256];
    int rightAnswer;
}question;

typedef struct 
{
    question* questions;
    int size;
    int max;
}questionList;

typedef struct 
{
    char* path;//Ïà¶ÔÂ·¾¶
    questionList questionList;
}database;

typedef struct 
{
    database* databases;
    int size;
    int max;
}databaseList;

questionList* InitQuestionList(int max);
void AddToQuestionList(question newQuestion,questionList* toQuestionList);

databaseList* InitDatabaseList(int max);
void AddToDatabaseList(database newDatabase,databaseList* toDatabaseList);

//void writeQuestion(FILE* file,question* q,int num);
void writeQuestionList(FILE* file,questionList*ql);
questionList* readQuestionList(FILE* file);
//question* readQuestion(FILE* file,int num);

#endif