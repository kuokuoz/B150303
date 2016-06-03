#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"player.h"
void printHead( )      /*��ӡ��Ա��Ϣ�ı�ͷ*/
{
	printf("=========================NBA PLAYERS' STATISTICS==========================\n");
	printf("%4s%6s%9s%6s%6s%6s%9s%6s%6s%6s%9s%6s\n","���","����","����λ��","���","���","����","�����÷�","����","����","����","��������","����");
}
void menu( )         /*����˵�����*/
{
		printf("******** 1. ��ʾ������Ϣ ********\n");
		printf("******** 2. ������Ϣ���� ********\n");
		printf("******** 3. ��Ա���ݹ��� ********\n");
		printf("******** 4. ��������ͳ�� ********\n");
        printf("******** 5. ����������ѯ ********\n");
		printf("******** 0. �˳�         ********\n");
}

void menuBase( )     /*2��������Ϣ����˵�����*/
{
		printf("%%%%%%%% 1. ������Ա��¼ %%%%%%%%\n");
		printf("%%%%%%%% 2. ɾ����Ա��¼ %%%%%%%%\n");
		printf("%%%%%%%% 3. �޸���Ա��¼ %%%%%%%%\n");
		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");
}

void menuScore( )     /*3����Ա�ɼ�����˵�����*/
{
		printf("@@@@@@@@ 1. ������Ա�ܷ� @@@@@@@@\n");
		printf("@@@@@@@@ 2. �����ܷ����� @@@@@@@@\n");
		printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");
}
 
void menuCount( )    /*4�����Գɼ�ͳ�Ʋ˵�����*/
{
		printf("&&&&&&&& 1. ��������� &&&&&&&&\n");
		printf("&&&&&&&& 2. ��������� &&&&&&&&\n");
		printf("&&&&&&&& 0. �����ϲ�˵� &&&&&&&&\n");
}

void menuSearch()    /*5������������ѯ�˵�����*/
{
		printf("######## 1. ����Ų�ѯ   ########\n");
		printf("######## 2. ��������ѯ   ########\n");
		printf("######## 3. �����β�ѯ   ########\n");
		printf("######## 0. �����ϲ�˵� ########\n");
}
int baseManage(Player pla[],int n)    	     /*�ú�����ɻ�����Ϣ����*/
/*����Ž��в���ɾ���޸ģ���Ų����ظ�*/
{  
	int choice,t,find[NUM];
	Player p;
	do
	{   
		menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	          /*����ѡ��*/
		switch(choice)
		{
			 case 1:	 readPla(&p,1);       /*����һ�����������Ա��¼*/
					 n=insertPla(pla,n,p);   /*���ú���������Ա��¼*/
					 break;
			 case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&p.num);  /*����һ����ɾ������Ա���*/
					 n=deletePla(pla,n,p);   /*���ú���ɾ��ָ����ŵ���Ա��¼*/
					 break;
			 case 3:  printf("Input the number modified\n");
					 scanf("%ld",&p.num);  /*����һ�����޸ĵ���Ա���*/
				      t=searchPla(pla,n,p,1,find) ; /*���ú�������ָ����ŵ���Ա��¼*/				                           if (t)                 /*����ñ�ŵļ�¼����*/
			  		 {
						  readPla(&p,1);   /*����һ����������Ա��¼��Ϣ*/
					      pla[find[0]]=p;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					 
					  }					 
					 else                 /*����ñ�ŵļ�¼������*/ 
		             printf("this player is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/
					 break;
			         case 0: break;
		   }
	}while(choice);
return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/
}
void scoreManage(Player pla[],int n)          /*�ú��������Ա���ݹ�����*/
{  
	int choice;
	do
	{
		menuScore( );                        /*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	                 /*�������ѡ��*/
		switch(choice)
		{
			case 1:   calcuTotal(pla,n);         /*��������Ա���ܷ�*/
					  break;
			case 2:   calcuRank(pla,n);         /*����������Ա���ܷ�������*/
				      break;		
			case 0:   break;
		}
	}while(choice);
}
void printMarkCourse(char *p,double m[2][2],int k)   /*��ӡ����ͨ�ú�������countManage ����*/
{                 /*��ʽ����k���������ͬ�����ݣ�0��1��2�ֱ��Ӧ������ݡ��������*/
int i;
    printf(p);                                  /*�����p�������������ݵ���ʾ��Ϣ*/
   for (i=0;i<2;i++)                           /*i������һ������*/
		  printf("%10.2lf",m[i][k]);
	   printf("\n");
}
void countManage(Player pla[],int n)               /*�ú�����ɳ�������ͳ�ƹ���*/
{
		int choice;
		double mark[3][2];
		do
		{
			menuCount( );                        /*��ʾ��Ӧ�Ķ����˵�*/
			calcuMark(mark,pla,n);                 /*���ô˺������������ݵ���ߡ����*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printMarkCourse("����������ߵķֱ���:\n",mark,0);  /*����������*/
				      break;
				case 2:   printMarkCourse("����������͵ķֱ���:\n",mark,1);  /*����������*/
				      break;
				case 0:   break;
			}
		}while (choice);
}
void searchManage(Player pla[],int n)               /*�ú�����ɸ���������ѯ����*/
{
    int i,choice,findnum,f[NUM];
Player p;
	   do
{
			menuSearch( );                         /*��ʾ��Ӧ�Ķ����˵�*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a player\'s num will be searched:\n");
				      scanf("%ld",&p.num);         /*�������ѯ��Ա�ı��*/
					  break;
				case 2:   printf("Input a player\'s name will be searched:\n");
				      scanf("%p",p.name);	          /*�������ѯ��Ա������*/		  
				      break;   
				case 3:   printf("Input a rank will be searched:\n");
				      scanf("%d",&p.rank);          /*�������ѯ��Ա������*/
					  break;
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{ 
				findnum=searchPla(pla,n,p,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/
				if (findnum)				     /*������ҳɹ�*/
				{
			   		 printHead( );                  /*��ӡ��ͷ*/
					 for (i=0;i<findnum;i++)         /*ѭ������f������±�*/
	      	 printPla(&pla[f[i]],1);      /*ÿ�����һ����¼*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		     }		
	    }while (choice);
}
int runMain(Player pla[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. ��ʾ������Ϣ*/
				 sortPla(pla,n,1);         /*�������С�����˳�������¼*/ 
        	 printPla(pla,n);          /*�������С�����˳��������м�¼*/
					break;
			case 2: n=baseManage(pla,n);    /* 2. ������Ϣ����*/
			   	     break;
			case 3: scoreManage(pla,n);     /* 3. ��Ա���ݹ���*/
					break;
			case 4: countManage(pla,n);     /* 4. ��������ͳ��*/
					break;
			case 5: searchManage(pla,n);     /* 5. ����������ѯ*/
				     break;
          case 0: break;
		}
		return n;
}
int main( )
{
		Player pla[NUM];                /*����ʵ��һά����洢��Ա��¼*/
      int choice,n;
	 n=readFile(pla);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	 if (!n)                          /*���ԭ�����ļ�Ϊ��*/
	     {
		    n=createFile(pla);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
}	 	 
	do
	     {
	         menu();                      /*��ʾ���˵�*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(pla,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortPla(pla,n,1);                   /*�����ļ�ǰ�������С��������*/ 
	     saveFile(pla,n);                   /*����������ļ�*/
        return 0;
}



