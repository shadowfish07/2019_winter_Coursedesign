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
        printf("������Ҫ�½��������\n>");
        scanf("%s",inputFileName);
    }
    AddTkFile(inputFileName);//TODO��д��ɹ����

    database* newDatabase=(database*)malloc(sizeof(database));
    newDatabase->path=(char*)malloc(256*sizeof(char));
    strcpy(newDatabase->path,inputFileName);
    strcat(newDatabase->path,".tk");
    newDatabase->questionList=*InitQuestionList(50);
    AddToDatabaseList(*newDatabase,&databases);

    printf("�ɹ��½�%s��� admin.tk\n�Զ��������༭ϵͳ\n",isAdmin?"Ĭ��":"");
    AddQuestionSystem();
}

void AddQuestionSystem()
{
    printf("------------���༭ϵͳ------------\n");
    while(1)
    {
        question* newQuestion =(question*)malloc(sizeof(question));
        printf("��ǰ�༭��⣺%s\n",databases.databases[currentDatabase].path);
        printf("��ǰ�����Ŀ������%d\n",databases.databases[currentDatabase].questionList.size);
        printf("---�½���Ŀ---\n");
        printf("���������\n>");
        scanf("%s",newQuestion->description);
        printf("������ѡ��A\n>");
        scanf("%s",newQuestion->alternativeAnswer[0]);
        printf("������ѡ��B\n>");
        scanf("%s",newQuestion->alternativeAnswer[1]);
        printf("������ѡ��C\n>");
        scanf("%s",newQuestion->alternativeAnswer[2]);
        printf("������ѡ��D\n>");
        scanf("%s",newQuestion->alternativeAnswer[3]);
        printf("��������ȷ��(0->A 1->B 2->C 3->D\n>");
        scanf("%d",&newQuestion->rightAnswer);
        printf("��Ŀ�������\n");
        AddQuestionToFileAndList(*newQuestion,&databases.databases[currentDatabase]);
        printf("�Ƿ�������룿�����->�� N->��\n>");
        char ch;
        getchar();
        scanf("%c",&ch);
        if(ch=='N')
            break;
    }
    printf("----------�˳����༭ϵͳ----------");
}

int main()
{
    printf("��ӭʹ�� ����ѡ�����׼������ϵͳ\n");
    printf("����ɨ�����...\n");
    databases= *InitDatabaseList(10);
    ReadPathTkFiles();
    if(databases.size==0)
    {
        CreatNewQuestionSystem(1);
    }
    //��ӡ����б�
    while(1)
    {
        printf("��ѡ�񽫽��еĲ���\n");
        printf("1.���д���\n");
        printf("2.¼�����\n");
        printf("3.���������\n");
        printf("4.�˳�����\n");
        printf(">");
        int inputWay;
        scanf("%d",&inputWay);
        if(inputWay==1)
        {
            printf("--------------����ϵͳ--------------\n");
            while(1)
            {
                int grade=0;
                printf("��ǰ��⣺%s\n",databases.databases[currentDatabase].path);
                printf("��������%d\n",databases.databases[currentDatabase].questionList.size);
                printf("����������������:\n>");
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
                        printf("�����ʽ��������������\n>");
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
                printf("��Ŀ��ȡ���\n");
                printf("�÷֣�%d\n",grade);
                printf("�Ƿ����³��⣿�����-�ǣ�N-��\n>");
                char inputC;
                getchar();
                scanf("%c",&inputC);
                if(inputC=='N'||inputC=='n')
                {
                    printf("------------�˳�����ϵͳ------------\n");
                    break;
                }
            }
            
        }
        else if(inputWay==2)
        {
            printf("������Ҫ�༭��������\n>");
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
