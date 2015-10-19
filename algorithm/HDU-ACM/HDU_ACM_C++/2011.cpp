////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-11 13:33:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2011
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<cstdio>
using namespace std;
int main()
{
	double s,f;
    int n,i,m;
	cin>>m;
	while(m--)
	{
		cin>>n;
		s=0;
		for(f=i=1;i<=n;i++)
		{
			s+=f/i;       //省去了判断是奇偶项
			f*=-1;
		}
		printf("%.2lf\n",s);
	}
   return 0;
}