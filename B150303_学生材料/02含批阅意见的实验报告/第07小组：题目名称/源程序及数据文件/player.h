#ifndef _PLAYER             /*�������룬��ֹ�ظ������Ĵ���*/
#define _PLAYER
#include <string.h>
#define NUM 20                /*������Ա�����������˴����Ը���ʵ����Ҫ�޸ĳ���ֵ*/
struct Player                   /*��Ա��¼��������*/
{
		long num;
		char name[20];
		char pos[10];
		char team[20];
        int height;
		int weight;
		int score[3];
		int ascore;
        int rebound;
        int assist;
		int steal;
		int appearance;
		int total;
		int rank;
};
typedef struct Player Player;
#define sizePla sizeof(Player)      /*һ����Ա��¼����Ҫ���ڴ�ռ��С*/
int readPla(Player pla[],int n);       /*������Ա��¼ֵ�����Ϊ0������涨������¼ʱֹͣ*/
void printPla(Player  *pla , int n);   /*���������Ա��¼��ֵ*/
int equal(Player p1,Player p2,int condition);  /*����condition�����ж�����Player����������ȷ�*/
int larger(Player p1,Player p2,int condition);  /*����condition�Ƚ�Student�������ݴ�С*/
void reverse(Player pla[],int n);             /*��Ա��¼����Ԫ������*/

void calcuTotal(Player pla[],int n);           /*����������Ա���ܷ�*/
void calcuRank(Player pla[],int n);           /*�����ּܷ�����Ա�����Σ������в�������*/
void calcuMark(double m[2][2],Player pla[],int n); /*�󳡾��÷֡����塢��������ߡ���ͣ�m�����һά*/
/*��ʾ���ſΣ��ڶ�ά��ʾ��ߡ����*/

void sortPla(Player pla[],int n,int condition);   /*ѡ�񷨴�С�������򣬰�condition���涨������*/

int searchPla(Player pla[],int n,Player p,int condition,int f[]) ;  /*������������������s��ȵĸ�Ԫ��*/
/*�±�����f�����У���f��������Ϊ���ҽ�����ܲ�ֹһ����¼*/
int insertPla(Player pla[],int n,Player p);                   /*�������в���һ��Ԫ�ذ�ѧ������*/
int deletePla(Player pla[],int n,Player p);                   /*��������ɾ��һ��ָ��ѧ�ŵ�Ԫ��*/
#endif