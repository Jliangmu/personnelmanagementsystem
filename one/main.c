#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    long studentid;
    char studentname[15];
    int score[6];
    int totalscore;
}STUDENT;
void one(STUDENT stu[],int studentnum,int classesnum);
void two(STUDENT stu[],int studentnum,int classesnum);
void three(STUDENT stu[],int studentnum,int classesnum);
void four(STUDENT stu[],int studentnum,int jiangxu[]);
void five(STUDENT stu[],int studentnum,int shengxu[]);
void six(STUDENT stu[],int studentnum,int IDshengxu[],int IDscore[]);
void seven(STUDENT stu[],int studentnum);
void eight(STUDENT stu[],int studentnum,int jiangxu[]);
void nine(STUDENT stu[],int studentnum,int jiangxu[]);
void ten(STUDENT stu[],int studentnum,int classesnum);
int main()
{
    int studentnum,classesnum,choice,k;
    int jiangxu[30],shengxu[30],IDscore[30];
    long IDshengxu[30];
    STUDENT stu[30];
    //输入学生人数，考试门数
    printf("Input the number of student:");
    scanf("%d" ,&studentnum);
    printf("Input the number of classes:");
    scanf("%d" ,&classesnum);
    for(k=0;k<20;k++)
    {
        //选择菜单
        printf("--------------------------------------------------------------------------------------\n");
        printf("1.录入每个学生的学号、姓名、各科考试成绩\n");
        printf("2.计算每门课程的总分和平均分\n");
        printf("3.计算每个学生的总分和平均分\n");
        printf("4.按每个学生的总分由高到低排出名次表(注意使用4时请先使用3)\n");
        printf("5.按每个学生的总分由低到高排出名次表(注意使用5时请先使用3)\n");
        printf("6.按学号大小排出成绩表(注意使用6时请先使用3)\n");
        printf("7.按姓名的字典顺序排出成绩表(注意使用7时请先使用3)\n");
        printf("8.按学号查询学生排名及其考试成绩(注意使用8时请先使用3和4)\n");
        printf("9.按姓名查询学生排名及其考试成绩(注意使用9时请先使用3和4)\n");
        printf("10.按优秀、良好、中等、及格、不及格对每门分别统计每个类别的人数所占比例\n");
        printf("11.输出每个学生的学号、姓名、各科考试成绩，以及每门课程的总分和平均分\n");
        printf("12.将每个学生的记录信息写入文件\n");
        printf("13.从文件中读出每个学生的记录信息并显示\n");
        printf("0.退出程序\n");
        printf("Please enter your choice\n");
        scanf("%d" ,&choice);
        printf("--------------------------------------------------------------------------------------\n");
        getchar();
        //选择执行程序
        if(choice==0)
            exit(0);
        else if(choice==1)
            one(stu,studentnum,classesnum);
        else if(choice==2)
            two(stu,studentnum,classesnum);
        else if(choice==3)
            three(stu,studentnum,classesnum);
        else if(choice==4)
            four(stu,studentnum,jiangxu);
        else if(choice==5)
            five(stu,studentnum,shengxu);
        else if(choice==6)
            six(stu,studentnum,IDshengxu,IDscore);
        else if(choice==7)
            seven(stu,studentnum);
        else if(choice==8)
            eight(stu,studentnum,jiangxu);
        else if(choice==9)
            nine(stu,studentnum,jiangxu);
        else if(choice==10)
            ten(stu,studentnum,calssesnum);
    }
    return 0;
}
//第一个小程序
void one(STUDENT stu[],int studentnum,int classesnum)
{
    int i,j;
    for(i=0;i<studentnum;i++)
    {
        printf("Input studentID:");
        scanf("%ld" ,&stu[i].studentid);
        printf("Input studentname:");
        scanf("%s" ,stu[i].studentname);
        printf("Input all scores:");
        for(j=0;j<classesnum;j++)
            scanf("%d" ,&stu[i].score[j]);
    }
}
//第二个小程序
void two(STUDENT stu[],int studentnum,int classesnum)
{
    int i,j,sum=0;
    for(i=0;i<classesnum;i++)
    {
        for(j=0;j<studentnum;j++)
            sum = sum+stu[j].score[i];
        printf("第%d门课程总分%d,第%d门课程平均分%.2f\n" ,i+1,sum,i+1,(float)sum/studentnum);
        sum=0;
    }
}
//第三个小程序
void three(STUDENT stu[],int studentnum,int classesnum)
{
    int i,j,sum=0;
    for(i=0;i<studentnum;i++)
    {
        for(j=0;j<classesnum;j++)
            sum = sum+stu[i].score[j];
        stu[i].totalscore = sum;
        printf("%s课程总分%d,课程平均分%.2f\n" ,stu[i].studentname,sum,(float)sum/studentnum);
        sum=0;
    }
}
//第四个小程序
void four(STUDENT stu[],int studentnum,int jiangxu[])
{
    int i,temp,j;
    for(i=0;i<studentnum;i++)
        jiangxu[i] = stu[i].totalscore;
    for(i=0;i<studentnum-1;i++)
    {
        for(j = i+1;j<studentnum;j++)
        {
            if(jiangxu[j]>jiangxu[i])
            {
                temp = jiangxu[i];
                jiangxu[i] = jiangxu[j];
                jiangxu[j] = temp;
            }
        }
    }
    printf("降序排列成绩：\n");
    for(i=0;i<studentnum;i++)
        printf("第%d:%d\n" ,i+1,jiangxu[i]);
}
//第五个小程序
void five(STUDENT stu[],int studentnum,int shengxu[])
{
    int i,temp,j;
    for(i=0;i<studentnum;i++)
        shengxu[i] = stu[i].totalscore;
    for(i=0;i<studentnum-1;i++)
    {
        for(j = i+1;j<studentnum;j++)
        {
            if(shengxu[j]<shengxu[i])
            {
                temp = shengxu[i];
                shengxu[i] = shengxu[j];
                shengxu[j] = temp;
            }
        }
    }
    printf("升序排列成绩：\n");
    for(i=0;i<studentnum;i++)
        printf("%d\n" ,shengxu[i]);
}
//第六个小程序
void six(STUDENT stu[],int studentnum,int IDshengxu[],int IDscore[])
{
    int i,j,temp;
    for(i=0;i<studentnum;i++)
        IDshengxu[i] = stu[i].studentid;
    for(i=0;i<studentnum;i++)
        IDscore[i] = stu[i].totalscore;
    for(i=0;i<studentnum-1;i++)
    {
        for(j = i+1;j<studentnum;j++)
        {
            if(IDshengxu[i]>IDshengxu[j])
            {
                temp = IDshengxu[i];
                IDshengxu[i] = IDshengxu[j];
                IDshengxu[j] = temp;
                temp = IDscore[i];
                IDscore[i] = IDscore[j];
                IDscore[j] = temp;
            }
        }
    }
    for(i=0;i<studentnum;i++)
        printf("学号：%ld,成绩：%d\n" ,IDshengxu[i],IDscore[i]);
}
//第七个小程序
void seven(STUDENT stu[],int studentnum)
{
    char temp[15];
    int i,j,s,temp1;
    for(i=0;i<studentnum-1;i++)
    {
        for(j=i+1;j<studentnum;j++)
        {
            s = strcmp(stu[i].studentname , stu[j].studentname);
            if(s>0)
            {
                strcpy(temp , stu[i].studentname);
                strcpy(stu[i].studentname , stu[j].studentname);
                strcpy(stu[j].studentname , temp);
                temp1 = stu[i].totalscore;
                stu[i].totalscore = stu[j].totalscore;
                stu[j].totalscore = temp1;
            }
        }
    }
    for(i=0;i<studentnum;i++)
        printf("%s的成绩%d\n" ,stu[i].studentname,stu[i].totalscore);
}
//第八个小程序
void eight(STUDENT stu[],int studentnum,int jiangxu[])
{
    int i,a=0,j;
    long IDsearch;
    printf("请输入要查找的学号");
    scanf("%ld" ,&IDsearch);
    getchar();
    for(i=0;i<studentnum;i++)
    {
        if(IDsearch == stu[i].studentid)
        {
            a = 1;
            for(j=0;j<studentnum;j++)
            {
                if(stu[i].totalscore == jiangxu[j])
                {
                    printf("学号：%ld,成绩：%d,排名：%d\n" ,IDsearch,stu[i].totalscore,j+1);
                    break;
                }
            }
            break;
        }
    }
    if(a==0)
        printf("对不起，未查到此人\n");
}
//第九个小程序
void nine(STUDENT stu[],int studentnum,int jiangxu[])
{
    int i,result,a=0,j;
    char temp[15];
    printf("请输入要查找的姓名");
    gets(temp);
    for(i=0;i<studentnum;i++)
    {
        result = strcmp(temp,stu[i].studentname);
        if(result==0)
        {
            a = 1;
            for(j=0;j<studentnum;j++)
            {
                if(stu[i].totalscore == jiangxu[j])
                {
                    printf("%s的成绩：%d,排名：%d\n" ,temp,stu[i].totalscore,j+1);
                    break;
                }
            }
            break;
        }
    }
    if(a==0)
        printf("对不起，未查到此人\n");
}
//第十个小程序
void ten

