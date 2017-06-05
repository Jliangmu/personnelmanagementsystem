#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void password();//欢迎语句，输入密码。
void hello();//开始界面

typedef struct personnelArchiveInfo{
    char num[10];
    char name[10];
    char sex[5];
    int age;
    char job[10];
    char post[10];
    char politic[10];
    char edu_level[10];
    char period[10];
    char start_time[10];
}PAInfo;

struct link{
    PAInfo data;
    struct link *next;
};

struct link *AppendNode(struct link *head);//添加一条数据
void DisplyNode(struct link *head);
void DeleteMemory(struct link *head);//释放内存
void Inputdata();

/*数据输入模块*/



int main()
{
    int se;
    //password();
    hello();
    printf("请输入序号\n");
    scanf("%d",&se);
    getchar();
    if(se == 1){
        Inputdata();
    }
    return 0;
}

void password(){
    printf("Hello!\n");
    printf("welcome to use the personal management system!\n");
    char password[11] = {"jiangkaida"};
    char s[11];
    int flag = 0;
    int n = 3;
    int i,m;
    do{
        printf("please input your password:\n");
        for(m = 0;m < 10;m++){
            s[m] = getch();
            putchar('*');
        }
        s[m] = '\0';
        printf("\n");
        if((!strcmp(s,password))){
            printf("land successfully!\n");
            flag = 1;
            break;

        }
        else{
            printf("error!please input again!\n");
            n--;
        }
    }while(n>0);
    if(!flag){
        printf("Input error more than three times!");
        exit(0);
    }
}

void hello(){
    printf("* * * * * * * * * * * * * * * * * * * \n");
    printf("*      欢迎使用人事管理系统！       * \n");
    printf("*     请输入功能序号进行使用！      * \n");
    printf("*\t1.新建员工信息              * \n");
    printf("*\t2.添加员工信息              * \n");
    printf("*\t3.删除员工信息              * \n");
    printf("*\t4.查询员工信息              * \n");
    printf("*\t5.修改员工信息              * \n");
    printf("*\t6.对信息进行排序            * \n");
    printf("*\t7.统计员工信息              * \n");
    printf("* * * * * * * * * * * * * * * * * * * \n");
}

void Inputdata(){
    struct link *head = NULL;
    char c;
    int i = 0;
    printf("您想要新建一个员工数据吗(Y/N)?");
    scanf(" %c",&c);
    while(c == 'Y' || c == 'y'){
        head = AppendNode(head);
        printf("您想要再新建一个员工数据吗(Y/N)?");
            scanf(" %c",&c);
            i++;
    }
    while(getchar()!='\n');
    printf("您成功新建了 %d 个员工数据,是否需要显示详细信息？\n",i);
    scanf(" %c",&c);
    while(c == 'y' || c == 'Y'){
    DisplyNode(head);
    }
}

struct link *AppendNode(struct link *head){
    struct link *p = NULL, *pr = head;
    PAInfo data;
    p = (struct link *)malloc(sizeof(struct link));
    if(p == NULL){
        printf("内存不足！");
        exit(0);
    }
    if(head ==NULL){
        head = p;
    }
    else{
        while(pr->next!=NULL){
            pr = pr ->next;
        }
    }
    printf("请输入员工的详细信息\n");
    printf("输入编号：");
    scanf("%s",data.num);
    printf("输入姓名：");
    scanf("%s",data.name);
    printf("输入性别：");
    scanf("%s",data.sex);
    printf("输入年龄：");
    scanf("%d",&data.age);
    printf("输入职务：");
    scanf("%s",data.job);
    printf("输入职称：");
    scanf("%s",data.post);
    printf("输入政治面貌：");
    scanf("%s",data.politic);
    printf("输入最高学历：");
    scanf("%s",data.edu_level);
    printf("输入任职时间：");
    scanf("%s",data.period);
    printf("输入来院时间：");
    scanf("%s",data.start_time);
    p->data = data;
    p->next = NULL;
    return head;
}

void DisplyNode(struct link *head){
    struct link *p = head;
    int j = 1;
    while(p!= NULL){
        printf("--------第 %d 个员工信息--------",j);
        printf("|\t姓名：%s            \n",p->data.name);
        printf("|\t编号：%s            \n",p->data.num);
        printf("|\t性别：%s            \n",p->data.sex);
        printf("|\t年龄：%d            \n",p->data.age);
        printf("|\t职务：%s            \n",p->data.job);
        printf("|\t职称：%s            \n",p->data.post);
        printf("|\t政治面貌：%s",p->data.politic);
        printf("|\t最高学历：%s",p->data.edu_level);
        printf("|\t任职时间：%s",p->data.period);
        printf("|\t来院时间：%s",p->data.start_time);
        printf("--------------------------------");
        p = p->next;
        j++;
    }
}


