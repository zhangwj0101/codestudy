////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-09 22:48:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2053
////Problem Title: 
////Run result: Accept
////Run time:921MS
////Run memory:300KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int n,i,j,s[100001];
   while(cin>>n)
   {
	   for(i=0;i<=n;i++)
		   s[i]=0;
	   for(i=1;i<=n;i++)
		   for(j=i;j<=n;j+=i)
			   s[j]=!s[j];
		cout<<s[n]<<endl;
   }
   return 0;
}