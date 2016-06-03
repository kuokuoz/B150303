#include "player.h"
#include <stdio.h>
int readPla(Player  *pla , int n)          /*������Ա��¼ֵ�����Ϊ0������涨������¼ʱֹͣ*/
{
	int i,j;
	for (i=0;i<n;i++)
	{
		printf("Input one player\'s information\n");
		printf("num:  ");
		scanf("%ld", &pla[i].num);
		if (pla[i].num==0) break;
		printf("name: ");
		scanf("%s",pla[i].name);	
		printf("pos:  ");
		scanf("%s",pla[i].pos);
		printf("team:  ");
		scanf("%s",pla[i].team);
        printf("height:  ");
		scanf("%d",&pla[i].height);
		printf("weight:  ");
		scanf("%d",&pla[i].weight);
		printf("ascore:  ");
		scanf("%d",&pla[i].ascore);
		printf("rebound:  ");
		scanf("%d",&pla[i].rebound);
		printf("assist:  ");
		scanf("%d",&pla[i].assist);
		printf(" steal:  ");
		scanf("%d",&pla[i]. steal);
		printf("appearance:  ");
		scanf("%d",&pla[i].appearance);
  	     pla[i].total=0;		                  /*�ܷ���Ҫ������ã���ֵ��Ϊ0*/
         pla[i].rank=0;                 /*������Ҫ�����ܷ������㣬��ֵ��Ϊ0*/
		 printf("Input three data of the player:\n");
		for (j=0;j<3;j++)
	    {
		    scanf("%d",&pla[i].score[j]);	
		}
		
	}
	return i;                         /*����ʵ�ʶ���ļ�¼����*/
}

void printPla ( Player  *pla , int n)       /*���������Ա��¼��ֵ*/
{
    int i;
	for (i=0;i<n;i++)
	{
		printf("%2ld  ", pla[i].num);
		printf("%4s", pla[i].name);
		printf("%8s", pla[i].pos);
		printf("%8s", pla[i].team);
        printf("%6ld  ", pla[i].height);
		printf("%4ld  ", pla[i].weight);
		printf("%5ld  ", pla[i].ascore);
		printf("%5ld  ", pla[i].assist);
		printf("%4ld  ", pla[i].steal);
		printf("%5ld  ", pla[i].appearance);
	    printf("%4d",pla[i].total);
	    printf("%8d\n",pla[i].rank);
	}
}

