////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-06 17:15:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2007
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
   long s1,s2,a,b,i,a1,b1;
   while(cin>>a>>b)
   {
       s1=s2=0;
	   a1=a>b?b:a;
	   b1=a>b?a:b;
       for(i=a1;i<=b1;i++)
       {
           if(i%2)
               s1+=i*i*i;
           else
               s2+=i*i;
       }
       cout<<s2<<" "<<s1<<endl;
   }
   return 0;
}