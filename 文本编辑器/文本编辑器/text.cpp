#ilude <iostream>
#include <ctime>
#include <cstdlib>
#include<cstring>
using namespace std;

void m_sort(string* p)
{
    int mmin,i1,i2;
    string temp;
    for(i1=0;i1<4;i1++)
  {
      mmin=i1;
      for(i2=i1+1;i2<4;i2++)
          if(p[mmin]>p[i2])
            mmin=i2;
      if(i1!=mmin)
      {
          temp=p[i1];
          p[i1]=p[mmin];
          p[mmin]=temp;
      }
  }
  cout<<endl;
  for(i1=0;i1<4;i1++)
    cout<<p[i1]<<' ';
}
void m_sort(char *p)
{
    int i,j,temp;
    for (i=0;i<7;i++)
       for(j=0;j<7-i;j++)
       {
          if(p[j]>p[j+1])
          {
           temp=p[j];
           p[j]=p[j+1];
           p[j+1]=temp;
          }
       }
       for(i=0;i<8;i++)
       cout<<*(p+i)<<' ';
}
void m_sort (int *p)
{
    int i,j,temp;
    for (i=0;i<9;i++)
       for(j=0;j<9-i;j++)
       {
          if(p[j]>p[j+1])
          {
           temp=p[j];
           p[j]=p[j+1];
           p[j+1]=temp;
          }
       }
       for(i=0;i<10;i++)
       cout<<*(p+i)<<' ';
}
int main()
{
   int i;
   int iarr[10];
   char carr[8];
   srand(time(0));
   for(i=0;i<10;i++)
    iarr[i]=rand()%100+1;
    for(i=0;i<10;i++)
    cout<<iarr[i]<<' ';
    cout<<endl;
    m_sort(iarr);
    cout<<endl<<"Input 8 char:\n";
    for(i=0;i<8;i++)
        cin>>carr[i];
    m_sort(carr);
    string name[4]={"Gates","Kongzi","Obama","Micky"};
    m_sort(name);
    return 0;
}
