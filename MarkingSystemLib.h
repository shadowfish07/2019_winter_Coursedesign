#ifndef _markingSystemLib
#define _markingSystemLib


typedef struct 
{
    char* descripsion;
    char* alternativeAnswer[4];
    int rightAnswer;
}question;

typedef struct 
{
    question** questions;
    int size;
    int max;
}questionList;

typedef struct 
{
    char* path;
    questionList* questionList;
}database;



questionList* InitQuestionList(int max);
void AddToQuestionList(question* newQuestion,questionList* toQuestionList);

#endif