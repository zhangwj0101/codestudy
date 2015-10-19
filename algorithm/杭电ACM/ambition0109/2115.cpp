////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-18 15:51:11
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2115
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n[100],i,j,time[100][10],rank[100][10],m,mm,s,c=0;
	char name[100][10][20];
	while(scanf("%d",&n[c]),n[c])
	{
		for(i=0;i<n[c];i++)
		{
			scanf("%s %d:%d",name[c][i],&m,&s);
			time[c][i]=m*100+s;
		}
		for(i=0;i<n[c];i++)
		{
			rank[c][i]=1;
			for(j=0;j<n[c];j++)
				if(time[c][i]>time[c][j])
					rank[c][i]+=1;
		}
		c++;
	}
	mm=c;
	printf("Case #%d\n",1);
		for(i=0;i<n[0];i++)
		{
			for(j=0;j<n[0];j++)
				if(rank[0][j]==i+1)
					printf("%s %d\n",name[0][j],rank[0][j]);
		}
	for(c=1;c<mm;c++)
	{
		printf("\nCase #%d\n",c+1);
		for(i=0;i<n[c];i++)
		{
			for(j=0;j<n[c];j++)
				if(rank[c][j]==i+1)
					printf("%s %d\n",name[c][j],rank[c][j]);
		}
	}
}