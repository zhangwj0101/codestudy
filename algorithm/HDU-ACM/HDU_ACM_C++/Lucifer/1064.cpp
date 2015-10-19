////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-04-25 20:04:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1064
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<iomanip>
#include<cstdio>
using namespace std;

int main()
{
   double s=0.0,a;
   for(int i=0;i<12;i++)
   {
		cin>>a;
		s+=a;
   }
   s=s/12;
   cout<<"$";
   printf("%.2f",s);
   cout<<endl;
   return 0;
}

