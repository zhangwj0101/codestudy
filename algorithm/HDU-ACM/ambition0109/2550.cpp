////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-11 22:38:58
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2550
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int t,n,i,j,arrow[50][2],tmp;
	for(scanf("%d",&t);t>0;t--)
	{
		for(scanf("%d",&n),i=0;i<n;i++)
			scanf("%d%d",&arrow[i][0],&arrow[i][1]);
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
				if(arrow[i][0]>arrow[j][0])
				{
					tmp=arrow[i][0],arrow[i][0]=arrow[j][0],arrow[j][0]=tmp;
					tmp=arrow[i][1],arrow[i][1]=arrow[j][1],arrow[j][1]=tmp;
				}
		for(i=0;i<n;i++)
		{
			for(j=0;j<arrow[i][1];j++)
			{
				printf(">+");
				for(tmp=0;tmp<arrow[i][0]-2;tmp++)
					printf("-");
				printf("+>\n");
			}
			printf("\n");
		}
	}
}