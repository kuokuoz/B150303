 /*�� file.h�ļ����������£�*/
#include <stdio.h>
#include <stdlib.h>
#include "book.h"        
int  createFile(Book boo[ ])              /*������ʼ�������ļ�*/
{
	FILE *fp;
	int n;
   	if((fp=fopen("d:\\book.dat", "wb")) == NULL) /*ָ�����ļ�������д�뷽ʽ��*/
	{
	    printf("can not open file !\n");         /*����ʧ�ܣ������ʾ��Ϣ*/
	    exit(0);                           /*Ȼ���˳�*/
    	}
	printf("input books\' information:\n");
	n=readBoo(boo,NUM);                /*����book.h�еĺ���������*/
fwrite(boo,sizeBoo,n,fp);                  /*���ղŶ�������м�¼һ����д���ļ�*/
 	fclose(fp);                             /*�ر��ļ�*/
	 return n;
}

int readFile(Book boo[ ] )                     /*���ļ��е����ݶ������ڽṹ������stu��*/
{
   	FILE *fp;
	int i=0;
	if((fp=fopen("d:\\book.dat", "rb")) == NULL)  /*�Զ��ķ�ʽ��ָ���ļ�*/
	{
	    printf("file does not exist,create it first:\n");  /*�����ʧ�������ʾ��Ϣ*/
	    return 0;                              /*Ȼ�󷵻�0*/
	}	 
    	fread(&boo[i],sizeBoo,1,fp);                   /*������һ����¼*/
   	while(!feof(fp))                            /*�ļ�δ����ʱѭ��*/
	{
		i++;
	    	fread(&boo[i],sizeBoo,1,fp);              /*�ٶ�����һ����¼*/
     }
	fclose(fp);                                /*�ر��ļ�*/
	return i;                                  /*���ؼ�¼����*/
}

void saveFile(Book boo[],int n)                  /*���ṹ�����������д���ļ�*/
{   			
  	FILE *fp;	
   	if((fp=fopen("d:\\book.dat", "wb")) == NULL) /*��д�ķ�ʽ��ָ���ļ�*/
	{
		printf("can not open file !\n");           /*�����ʧ�ܣ������ʾ��Ϣ*/
		exit(0);                            /*Ȼ���˳�*/
	}
	fwrite(boo,sizeBoo,n,fp);        
	fclose(fp);                              /*�ر��ļ�*/
}
