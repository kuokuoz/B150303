/* ��student.h�ļ����������� */
#ifndef _STUDENT             /*�������룬��ֹ�ظ������Ĵ���*/
#define _STUDENT
#include <string.h>
#define NUM 20                /*����ͼ�������������˴����Ը���ʵ����Ҫ�޸ĳ���ֵ*/
struct Book                   /*ͼ���¼��������*/
{
	long num;											//���
	char title[20];										//����
	char author[10];									//����
	char company[10];									//������
	int price;											//�۸�
	int a;												//������
	int b;												//������
};
typedef struct Book Book;
#define sizeBoo sizeof(Book)      /*һ��ͼ���¼����Ҫ���ڴ�ռ��С*/
int readBoo(Book boo[],int n);       /*����ͼ���¼ֵ�����Ϊ0������涨������¼ʱֹͣ*/
void printBoo(Book  *boo , int n);   /*�������ͼ���¼��ֵ*/

int equal(Book b1,Book b2,int condition);  /*����condition�����ж�����Book����������ȷ�*/
int larger(Book b1,Book b2,int condition);  /*����condition�Ƚ�Book�������ݴ�С*/
void reverse(Book b[],int n);             /*ͼ���¼����Ԫ������*/

void calcuTotal(Book boo[],int n);           /*��������ͼ���������*/   
void calcuMark(double m[2][2],Book boo[],int n); /*�������ݵ���ߡ���͡�ƽ����m�����һά*/
/*��ʾ�������ݣ��ڶ�ά��ʾ��ߡ���͡�ƽ��*/

void sortBoo(Book boo[],int n,int condition);   /*ѡ�񷨴�С�������򣬰�condition���涨������*/

int searchBoo(Boo boo[],int n,Book b,int condition,int f[]) ;  /*������������������s��ȵĸ�Ԫ��*/
/*�±�����f�����У���f��������Ϊ���ҽ�����ܲ�ֹһ����¼*/
int insertBoo(Book boo[],int n,Book b);                   /*�������в���һ��Ԫ�ذ�ѧ������*/
int deleteBoo(Book boo[],int n,Bool s);                   /*��������ɾ��һ��ָ��ѧ�ŵ�Ԫ��*/
#endif
