////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-03 08:43:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2062
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:0KB
//////////////////System Comment End//////////////////
//比较难理解
#include<iostream>
using namespace std;
int main()
{
	int n,i,s[21];
	__int64 m,t,c[21]={0};
	for(i=1;i<21;i++)
		c[i]=c[i-1]*(i-1)+1;
	while(scanf("%d%I64d",&n,&m)==2)
	{
		for(i=0;i<21;i++)
			s[i]=i;
		while(n--&&m)
		{
			if(t=m/c[n+1]+((m%c[n+1])?1:0))
			{
				printf("%d",s[t]);
				for(i=t;i<=n;s[i]=s[i+1],i++);
				m-=(t-1)*c[i]+1;
				putchar(m?' ':'\n');
			}
		}
	}
   return 0;
}