////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-11 13:21:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2009
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	double s,t;
    int n,i,m;
    while(cin>>n>>m)
    {
		for(s=t=n,i=0;i<m-1;i++)
		{
			t=sqrt(t);
			s+=t;
		}
		printf("%.2lf\n",s);
    }
   return 0;
}