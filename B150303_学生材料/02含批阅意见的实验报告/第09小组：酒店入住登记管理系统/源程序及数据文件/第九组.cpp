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
	printf("\n\n   ����        ����        �Ա�        ���֤��        \n");
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
	printf("\n\n\t\t------------��ӭ����**�Ƶ�-----------\n\n"); 
	printf("\t\t\t 1. �Ǽ���ס \n\n");	
	printf("\t\t\t 2. �Ǽ��߷����ѯ \n\n");
	printf("\t\t\t 3. �Ǽ�����Ϣ��ѯ \n\n");  
	printf("\t\t\t 4. �˳�ϵͳ \n\n");
	printf("\t\t�ܷ�����:   \t��ס����:  \t�շ�����:   ");
	printf("\n\n&&&&&&&&&&&&&&&&&&&&&&&&############################&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");
	printf("\t\t\t ��ѡ��������ķ���: ");
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
		printf("������Ҫ��ѯ�ķ������:\n ");
		scanf("%s",no);
		 getchar();
		index=searchbyroom(no);
		if(index==-1)
			printf("�÷���Ϊ�գ�\n");
		else
		{
			system("cls");
			printf("\t\t��Ҫ��ѯ�Ŀͻ���ϢΪ��\n");
            displaysingle(index);
		}
		printf("�Ƿ��������y/n)");
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
		printf("\t##########��������������##########\n\n");
		scanf("%s",Name);
		getchar();
		index=searchbyname(Name);
		if(index==-1)
			printf("���û������ڣ�\n");
		else
		{
			printf("\t��Ҫ��ѯ�Ŀͻ���ϢΪ\n");
			displaysingle(index);
		}
		printf("�Ƿ������y/n\n");
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
  printf("######################�Ǽ���ס######################\n");
  printf("������\n");
  scanf("%s",guests[nums].name);
  getchar();
  printf("�Ա�\n");
  scanf("%s",guests[nums].sex);
  getchar();
  printf("���֤��\n");
  scanf("%s",guests[nums].id);
  getchar();
  printf("��סʱ��\n");
  scanf("%s",guests[nums].checkintime);
  getchar();
  printf("��סʱ��\n");
  scanf("%s",guests[nums].time);
  getchar();
  printf("��ס����\n");
  scanf("%s",guests[nums].num);
  getchar();
  printf("��ѡ�񷿼�����:\n1.���˼�\t\t\t2.˫�˼�\n3.���˼�\t\t\t4.��ͳ��\n");
  scanf("%d",&i);
  printf("�ɹ���ѡ��ķ�����\n");
 switch(i)
 {  
	case 1: for(j=0;j<13;j++)
		  printf("%5d",choice[0][j]);
	  printf("\n");
	  printf("���ۣ� 60           \n");
	  break;

  
	case 2: 
  
	  for(j=0;j<13;j++)
		  printf("%5d",choice[1][j]);
	  printf("\n");
	  printf("���ۣ�  100          \n");
	  break;
	 
  
	case 3: 
  
	  for(j=0;j<13;j++)
		  printf("%5d",choice[2][j]);
	  printf("\n");
	  printf("���ۣ�    30        \n");
	  break;

  
	case 4: 
  	  for(j=0;j<13;j++)
		  printf("%5d",choice[3][j]);
	  printf("\n");
	  printf("���ۣ�      300      \n");
	  break;
	  
 } 
  scanf("%s",guests[nums].room);
  getchar();
  printf("    �Ƿ������������y/n\n");
  if(getchar()=='n'||getchar()=='N')
	  break;
 }
 system("cls");
  

}
