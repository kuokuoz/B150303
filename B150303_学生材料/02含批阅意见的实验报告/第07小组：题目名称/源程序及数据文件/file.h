#include <stdio.h>
#include <stdlib.h>
#include "player.h"        
int  createFile(Player pla[ ])              /*������ʼ�������ļ�*/
{
	FILE *fp;
	int n;
  	if((fp=fopen("F:\\GONG\\player.txt", "wb")) == NULL) /*ָ�����ļ�������д�뷽ʽ��*/
	{
	    printf("can not open file !\n");         /*����ʧ�ܣ������ʾ��Ϣ*/
	    exit(0);                           /*Ȼ���˳�*/
    	}
	printf("input players\' information:\n");
	n=readPla(pla,NUM);                /*����player.h�еĺ���������*/
fwrite(pla,sizePla,n,fp);                  /*���ղŶ�������м�¼һ����д���ļ�*/
	fclose(fp);                             /*�ر��ļ�*/
	 return n;
}
int readFile(Player pla[ ] )                     /*���ļ��е����ݶ������ڽṹ������pla��*/
{
   	FILE *fp;
	int i=0;
	if((fp=fopen("F:GONG\\player.txt\\", "rb")) == NULL)  /*�Զ��ķ�ʽ��ָ���ļ�*/
	{
	    printf("file does not exist,create it first:\n");  /*�����ʧ�������ʾ��Ϣ*/
	    return 0;                              /*Ȼ�󷵻�0*/
	}	 
   	fread(&pla[i],sizePla,1,fp);                   /*������һ����¼*/
  	while(!feof(fp))                            /*�ļ�δ����ʱѭ��*/
	{
		i++;
	    	fread(&pla[i],sizePla,1,fp);              /*�ٶ�����һ����¼*/
    }
	fclose(fp);                                /*�ر��ļ�*/
	return i;                                  /*���ؼ�¼����*/
}

void saveFile(Player pla[],int n)                  /*���ṹ�����������д���ļ�*/
{   			
  	FILE *fp;	
   	if((fp=fopen("F:\\GONG\\player.txt\\", "wb")) == NULL) /*��д�ķ�ʽ��ָ���ļ�*/
	{
		printf("can not open file !\n");           /*�����ʧ�ܣ������ʾ��Ϣ*/
		exit(0);                            /*Ȼ���˳�*/
	}
	fwrite(pla,sizePla,n,fp);        
	fclose(fp);                              /*�ر��ļ�*/
}