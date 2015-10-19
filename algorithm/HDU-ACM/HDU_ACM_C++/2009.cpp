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
			t=sqrt(t);              //t是double类型的，可以防止因开方生成的小数丢失（相当于n而言）
			s+=t;
		}
		printf("%.2lf\n",s);     //%.2lf,double型
    }
   return 0;
}