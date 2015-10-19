////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-15 12:08:41
////Compiler: GUN C
//////////////////////////////////////////////////////
////Problem ID: 1234
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
int main()
{
	int n,m;
	char name[20];
	int hh,mm,ss;
	int min,max;
	char minn[20],maxn[20];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		max=-1;
		min=1000000000;
		while(m--)
		{
			scanf("%s",name);
			scanf("%d:%d:%d",&hh,&mm,&ss);
			if(hh*10000+mm*100+ss<min)
			{
				min=hh*10000+mm*100+ss;
				strcpy(minn,name);
			}
				
			scanf("%d:%d:%d",&hh,&mm,&ss);
			if(hh*10000+mm*100+ss>max)
			{
				max=hh*10000+mm*100+ss;
				strcpy(maxn,name);
			}
		}
		printf("%s %s\n",minn,maxn);
	}
	return 0;
}
