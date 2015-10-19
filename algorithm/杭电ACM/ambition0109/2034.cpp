////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-09 16:10:07
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2034
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,i,j,nnum[100],mnum[100],tmp,x,y;
	while(scanf("%d%d",&n,&m),n||m)
	{
		for(i=0;i<n;i++)
			scanf("%d",&nnum[i]);
		for(i=0;i<m;i++)
			scanf("%d",&mnum[i]);
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
				if(nnum[i]>nnum[j])
				{tmp=nnum[i];nnum[i]=nnum[j];nnum[j]=tmp;}
		for(i=0,y=1;i<n;i++)
		{
			for(j=0,x=0;j<m;j++)
				if(mnum[j]==nnum[i])
				{x=1;break;}
			if(x)
				continue;
			y=0;
			printf("%d ",nnum[i]);
		}
		if(y)
			printf("NULL");
		printf("\n");
	}
}