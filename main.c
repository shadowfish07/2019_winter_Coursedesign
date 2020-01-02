#include <stdio.h>
#include <string.h>
#include "MarkingSystemLib.h"
#include "zhangqianyuLib.h"
#include "maoxiaoyu.h"

int currentDatabase=0;
databaseList databases;

void CreatNewQuestionSystem(int isAdmin)
{
    char* inputFileName=(char*)malloc(256*sizeof(char));
    if(isAdmin)
    {
        strcpy(inputFileName,"admin");
    }
    else
    {
        printf("请输入要新建的题库名\n>");
        scanf("%s",inputFileName);
    }
    AddTkFile(inputFileName);//TODO：写入成功检测

    database* newDatabase=(database*)malloc(sizeof(database));
    newDatabase->path=(char*)malloc(256*sizeof(char));
    strcpy(newDatabase->path,inputFileName);
    strcat(newDatabase->path,".tk");
    newDatabase->questionList=*InitQuestionList(50);
    AddToDatabaseList(*newDatabase,&databases);

    printf("成功新建%s题库 admin.tk\n自动进入题库编辑系统\n",isAdmin?"默认":"");
    AddQuestionSystem();
}

void AddQuestionSystem()
{
    printf("------------题库编辑系统------------\n");
    while(1)
    {
        question* newQuestion =(question*)malloc(sizeof(question));
        printf("当前编辑题库：%s\n",databases.databases[currentDatabase].path);
        printf("当前题库题目总数：%d\n",databases.databases[currentDatabase].questionList.size);
        printf("---新建题目---\n");
        printf("请输入题干\n>");
        getchar();
        gets(newQuestion->description);
        printf("请输入选项A\n>");
        gets(newQuestion->alternativeAnswer[0]);
        printf("请输入选项B\n>");
        gets(newQuestion->alternativeAnswer[1]);
        printf("请输入选项C\n>");
        gets(newQuestion->alternativeAnswer[2]);
        printf("请输入选项D\n>");
        gets(newQuestion->alternativeAnswer[3]);
        printf("请输入正确答案(0->A 1->B 2->C 3->D\n>");
        scanf("%d",&newQuestion->rightAnswer);
        printf("题目导入完成\n");
        AddQuestionToFileAndList(*newQuestion,&databases.databases[currentDatabase]);
        printf("是否继续导入？任意键->是 N->否\n>");
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
    databases= *InitDatabaseList(10);
    ReadPathTkFiles();
    if(databases.size==0)
    {
        CreatNewQuestionSystem(1);
    }
    //打印题库列表
    while(1)
    {
        printf("请选择将进行的操作\n");
        printf("1.进行答题\n");
        printf("2.录入题库\n");
        printf("3.创建新题库\n");
        printf("4.退出程序\n");
        printf(">");
        int inputWay;
        scanf("%d",&inputWay);
        if(inputWay==1)
        {
            printf("--------------答题系统--------------\n");
            while(1)
            {
                int grade=0;
                printf("当前题库：%s\n",databases.databases[currentDatabase].path);
                printf("总题数：%d\n",databases.databases[currentDatabase].questionList.size);
                printf("请输入欲抽题题数:\n>");
                int randNum;
                while(1)
                {
                    scanf("%d",&randNum);
                    if(randNum<=databases.databases[currentDatabase].questionList.size&&randNum>0)
                    {
                        break;
                    }
                    else
                    {
                        printf("输入格式错误，请重新输入\n>");
                    }
                    
                }
                question* RandQuestions=(question*)malloc(randNum*sizeof(question));
                RandQuestions=GetRandomQuestion(&databases.databases[currentDatabase],randNum);
                int currentQ=0;
                while(randNum--)
                {
                    PrintQuestion(RandQuestions[currentQ],currentQ+1);
                    printf(">");
                    char inputA;
                    getchar();
                    scanf("%c",&inputA);
                    if(inputA=='A'+RandQuestions[currentQ].rightAnswer||inputA=='a'+RandQuestions[currentQ].rightAnswer)
                        grade++;
                    currentQ++;
                }
                printf("题目抽取完毕\n");
                printf("得分：%d\n",grade);
                printf("是否重新抽题？任意键-是，N-否\n>");
                char inputC;
                getchar();
                scanf("%c",&inputC);
                if(inputC=='N'||inputC=='n')
                {
                    printf("------------退出答题系统------------\n");
                    break;
                }
            }
            
        }
        else if(inputWay==2)
        {
            printf("请输入要编辑的题库序号\n>");
            int inputIndex;
            scanf("%d",&inputIndex);
            currentDatabase=inputIndex-1;
            AddQuestionSystem();
        }
        else if(inputWay==3)
        {
            CreatNewQuestionSystem(0);
        }
        else if(inputWay==4)
        {
            return 0;
        }
        
    }
            
            
            
    
}
