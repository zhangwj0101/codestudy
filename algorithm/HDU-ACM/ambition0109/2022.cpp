////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-06 10:23:26
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2022
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
main()
{
	int n,m,i,j,score,mn,mm,ms;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0,ms=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				scanf("%d",&score);
				if(abs(ms)<abs(score))
					mn=i+1,mm=j+1,ms=score;
			}
		printf("%d %d %d\n",mn,mm,ms);
	}
}