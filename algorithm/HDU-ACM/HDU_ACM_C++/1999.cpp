////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-11-01 14:36:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1999
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:1812KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int s[500001];
char a[1001];
int main()
{
	int i,j,t,n;
	for(i=1;i<=500000;i++)
	{
		for(j=i*2;j<500001;j+=i)
			s[j]+=i;
		if(s[i]<1001)a[s[i]]=1;		
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		puts(a[n]?"no":"yes");
	}
	return 0;
}