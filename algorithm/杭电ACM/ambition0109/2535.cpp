////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-06 15:09:02
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2535
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,j,num[100],t,count;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(num[i]>num[j])
				{t=num[i];num[i]=num[j];num[j]=t;}
		for(i=0,count=0;i<n/2+1;i++)
			count+=num[i]/2+1;
		printf("%d\n",count);
	}
}