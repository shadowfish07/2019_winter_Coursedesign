#include <stdio.h>
#include "MarkingSystemLib.h"

questionList* InitQuestionList(int max)
{
    question** newQuestion = (question**)malloc(max*sizeof(question));
    questionList* newQuestionList = (questionList*)malloc(sizeof(questionList));
    newQuestionList->questions=newQuestion;
    newQuestionList->max=max;
    newQuestionList->size=0;
    return newQuestionList;
}

void AddToQuestionList(question* newQuestion,questionList* toQuestionList)
{
    if (toQuestionList->size==toQuestionList->max)
    {
        //原列表不够大就扩大
        question** tmpQuestions = (question**)malloc(toQuestionList->max*2*sizeof(question));
        int i;
        for(i=0;i<toQuestionList->size;i++)
        {
            tmpQuestions[i]=toQuestionList->questions[i];
        }
        free(toQuestionList->questions);
        toQuestionList->questions = tmpQuestions;
        toQuestionList->max = toQuestionList->max*2;
    }
    toQuestionList->questions[toQuestionList->size++]=newQuestion;//test
}
