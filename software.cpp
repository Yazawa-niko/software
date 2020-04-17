#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;


struct PhoneName{
    char name[20];
    char phonenum[100];
    int num;
    char address[100];
    PhoneName *next;
};
void menu(){
    cout<<"                         通讯录功能操作       "<<endl;
    cout<<"                  +--------------------------+"<<endl;
    cout<<"                  +         1.添加           +"<<endl;
    cout<<"                  +         2.查找           +"<<endl;
    cout<<"                  +         3.修改           +"<<endl;
    cout<<"                  +         4.删除           +"<<endl;
    cout<<"                  +         5.浏览           +"<<endl;
    cout<<"                  +         0.关于           +"<<endl;
    cout<<"                  +--------------------------+"<<endl;
    cout<<"请输入你的操作: ";
}
void print(PhoneName *head){
    PhoneName *p=NULL;
    p=head;
    printf("联系人数：%d\n",head->num);
    p=p->next;
    cout<<"姓名\t\t电话\t\t\t地址\n";
    if(head!=NULL){
        do{

            printf("%s",p->name);
            printf("\t\t%s",p->phonenum);
            printf("\t\t%s\n",p->address);
            p=p->next;
        }while(p!=NULL);
    }
}
struct PhoneName*create1(){
    int i,k;
    struct PhoneName *p1,*p2,*head;
    head=NULL;
    head=p1=p2=new(PhoneName);
    FILE *in=fopen("通讯录.txt","r");
    fscanf(in,"%d",&k);
    p1->num=k;//头节点用来存联系人数
    p2->next=p1;
    p2=p1;
    for(i=0;i<k;i++){
        p1=new(PhoneName);
        /*cout<<"\n请输入姓名：";*/
        fscanf(in,"%s",p1->name);
       /* cout<<"\n请输入电话：";*/
        fscanf(in,"%s",p1->phonenum);
        /*cout<<"\n请输入地址：";*/
        fscanf(in,"%s",p1->address);
        p2->next=p1;
        p2=p1;
    }
    p2->next=NULL;
    fclose(in);
    return head;
};
struct PhoneName*create2(){
    int i,k;
    struct PhoneName *p1,*p2,*head;
    head=NULL;
    head=p1=p2=new(PhoneName);
    FILE *in=fopen("通讯录副本.txt","r");
    fscanf(in,"%d",&k);
    p1->num=k;//头节点用来存联系人数
    p2->next=p1;
    p2=p1;
    for(i=0;i<k;i++){
        p1=new(PhoneName);
        /*cout<<"\n请输入姓名：";*/
        fscanf(in,"%s",p1->name);
       /* cout<<"\n请输入电话：";*/
        fscanf(in,"%s",p1->phonenum);
        /*cout<<"\n请输入地址：";*/
        fscanf(in,"%s",p1->address);
        p2->next=p1;
        p2=p1;
    }
    p2->next=NULL;
    fclose(in);
    return head;
};
struct PhoneName*create(){
    int i,k;
    struct PhoneName *p1,*p2,*head;
    cout<<"请输入通讯录人数:";
    scanf("%d",&k);
    head=NULL;
    head=p1=p2=new(PhoneName);
    p1->num=k;//头节点用来存联系人数
    p2->next=p1;
    p2=p1;
    for(i=0;i<k;i++){
        p1=new(PhoneName);
        cout<<"\n请输入姓名：";
        scanf("%s",p1->name);
        cout<<"\n请输入电话：";
        scanf("%s",p1->phonenum);
        cout<<"\n请输入地址：";
        scanf("%s",p1->address);
        p2->next=p1;
        p2=p1;
    }
    p2->next=NULL;
    return head;
};
void out_message(PhoneName *head){
    PhoneName *p=NULL;
    p=head;
    FILE *in=fopen("通讯录副本.txt","w");
    fprintf(in,"%d\n",head->num);//输出联系人数到文件
    p=p->next;
    if(head!=NULL){
        do{
            fprintf(in,"%s ",p->name);
            fprintf(in,"%s ",p->phonenum);
            fprintf(in,"%s\n",p->address);
            p=p->next;
        }while(p!=NULL);
    }
    fclose(in);
}
void out_message2(PhoneName *head){
    PhoneName *p=NULL;
    p=head;
    FILE *in=fopen("通讯录.txt","w");
    fprintf(in,"%d\n",head->num);//输出联系人数到文件
    p=p->next;
    if(head!=NULL){
        do{
            fprintf(in,"%s ",p->name);
            fprintf(in,"%s ",p->phonenum);
            fprintf(in,"%s\n",p->address);
            p=p->next;
        }while(p!=NULL);
    }
    fclose(in);
}
void AllOut(PhoneName *p){
    cout<<"                            浏览功能操作       "<<endl;
    cout<<"                  +------------------------------+"<<endl;
    cout<<"                  +         1.显示全部联系人     +"<<endl;
    cout<<"                  +         2.返回上一层         +"<<endl;
    cout<<"                  +------------------------------+"<<endl;
    cout<<"请输入你的操作: ";
    int num;
    cin>>num;
    if(num==1){
        print(p);
        cout<<endl;
    }
}
void Add(PhoneName *head){
    cout<<"                            添加功能操作       "<<endl;
    cout<<"                  +------------------------------+"<<endl;
    cout<<"                  +         1.添加联系人         +"<<endl;
    cout<<"                  +         2.返回上一层         +"<<endl;
    cout<<"                  +------------------------------+"<<endl;
    cout<<"请输入你的操作: ";
    int num;
    cin>>num;
    PhoneName *p=NULL,*p1=head;
    if(num==1){
        while(true){
            p1=p1->next;
            if(p1->next==NULL)
                break;
        }
        p=create();
        head->num+=p->num;
        p1->next=p->next;
        out_message(head);
    }


}
void PhonenumScan(PhoneName *head){
    PhoneName *p=head;
    char str[100];
    cout<<"输入电话： ";
    scanf("%s",str);
    p=p->next;
    cout<<"姓名\t\t电话\t\t\t地址\n";
    while(p!=0){
        if(strcmp(str,p->phonenum)==0) {
            printf("%s",p->name);
            printf("\t\t%s",p->phonenum);
            printf("\t\t%s\n",p->address);
        }
          p=p->next;
    }
    out_message(head);
}
void AddressScan(PhoneName *head){
    PhoneName *p=head;
    char str[100];
    cout<<"输入地址： ";
    scanf("%s",str);
    p=p->next;
    cout<<"姓名\t\t电话\t\t\t地址\n";
    while(p!=0){
        if(strcmp(str,p->address)==0) {
            printf("%s",p->name);
            printf("\t\t%s",p->phonenum);
            printf("\t\t%s\n",p->address);
        }
          p=p->next;
    }
    out_message(head);
}
void NameScan(PhoneName *head){
    PhoneName *p=head;
    char str[100];
    cout<<"输入地址： ";
    scanf("%s",str);
    p=p->next;
    cout<<"姓名\t\t电话\t\t\t地址\n";
    while(p!=0){
        if(strcmp(str,p->name)==0) {
            printf("%s",p->name);
            printf("\t\t%s",p->phonenum);
            printf("\t\t%s\n",p->address);
        }
          p=p->next;
    }
    out_message(head);
}
void LookUp(PhoneName *p){
    cout<<"                            查找功能操作       "<<endl;
    cout<<"                  +------------------------------+"<<endl;
    cout<<"                  +         1.电话查找           +"<<endl;
    cout<<"                  +         2.地址查找           +"<<endl;
    cout<<"                  +         3.姓名查找           +"<<endl;
    cout<<"                  +         4.返回上一层         +"<<endl;
    cout<<"                  +------------------------------+"<<endl;
    cout<<"请输入你的操作: ";
    int num;
    cin>>num;
    switch(num){
        case 1:PhonenumScan(p);break;
        case 2:AddressScan(p);break;
        case 3:NameScan(p);break;
    }
}
void PhonenumChange(PhoneName *head){
    PhoneName *p=head;
    char str[100],name[20],num[20],Address[20];
    PhonenumScan(head);
    cout<<"\n再次输入电话： ";
    scanf("%s",str);
    p=p->next;
    while(p!=0){
        if(strcmp(str,p->phonenum)==0) {
        cout<<"\n输入姓名：";
        scanf("%s",name);
        cout<<"\n输入电话：";
        scanf("%s",num);
        cout<<"\n输入地址：";
        scanf("%s",Address);
        strcpy(p->name,name);
        strcpy(p->address,Address);
        strcpy(p->phonenum,num);
        }
        else{
          p=p->next;
        }
    }
    out_message(head);
}
void AddressChange(PhoneName *head){
    PhoneName *p=head;
    char str[100],name[20],num[20],Address[20];
    AddressScan(head);
    cout<<"\n再次输入地址： ";
    scanf("%s",str);
    p=p->next;
    while(p!=0){
        if(strcmp(str,p->address)==0) {
        cout<<"\n输入姓名：";
        scanf("%s",name);
        cout<<"\n输入电话：";
        scanf("%s",num);
        cout<<"\n输入地址：";
        scanf("%s",Address);
        strcpy(p->name,name);
        strcpy(p->address,Address);
        strcpy(p->phonenum,num);
        }
        else{
          p=p->next;
        }
    }
    out_message(head);
}
void NameChange(PhoneName *head){
    PhoneName *p=head;
    char str[100],name[20],num[20],Address[20];
    NameScan(head);
    cout<<"\n再次输入名字： ";
    scanf("%s",str);
    p=p->next;
    while(p!=0){
        if(strcmp(str,p->name)==0) {
        cout<<"\n输入姓名：";
        scanf("%s",name);
        cout<<"\n输入电话：";
        scanf("%s",num);
        cout<<"\n输入地址：";
        scanf("%s",Address);
        strcpy(p->name,name);
        strcpy(p->address,Address);
        strcpy(p->phonenum,num);
        }
        else{
          p=p->next;
        }
    }
    out_message(head);
}
void Change(PhoneName *p){
    cout<<"                                修改功能操作       "<<endl;
    cout<<"                  +----------------------------------------+"<<endl;
    cout<<"                  +           1.通过电话查找修改           +"<<endl;
    cout<<"                  +           2.通过地址查找删除           +"<<endl;
    cout<<"                  +           3.通过姓名查找删除           +"<<endl;
    cout<<"                  +           4.返回上一层                 +"<<endl;
    cout<<"                  +---------------------------------------+"<<endl;
    cout<<"请输入你的操作: ";
    int num;
    cin>>num;
    switch(num){
        case 1:PhonenumChange(p);break;
        case 2:AddressChange(p);break;
        case 3:NameChange(p);break;
    }

}
void PhonenumDelete(PhoneName *head){
    PhoneName *pre,*p=head;
    char str1[20];//要删除的联系人姓名
    AllOut(head);
    cout<<"\n输入联系人电话号码: ";
    scanf("%s",str1);
    while(p!=0){
        pre=p;
        p=p->next;
        if(strcmp(str1,p->phonenum)==0){
            pre->next=p->next;
            head->num=head->num-1;
            p=pre;
        }
        if(p->next==0){
            if(strcmp(str1,p->phonenum)==0){
                p=NULL;
                head->num=head->num-1;
            }
            else
                break;
        }
    }
    out_message(head);
}
void AddressDelete(PhoneName *head){
    PhoneName *pre,*p=head;
    AllOut(head);
    head->num=head->num-1;
    char str1[20];//要删除的联系人姓名
    cout<<"\n输入联系人地址: ";
    scanf("%s",str1);
    while(p!=0){
        pre=p;
        p=p->next;
        if(strcmp(str1,p->address)==0){
            pre->next=p->next;
            head->num=head->num-1;
            p=pre;
        }
        if(p->next==0){
            if(strcmp(str1,p->address)==0){
                 p=NULL;
                 head->num=head->num-1;
            }
            else
                break;
        }
    }
    out_message(head);
}
void NameDelete(PhoneName *head){
    PhoneName *pre,*p=head;
    AllOut(head);
    head->num=head->num-1;
    char str1[20];//要删除的联系人姓名
    cout<<"\n输入联系人姓名: ";
    scanf("%s",str1);
    while(p!=0){
        pre=p;
        p=p->next;
        if(strcmp(str1,p->name)==0){
            pre->next=p->next;
            head->num=head->num-1;
            p=pre;
        }
        if(p->next==0){
            if(strcmp(str1,p->name)==0){
                head->num=head->num-1;
                 p=NULL;
            }
            else
                break;
        }
    }
    out_message(head);
}
void Delete(PhoneName *p){
    cout<<"                            删除功能操作       "<<endl;
    cout<<"                  +------------------------------+"<<endl;
    cout<<"                  +         1.电话删除           +"<<endl;
    cout<<"                  +         2.地址删除           +"<<endl;
    cout<<"                  +         3.姓名删除           +"<<endl;
    cout<<"                  +         4.返回上一层         +"<<endl;
    cout<<"                  +------------------------------+"<<endl;
    cout<<"请输入你的操作: ";
    int num;
    cin>>num;
    switch(num){
        case 1:PhonenumDelete(p);break;
        case 2:AddressDelete(p);break;
        case 3:NameDelete(p);break;
    }
}
void About(){
    cout<<"                  +--------------------------------------+"<<endl;
    cout<<"                  +         1.添加:添加联系人            +"<<endl;
    cout<<"                  +         2.查找:查找联系人            +"<<endl;
    cout<<"                  +         3.修改:修改联系人            +"<<endl;
    cout<<"                  +         4.删除:删除联系人            +"<<endl;
    cout<<"                  +         5.浏览:显示所有联系人        +"<<endl;
    cout<<"                  +--------------------------------------+"<<endl;
    system("pause");
}