int equal(Player p1,Player p2,int condition)  /*����ж�����Player��¼���*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚϱ��*/
		return p1.num==p2.num;
	else if (condition==2)                /*�������condition��ֵΪ2����Ƚ�����*/
    {
	     if (strcmp(p1.name,p2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*�������condition��ֵΪ3����Ƚ�����*/
	     return p1.rank==p2.rank;
 else if (condition==4)                /*�������condition��ֵΪ4����Ƚ��ܷ�*/
		return p1.total==p2.total;
	else return 1;                       /*�����������1*/
} 

int larger(Player p1,Player p2,int condition)  /*����condition�����Ƚ�����Player��¼�Ĵ�С*/
{
	if (condition==1)                    /*�������condition��ֵΪ1����Ƚϱ��*/
		return p1.num>p2.num;
	if (condition==2)                    /*�������condition��ֵΪ2����Ƚ��ܷ�*/
		return p1.total>p2.total;	
	else return 1; /*�����������1*/
}

void reverse(Player pla[],int n)             /*����Ԫ������*/
{
	int i;
	Player temp;
	for (i=0;i<n/2;i++)                   /*ѭ������ΪԪ��������һ��*/
	{
		temp=pla[i];
		pla[i]=pla[n-1-i];
		pla[n-1-i]=temp;
	}
}

void calcuTotal(Player pla[],int n)         /*����������Ա���ܷ�*/
{
	int i;
	for (i=0;i<n;i++)                    /*���ѭ������������Ա��¼*/
	{
		pla[i].total =0;
			pla[i].total =(pla[i].ascore*pla[i].appearance);
	}	
}

void calcuRank(Player pla[],int n)          /*�����ּܷ���������Ա���������ɼ���ͬ��������ͬ*/
{
	int i ;                       
	sortPla(pla,n,2);                     /*�ȵ���sortPla�㷨�����ܷ���С��������*/
	reverse(pla,n);                      /*�����ã����ܷ��ɴ�С������*/
	pla[0].rank=1;                      /*��һ����¼������һ����1*/
	for (i=1;i<n;i++)                     /*�ӵڶ�����¼һֱ�����һ������ѭ��*/
	{
		if (equal(pla[i],pla[i-1],11))         /*��ǰ��¼�������ڵ�ǰһ����¼����ܷ����*/
			pla[i].rank=pla[i-1].rank;     /*��ǰ��¼���ε��������ڵ�ǰһ����¼����*/ 
	    else
			pla[i].rank=i+1;             /*�����ʱ��ǰ��¼���ε������±��+1*/
	}
}
void calcuMark(double m[3][2],Player pla[],int n) /*�󳡾��÷�����������ߡ����*/
/*������ʽ������ά����m�ĵ�һά�����������ݣ��ڶ�ά������ߡ����*/
{
	int i,j;
	for (i=0;i<3;i++)                 /*���������ݵ���߷�*/		
	{ 
		m[i][0]=pla[0].score[i];     
		for (j=1;j<n;j++)
			if (m[i][0]<pla[j].score[i])
				m[i][0]=pla[j].score[i];
	}
	for (i=0;i<3;i++)                  /*���������ݵ���ͷ�*/
	{ 
		m[i][1]=pla[0].score[i];      
		for (j=1;j<n;j++)
			if (m[i][1]>pla[j].score[i])
				m[i][1]=pla[j].score[i];
	}
}

void sortPla(Player pla[],int n,int condition)  /*ѡ�����򣬰�condition������С��������*/
{
	int i,j,minpos;                      /*minpos�����洢������СԪ�����ڵ��±�*/
	Player t;
	for (i=0;i<n-1;i++)                  /*����ѭ����n-1��*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*Ѱ�ұ�����СԪ�����ڵ��±�*/
			if (larger(pla[minpos],pla[j],condition))
				minpos=j;
		if (i!=minpos)                 /*��֤������СԪ�ص����±�Ϊi��λ��*/
		{
			t=pla[i];
			pla[i]=pla[minpos];
			pla[minpos]=t;
		}
	}
}

int searchPla(Player pla[],int n,Player p,int condition,int f[ ])  /*��pla��������condition��������*/
/*��s��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*�����ҵ�Ԫ��*/
		if (equal(pla[i],p,condition))  
		{
			f[j++]=i;                          /*�ҵ�����ȵ�Ԫ�أ������±�ŵ�f������*/
			find++;	                        /*ͳ���ҵ���Ԫ�ظ���*/                              
		}
	 return find;                                /*����find����ֵΪ0���ʾû�ҵ�*/ 
}

int insertPla(Player pla[],int n,Player p)              /*��pla����������ŵ�������һ��Ԫ��s*/
{
	int i;
	sortPla(pla,n,1);                              /*�Ȱ��������*/
	for (i=0;i<n;i++)
	{
		if (equal(pla[i],p,1))                      /*�����ͬ��������룬��֤��ŵ�Ψһ��*/		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*����Ŵ�С��������*/
	{
		if (!larger(pla[i],p,1))                    /*���p���ڵ�ǰԪ��pla[i]�����˳�ѭ��*/
		break;
		pla[i+1]=pla[i];                         /*����Ԫ��pla[i]����һ��λ��*/
	}
	pla[i+1]=p;                                /*���±�i+1������Ԫ��s*/                                   
	n++;                                     /*Ԫ�ظ�������1*/
	return n;                                  /*��������Ԫ�ظ���*/
}

int deletePla(Player pla[],int n,Player p)            /*��������ɾ��ָ����ŵ�һ��Ԫ��*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*Ѱ�Ҵ�ɾ����Ԫ��*/
		if (equal(pla[i],p,1))   break;            /*����ҵ����Ԫ�����˳�ѭ��*/
	if (i==n)                                 /*����Ҳ�����ɾ����Ԫ��*/
	{
		printf("This record does not exist!\n");    /*������ʾ��ϢȻ�󷵻�*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*�˴���������Ϊi<n��equal(pla[i],s,1)����*/ 
		pla[j]=pla[j+1];                       /*ͨ���ƶ�����ɾ���±�Ϊi��Ԫ��*/
                                                                          
	n--;                                      /*Ԫ�ظ������ټ�1*/
	return n;                                  /*�������и���*/
}