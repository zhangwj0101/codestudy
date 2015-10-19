////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-31 12:55:45
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2037
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,j,m,num[100][2],t;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%d%d",&num[i][0],&num[i][1]);
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
				if(num[i][1]>num[j][1])
				{t=num[i][1],num[i][1]=num[j][1],num[j][1]=t;
				t=num[i][0],num[i][0]=num[j][0],num[j][0]=t;}
		for(i=1,m=num[0][1],t=1;i<n;i++)
			if(m<=num[i][0])
			{t+=1;m=num[i][1];}
		printf("%d\n",t);
	}
}