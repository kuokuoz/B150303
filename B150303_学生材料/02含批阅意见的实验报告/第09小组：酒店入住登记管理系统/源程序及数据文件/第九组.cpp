#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
void Checkin( );
void Room();
void informationservices( );
struct Check
{
	char id[20];											
	char name[20];												
	char sex[10];											
	char room[5];												
	char style[20] ;                                      	
	char  price[3];                                         	
    char  num[20];
	char  time[20];
	char checkintime[20];                                
};
struct Check guests[200];
int nums=0;
int searchbyroom(char no[])
{
	int i,k=1;
	for(i=0;i<nums;i++)
	{
		if(strcmp(guests[i].room,no)==0)
		{
			return i;
			k=0;
		}
	}
	if(k)
	{
		return -1;
	}
}
int searchbyname(char Name[])
{
	int i,k=1;
	for(i=0;i<nums;i++)
	{
		if(strcmp(guests[i].name,Name)==0)
		{
			return i;
			k=0;
		}
	}
	if(k)
	{
		return -1;
	}
}
void displaysingle(int index)
{
	printf("\n\n   房号        姓名        性别        身份证号        \n");
	printf("-----------------------------------------------------------\n");
	printf("   %10s%10s%10s%20s\n\n",guests[index].room,guests[index].name,guests[index].sex,guests[index].id);
	printf("-----------------------------------------------------------\n\n");
}
int main( )
{
  while(1)
  {
	int n;
	printf("&&&&&&&&&&&&&&&&&&&&&&&&&&#############################&&&&&&&&&&&&&&&&&&&&&&&");
	printf("\n\n\t\t------------欢迎来到**酒店-----------\n\n"); 
	printf("\t\t\t 1. 登记入住 \n\n");	
	printf("\t\t\t 2. 登记者房间查询 \n\n");
	printf("\t\t\t 3. 登记者信息查询 \n\n");  
	printf("\t\t\t 4. 退出系统 \n\n");
	printf("\t\t总房间数:   \t入住人数:  \t空房间数:   ");
	printf("\n\n&&&&&&&&&&&&&&&&&&&&&&&&############################&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
	printf("\t\t\t 请选择您所需的服务: ");
    scanf("%d",&n);
	switch(n)
	{
	case 1:Checkin();break;
	case 2:Room();break;
	case 3:informationservices( );break;
	return 0;
	}
  }
}
void Room()
{
	while(1)
	{
		char no[20];
		char index;
		char a;
		printf("请输入要查询的房间号码:\n ");
		scanf("%s",no);
		 getchar();
		index=searchbyroom(no);
		if(index==-1)
			printf("该房间为空！\n");
		else
		{
			system("cls");
			printf("\t\t你要查询的客户信息为：\n");
            displaysingle(index);
		}
		printf("是否继续？（y/n)");
		scanf("%s",&a);
		if(a=='n'||a=='N')
			break;
	}
	system("cls");
}
void informationservices( )
{
	while(1)
	{
		char Name[20];
		int  index;
		char a;
		printf("\t##########请输入您的姓名##########\n\n");
		scanf("%s",Name);
		getchar();
		index=searchbyname(Name);
		if(index==-1)
			printf("该用户不存在！\n");
		else
		{
			printf("\t您要查询的客户信息为\n");
			displaysingle(index);
		}
		printf("是否继续？y/n\n");
		scanf("%s",&a);
		if(a=='n'||a=='N')
			break;
	}
	system("cls");
}
void Checkin()
{
 while(1)
 {
	int i,j;
  int choice[4][13]={{101,102,103,104,105,106,107,108,109,110,111,112,113},{201,202,203,204,205,206,207,208,209,210,211,212,213},{301,302,303,304,305,306,307,308,309,310,311,312,313},{401,402,403,404,405,406,407,408,409,410,411,412,413}};
  printf("######################登记入住######################\n");
  printf("姓名：\n");
  scanf("%s",guests[nums].name);
  getchar();
  printf("性别\n");
  scanf("%s",guests[nums].sex);
  getchar();
  printf("身份证号\n");
  scanf("%s",guests[nums].id);
  getchar();
  printf("入住时间\n");
  scanf("%s",guests[nums].checkintime);
  getchar();
  printf("入住时长\n");
  scanf("%s",guests[nums].time);
  getchar();
  printf("入住人数\n");
  scanf("%s",guests[nums].num);
  getchar();
  printf("请选择房间类型:\n1.单人间\t\t\t2.双人间\n3.多人间\t\t\t4.总统房\n");
  scanf("%d",&i);
  printf("可供您选择的房间有\n");
 switch(i)
 {  
	case 1: for(j=0;j<13;j++)
		  printf("%5d",choice[0][j]);
	  printf("\n");
	  printf("房价： 60           \n");
	  break;

  
	case 2: 
  
	  for(j=0;j<13;j++)
		  printf("%5d",choice[1][j]);
	  printf("\n");
	  printf("房价：  100          \n");
	  break;
	 
  
	case 3: 
  
	  for(j=0;j<13;j++)
		  printf("%5d",choice[2][j]);
	  printf("\n");
	  printf("房价：    30        \n");
	  break;

  
	case 4: 
  	  for(j=0;j<13;j++)
		  printf("%5d",choice[3][j]);
	  printf("\n");
	  printf("房价：      300      \n");
	  break;
	  
 } 
  scanf("%s",guests[nums].room);
  getchar();
  printf("    是否继续？请输入y/n\n");
  if(getchar()=='n'||getchar()=='N')
	  break;
 }
 system("cls");
  

}
