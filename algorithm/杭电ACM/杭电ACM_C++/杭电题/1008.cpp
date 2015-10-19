////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-09 22:02:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1008
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int i,n,t,sum,s[100]={0};
	cin>>n;
   while(n!=0)
   {
	   for(i=1,sum=0;i<=n;i++)
	   {
		   cin>>s[i];
		   t=s[i]-s[i-1];
		   if(t>0)
			   sum+=t*6;
		   if(t<0)
			   sum+=t*(-1)*4;
	   }
	   cout<<sum+n*5<<endl;
		cin>>n;
   }
   return 0;
}