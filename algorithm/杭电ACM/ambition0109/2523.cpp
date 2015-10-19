////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-29 12:37:34
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2523
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
int num[1000],hush[2001];
main()
{
	int n,m,t,i,j,k;
	for(scanf("%d",&n);n>0;n--)
	{
		for(i=0;i<2001;i++)
			hush[i]=0;
		for(scanf("%d%d",&m,&k),i=0;i<m;i++)
		{
			scanf("%d",&num[i]);
			for(j=0;j<i;j++)
			{
				t=abs(num[i]-num[j]);
				hush[t]=1;
			}
		}
		for(i=0,t=0;i<2001;i++)
		{
			if(hush[i])	t++;
			if(t==k)	{printf("%d\n",i);break;}
		}
	}
}