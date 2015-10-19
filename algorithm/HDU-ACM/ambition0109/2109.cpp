////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-16 16:03:03
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2109
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,j,t,num[2][100],vs[2];
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&num[0][i]);
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
				if(num[0][i]>num[0][j])
					t=num[0][i],num[0][i]=num[0][j],num[0][j]=t;
		for(i=0;i<n;i++)
			scanf("%d",&num[1][i]);
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
				if(num[1][i]>num[1][j])
					t=num[1][i],num[1][i]=num[1][j],num[1][j]=t;
		vs[0]=vs[1]=0;
		for(i=0;i<n;i++)
			if(num[0][i]>num[1][i])
				vs[0]+=2;
			else if(num[0][i]<num[1][i])
				vs[1]+=2;
			else
			{vs[0]+=1;vs[1]+=1;}
		printf("%d vs %d\n",vs[0],vs[1]);
	}
}