////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-06 17:08:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2005
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
bool leap(int y)
{
    if((y%4==0&&y%100!=0)||(y%400==0))
        return true;
    else
        return false;
}
int main()
{
    const int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31}; 
   int y,m,d,s,i;
   while(scanf("%d/%d/%d",&y,&m,&d)==3)
   {
        for(s=0,i=0;i<m-1;i++)
            s+=mon[i];
        if((m>2)&&leap(y))
            s++;
        s+=d;
        cout<<s<<endl;
   }
   return 0;
}