
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
int runmenu(int choice);
void managermenu();
void searchmenu();
void operatemenu();
void fmenu();
void smenuone();
void smenutwo();
void smenuthree();
void cover();
int main()
{
	int i,j,choice;
	cover();	
	for(i=1;i<40;i++)
		printf("***");
	printf("\n");
	for(i=1;i<40;i++)
		printf("---");	//ҳü���
	for(j=1;j<10;j++)
	    printf("\n");
do
{
	fmenu();
	scanf("%d",&choice);
	if(choice<=5&&choice>=0)
        runmenu(choice);
	else 
		printf("\t\t\t\t\t�����������һ�����룡\n");
    system("cls");//����
	for(j=1;j<8;j++)
	    printf("\n");//�ո����
}while(choice);
	return 0;
}
int runmenu(int choice)
{
    int j;
	system("cls");//����
	for(j=1;j<10;j++)
	    printf("\n");//���ƿո�
	switch(choice)
	{
	case 1:managermenu();
		   break;
	case 2:searchmenu();
		   break;
	case 3:operatemenu();
		   break;
    case 0:break;
	}
	return 0;
}
void cover()
{   int i,j;
    for(i=1;i<40;i++)
		printf("---");//��ͷҳ������
	for(j=1;j<6;j++)
	    printf("\n");//���ƿո�
	//�𳵼�����ͼƬ
	printf("\t\t\t\t\t-----------------------------------------------------------------------------\n");
	printf("\t\t\t\t       /\n");
    printf("\t\t\t\t      /     ������    ������    ������    ������   ������   ������    \n");
	printf("\t\t\t\t     /      ��  ��    ��  ��    ��  ��    ��  ��   ��  ��   ��  ��\n");
	printf("\t\t\t\t    /       ������    ������    ������    ������   ������   ������\n");
	printf("\t\t\t\t   /    (*^__^*)��˾����\n");
	printf("\t\t\t\t   ---------------------------------------------------------------------------------\n");
	for(j=1;j<5;j++)
	    printf("\n");//�ٷ��²�
	printf("\t\t\t\t��(�����)��(�����)���.��.\n");
	printf("\t\t\t\t����github���غ��Ѱ��q(�i�ɡɩi#)\n");
	printf("\t\t\t\t<(����)_�q�ɨr�q�ɨr(*+�n+*)~ �ܲ��ˣ�\n");
	printf("\t\t\t\t��Ʊϵͳ���Ѱ���~>_<~(�Уߩ�)\n");
	printf("\t\t\t\t(�����)�J�ж��<<(������)>>\n");
	for(j=1;j<6;j++)
	    printf("\n");//�ո����
    printf("\t\t\t\t\t\t��ӭ������˾����Ʊ����ϵͳ\n");
	for(i=1;i<40;i++)
		printf("---");
	Sleep(2000);//��ʱ
    system("cls");//����
}
void managermenu()
{
	int choice;
	do
	{
    smenuone();
	scanf("%d",&choice);
	if(choice<=3&&choice>=0)
	switch (choice)
	{
	case 1: //add()
		break;
    case 2: //modify()
		break;
	case 3: //del()
		break;
	case 0: break;
	}
        
	else 
		printf("\t\t\t\t\t�����������һ�����룡\n");
	
	}while (choice);
}
void searchmenu()
{   
	int choice;
	do
	{
    smenutwo();
	scanf("%d",&choice);
	if(choice<=3&&choice>=0)
	switch (choice)
	{
	case 1: //remain()
		break;
    case 2: //price()
		break;
	case 3: //opentime()
		break;
	case 0: break;
	}
        
	else 
		printf("\t\t\t\t\t�����������һ�����룡\n");
	
	}while (choice);
}
void operatemenu()
{
	int choice;
	do
	{
    smenuthree();
	scanf("%d",&choice);
	if(choice<=3&&choice>=0)
	switch (choice)
	{
	case 1: //client()
		break;
    case 2: //cancleorbook()
		break;
	case 3: //time()
		break;
	case 0: break;
	}
        
	else 
		printf("\t\t\t\t\t�����������һ�����룡\n");
	
	}while (choice);
}

void fmenu()
{	
	printf("\t\t\t\t\t****************************************************\n");
    printf("\t\t\t\t\t*************1.����Ա����ϵͳ      *****************\n");
    printf("\t\t\t\t\t*************2.��Ʊ����ϵͳ        *****************\n");
    printf("\t\t\t\t\t*************3.�ͻ��˶�Ʊ����ϵͳ  *****************\n");
	printf("\t\t\t\t\t*************0.�˳�                *****************\n");
    printf("\t\t\t\t\t****************************************************\n");
 //�˵�ѡ��
	printf("\t\t\t\t\t���ڴ˴�ѡ��˵�:");
}
void smenuone()
{
    printf("\t\t\t\t\t****************************************************\n");
    printf("\t\t\t\t\t*************1.��ӳ�����Ϣ        *****************\n");
    printf("\t\t\t\t\t*************2.�޸ĳ�����Ϣ        *****************\n");
    printf("\t\t\t\t\t*************3.ɾ��������Ϣ        *****************\n");
	printf("\t\t\t\t\t*************0.������һ���˵�      *****************\n");
    printf("\t\t\t\t\t****************************************************\n");
 //�˵�ѡ��
	printf("\t\t\t\t\t���ڴ˴�ѡ��˵�:");
}
void smenutwo()
{
	printf("\t\t\t\t\t****************************************************\n");
    printf("\t\t\t\t\t*************1.ʣ��Ʊ����Ϣ        *****************\n");
    printf("\t\t\t\t\t*************2.����Ʊ����Ϣ        *****************\n");
    printf("\t\t\t\t\t*************3.����ʱ�䳵����Ϣ    *****************\n");
	printf("\t\t\t\t\t*************0.������һ���˵�      *****************\n");
    printf("\t\t\t\t\t****************************************************\n");
	//�˵�ѡ��
	printf("\t\t\t\t\t���ڴ˴�ѡ��˵�:");
}
void smenuthree()
{
	printf("\t\t\t\t\t****************************************************\n");
    printf("\t\t\t\t\t*************1.�ͻ���Ϣȷ��        *****************\n");
    printf("\t\t\t\t\t*************2.�ͻ��˶�Ʊ����      *****************\n");
    printf("\t\t\t\t\t*************3.������ʱ���ѯ      *****************\n");
	printf("\t\t\t\t\t*************0.������һ���˵�      *****************\n");
    printf("\t\t\t\t\t****************************************************\n");
	//�˵�ѡ��
	printf("\t\t\t\t\t���ڴ˴�ѡ��˵�:");
}