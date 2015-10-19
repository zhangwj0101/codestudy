////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-09 21:01:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2071
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int i,j,n,t;
	float m,t1;
   cin>>t;
   for(i=0;i<t;i++)
   {
	   cin>>n;
	   for(m=0,j=0;j<n;j++)
	   {
		   cin>>t1;
			if(t1>m)
				m=t1;
	   }
	   printf("%.2f\n",m);
   }
   return 0;
}