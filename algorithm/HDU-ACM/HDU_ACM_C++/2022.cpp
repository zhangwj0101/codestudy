////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-06 17:27:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2022
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int a(int i)
{
	if(i<0)
		i*=-1;
	return i;
}
int main()
{
    int s,t,i,j,m,mb,x,y,mx,my;
   while(cin>>x>>y)
   {
       mx=my=mb=m=0;
       for(i=0;i<x;i++)      //不合题意，原题要求是从1开始的
           for(j=0;j<y;j++)
           {
               cin>>s;
			   t=a(s);
               if(mb<t)
               {
                   m=s;
				   mb=a(s);
                   mx=i+1;
                   my=j+1;
               }
           }
        cout<<mx<<" "<<my<<" "<<m<<endl;
   }
   return 0;
}
