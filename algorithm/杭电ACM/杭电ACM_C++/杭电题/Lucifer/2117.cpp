////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-15 15:06:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2117
////Problem Title: 
////Run result: Accept
////Run time:500MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int n,m,r,i;
	while(scanf("%d%d",&n,&m)==2)
	{
		if(n==1)
			puts("0");
		else
		{
		for(r=10,i=1;i<m;i++)
		{
			r%=n;
			r*=10;
			if(!r)break;
		}
		printf("%d\n",r/n);
		}
	}
	return 0;
}