void CMPDelete(){
    PhoneName *head1,*head2,*p1,*p2,*pre,*p=NULL;
    head1=create1();//提取通讯录的数据添加到链表1中
    head2=create2();//提取通讯录副本的数据添加到链表中2
    p1=head1,p2=head2;
    p1->num=p2->num;
    p2=p2->next;
    FILE *in=fopen("通讯录副本.txt","w");
    p=head2;
    fprintf(in,"%d\n",head2->num);//输出联系人数到文件
    p=p->next;
    if(head2!=NULL){
        do{
            fprintf(in,"%s ",p->name);
            fprintf(in,"%s ",p->phonenum);
            fprintf(in,"%s\n",p->address);
            p=p->next;
        }while(p!=NULL);
    }
    fprintf(in,"删除的数据：\n");
        while(p1!=0){
        pre=p1;
        p1=p1->next;
        if((strcmp(p2->name,p1->name)!=0)||(strcmp(p2->phonenum,p1->phonenum)!=0)||(strcmp(p2->address,p1->address)!=0)){
            fprintf(in,"%s ",p1->name);
            fprintf(in,"%s ",p1->phonenum);
            fprintf(in,"%s\n",p1->address);
            pre->next=p1->next;
            p1=pre;
        }
        else{
            p2=p2->next;
        }
        if(p2==NULL){
            PhoneName *p3=NULL;
            p3=p1->next;
            p1->next=NULL;
            while(p3!=0){
                fprintf(in,"%s ",p3->name);
                fprintf(in,"%s ",p3->phonenum);
                fprintf(in,"%s\n",p3->address);
                p3=p3->next;
            }
        break;
        }
        }
    out_message2(head1);
    fclose(in);
}
void CMPAdd(){
    PhoneName *head1,*head2,*p1,*p2,*p=NULL;
    head1=create1();//提取通讯录的数据添加到链表1中
    head2=create2();//提取通讯录副本的数据添加到链表中2
    p1=head1,p2=head2;
    p1->num=p2->num;
    p1=p1->next;
    p2=p2->next;
    FILE *in=fopen("通讯录副本.txt","w");
    p=head2;
    fprintf(in,"%d\n",head2->num);//输出联系人数到文件
    p=p->next;
    if(head2!=NULL){
        do{
            fprintf(in,"%s ",p->name);
            fprintf(in,"%s ",p->phonenum);
            fprintf(in,"%s\n",p->address);
            p=p->next;
        }while(p!=NULL);
    }
    fprintf(in,"增加的数据：\n");
    while(p2!=0){
        if((strcmp(p2->name,p1->name)==0)&&(strcmp(p2->phonenum,p1->phonenum)==0)&&(strcmp(p2->address,p1->address)==0)){
            if(p1->next==NULL){
                p1->next=p2->next;
                p2=p2->next;
            while(p2!=0){
                fprintf(in,"%s ",p2->name);
                fprintf(in,"%s ",p2->phonenum);
                fprintf(in,"%s\n",p2->address);
                p2=p2->next;
            }
            break;
            }
            p1=p1->next;
            p2=p2->next;
        }
    }
    out_message2(head1);
    print(head1);
    fclose(in);
}
void CMPChange(){
        PhoneName *head1,*head2,*p1,*p2,*p=NULL;
    head1=create1();//提取通讯录的数据添加到链表1中
    head2=create2();//提取通讯录副本的数据添加到链表中2
    p1=head1,p2=head2;
    p1->num=p2->num;
    p1=p1->next;
    p2=p2->next;
    FILE *in=fopen("通讯录副本.txt","w");
    p=head2;
    fprintf(in,"%d\n",head2->num);//输出联系人数到文件
    p=p->next;
    if(head2!=NULL){
        do{
            fprintf(in,"%s ",p->name);
            fprintf(in,"%s ",p->phonenum);
            fprintf(in,"%s\n",p->address);
            p=p->next;
        }while(p!=NULL);
    }
    fprintf(in,"修改的数据：\n");
    while(p2!=0){
        if((strcmp(p2->name,p1->name)!=0)||(strcmp(p2->phonenum,p1->phonenum)!=0)||(strcmp(p2->address,p1->address)!=0)){
        fprintf(in,"%s ",p1->name);
        fprintf(in,"%s ",p1->phonenum);
        fprintf(in,"%s\n",p1->address);
        strcpy(p1->name,p2->name);
        strcpy(p1->address,p2->address);
        strcpy(p1->phonenum,p2->phonenum);

        }
        p1=p1->next;
        p2=p2->next;
    }
    out_message2(head1);
    print(head1);
    fclose(in);
}
void PhoneNameCMP(int num){
    if(num==4)
        CMPDelete();
    if(num==1)
        CMPAdd();
    if(num==3)
        CMPChange();
}
int main()
{
    int num;
    FILE *in;
    char ch;
    in=fopen("通讯录.txt","r+");
    ch=fgetc(in);
    PhoneName *p;
    if(ch==EOF){
        cout<<"您的通讯录还未有联系人，请添加：\n";
        PhoneName *head1;
        head1=create();
        out_message2(head1);
        p=head1;
        out_message(head1);
    }
    else{
        PhoneName *head2;
        head2=create1();
        p=head2;
    }
    while(true){
        menu();
        cin>>num;
        switch(num){
        case 0:About();break;
        case 1:Add(p);  break;
        case 2:LookUp(p);break;
        case 3:Change(p);break;
        case 4:Delete(p);break;
        case 5:AllOut(p);break;
        }
        PhoneNameCMP(num);
        cout<<endl;
        if(num==9)
            break;
    }
    return 0;
}
