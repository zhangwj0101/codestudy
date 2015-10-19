////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-04-25 22:14:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2006
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{

   int t,s,i,n;
   while(cin>>n)
   {
	   s=1;
	   for(i=0;i<n;i++)
	   {
		   cin>>t;
		   if(t%2==1)
			   s*=t;
	   }
	   cout<<s<<endl;
   }
   return 0;
}
