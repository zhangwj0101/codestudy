////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-09 23:26:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1719
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int n,s[1000];
   while(cin>>n)
   {
	   if(n==0)
		   cout<<"NO!"<<endl;
	   else
	   {
		   n++;
		   while((n%2==0)&&n>0)
			   n/=2;
		   while((n%3==0)&&n>0)
			   n/=3;
		   if(n==1)
			   cout<<"YES!"<<endl;
		   else
			   cout<<"NO!"<<endl;
	   }
   }
   return 0;
}