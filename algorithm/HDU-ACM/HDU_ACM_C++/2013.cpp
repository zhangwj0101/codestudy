////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-04-25 23:24:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2013
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int a,i,s;
   while(cin>>a)
   {
	   s=1;
	   for(i=1;i<a;i++)
		   s=(s+1)*2;
	   cout<<s<<endl;
   }      
   return 0;
}

