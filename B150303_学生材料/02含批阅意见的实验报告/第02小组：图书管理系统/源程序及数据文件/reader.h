#include"iostream.h"
#include"string.h"
#include"fstream.h"
#include<windows.h>
#include<stdlib.h>
#include <iomanip.h>
/************************���������***********************************/

class Reader 
{
private:
     int tag;                                //ɾ�����   1����ɾ   0��ĩɾ
     int no;                                 //���߱��  
     char name[15];                         //��������
     int borbook[Maxbor]; //����ͼ��
public:
     Reader(){}
     char *getname()                        //��ȡ����
        {return name;}
     int gettag()                          //��ȡɾ�����
        {return tag;}
     int getno()                          //��ȡ���߱��
        {return no;} 
     void setname(char na[])              //��������
        {strcpy(name,na);}
     void delbook()                       //����ɾ�����
        {tag=1;}
     void addreader(int n,char *na)      //���Ӷ���
     {
        tag=0;
        no=n; 
        strcpy(name,na);
        for(int i=0;i<Maxbor;i++)
          borbook[i]=0;
      }
     void borrowbook(int bookid)           //�������
     {
        for(int i=0;i<Maxbor;i++)
         {
           if(borbook[i]==0)
             {
               borbook[i]=bookid;
	       cout<<"\t ����ɹ�"<<endl;
               return ;
             }
          }
     }
     int retbook(int bookid)             //�������
     {
         for(int i=0;i<Maxbor;i++)
          {
             if(borbook[i]==bookid)
               {
                 borbook[i]=0;
		 cout<<"\t ����ɹ�"<<endl;
                 return 1;
                }
	      cout<<"����ʧ��"<<endl;
           }
          return 0; 
      }
     void disp()             //���������Ϣ
     {
         cout<<setw(8)<<no<<setw(15)<<name<<"              �����ţ�[";
         for(int i=0;i<Maxbor;i++)
         if(borbook[i]!=0)
            cout<<borbook[i]<<"|";
         cout<<"]"<<endl;
     }
}; 
/*************************������߿���**********************************************/
class RDatabase
{
private:
    int top;                               //���߼�¼ָ��
    Reader read[Maxr];                     //���߼�¼
public:
    RDatabase()
    {
      Reader s;                           //����������Ķ���s
      top=-1;               
      fstream file("reader.txt",ios::in);  //���캯������reader.txt����read[]��
      while(1)
        {
           file.read((char *)&s,sizeof(s));
           if(!file)
           break;
           top++;
           read[top]=s;
        }
      file.close();
     }
    void clear()                            //ɾ�����ж�����Ϣ
     {
       top=-1;
     }
    int addreader(int n,char *na)         //��Ӷ���ʱ�Ȳ����Ƿ����
     {
       Reader *p=query(n);
       if (p==NULL)
         {
           top++;
           read[top].addreader(n,na);
           return 1;
         }
       return 0;
      }
     Reader *query(int readerid)         //����Ų���
      {
         for(int i=0;i<=top;i++)
         if(read[i].getno()==readerid&&read[i].gettag()==0)
	    return &read[i];
         return NULL;
      }
     void disp()                        //���������Ϣ
      {
        for(int i=0;i<=top;i++)
        read[i].disp();
      }
     void readerdata();                 //����ά�� 
     ~RDatabase()                       //������������read[]д��reader.txt�ļ�
      {
        fstream file("reader.txt",ios::out);
        for(int i=0;i<=top;i++)
        if(read[i].gettag()==0)
        file.write((char *)&read[i],sizeof(read[i]));
        file.close();
      }
 };
void RDatabase::readerdata()           //���߿�ά��
{
   int choice=1;
   char rname[20];
   int readerid;
   Reader *r;
   while(choice!=0)
      {
         cout<<"  ����������ά���������"<<endl<<"            1������"<<endl<<"            2������"<<endl<<"            3��ɾ��"<<endl<<"            4������"<<endl<<"            5����ʾ"<<endl<<"            6��ȫɾ"<<endl<<"            0���˳�=>"<<endl;
         cin>>choice;
         switch(choice)
         {
         case 1:
           cout<<"            ������߱��:";
           cin>>readerid;
           cout<<"            �����������:";
           cin>>rname;
           addreader(readerid,rname);
           break;
         case 2:
           cout<<"            ������߱��:";
           cin>>readerid;
           r=query(readerid);
           if(r==NULL)
            {
              cout<<"            �ö��߲�����"<<endl;
              break;
            }
              cout<<"            �����µ�����:";
              cin>>rname;
              r->setname(rname);
              break;
          case 3:
             cout<<"            ������߱��:";
             cin>>readerid;
             r=query(readerid);
             if (r=NULL)
               {
                 cout<<"            �ö��߲�����:"<<endl;
                 break;
                }
              r->delbook();
              break;
          case 4:
             cout<<"            ������߱��:";
             cin>>readerid;
             r=query(readerid);
             if(r==NULL)
             {
                cout<<"            �ö��߲�����:"<<endl;
                break;
              }
	      else
	     {
		cout<<"   ���߱��         ��������"<<endl;
                r->disp();
	     }
             break;
          case 5:
              cout<<"   ���߱��         ��������"<<endl;
              disp(); 
              break;
          case 6:
              clear();
              break;
          } 
      } 
 }