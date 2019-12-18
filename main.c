#include <stdio.h>

#include "MarkingSystemLib.h"
#include "zhangqianyuLib.h"
#include "AddTkFile.h"

int currentDatabase=0;
databaseList databases;

void AddQuestionSystem()
{
    printf("------------题库编辑系统------------\n");
    while(1)
    {
        question* newQuestion = InitQuestion();
        printf("当前编辑题库：%s\n",databases.databases[currentDatabase].path);
        printf("当前题库题目总数：%d\n",databases.databases[currentDatabase].questionList.size);
        printf("---新建题目---\n");
        printf("请输入题干\n");
        scanf("%s",newQuestion->description);
        printf("请输入选项A\n");
        scanf("%s",newQuestion->alternativeAnswer[0]);
        printf("请输入选项B\n");
        scanf("%s",newQuestion->alternativeAnswer[1]);
        printf("请输入选项C\n");
        scanf("%s",newQuestion->alternativeAnswer[2]);
        printf("请输入选项D\n");
        scanf("%s",newQuestion->alternativeAnswer[3]);
        printf("请输入正确答案(0->A 1->B 2->C 3->D\n");
        scanf("%d",&newQuestion->rightAnswer);
        printf("题目导入完成\n");
        AddQuestionToFile(newQuestion,databases.databases[currentDatabase]);
        printf("是否继续导入？Y->是 N->否\n");
        char ch;
        getchar();
        scanf("%c",&ch);
        if(ch=='N')
            break;
    }
    printf("----------退出题库编辑系统----------");
}

int main()
{
    printf("欢迎使用 单项选择题标准化考试系统\n");
    printf("正在扫描题库...\n");
    databases= InitDatabaseList(10);
    ReadPathTkFiles();
    if(databases.size==1)
    {
        printf("%s\n",databases.databases[0].path);
        printf("%s\n",databases.databases[0].questionList.questions[0].description);
        printf("%s\n",databases.databases[0].questionList.questions[0].alternativeAnswer[0]);
        printf("%d\n",databases.databases[0].questionList.questions[0].rightAnswer);
    }
    else if(databases.size==0)
    {
        AddTkFile("admin");
        printf("成功新建题库 admin.tk\n自动进入题库编辑系统\n");
        database* newDatabase=(database*)malloc(sizeof(database));
        newDatabase->path="admin.tk";
        newDatabase->questionList=InitQuestionList(50);
        AddToDatabaseList(*newDatabase,&databases);
        AddQuestionSystem();
    }
    
    else
    {
        //选择题库

    }
    
}