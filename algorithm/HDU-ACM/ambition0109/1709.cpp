////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-21 21:19:30
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1709
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:288KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
int number[10001],temp[10001];
main()
{
	int n,i,j,t,sum,num[100],count;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0,sum=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			sum+=num[i];
		}
		for(i=1;i<=sum;i++) number[i]=0;
		number[0]=1; number[num[0]]=1;
		for(i=1;i<n;i++)
		{
			for(j=0;j<=sum;j++) temp[j]=0;
			for(j=0;j<=sum;j++) temp[abs(num[i]-j)]+=number[j];
			for(j=1;j<=sum;j++) temp[num[i]+j]+=number[j];
			for(j=0;j<=sum;j++) number[j]+=temp[j];
		}
		for(i=1,count=0;i<=sum;i++)
			if(!number[i]) count++;
		printf("%d\n",count);
		if(count)
		{
			for(i=1,t=0;i<=sum;i++)
				if(!number[i])
				{
					printf("%d",i);t++;
					if(t!=count) printf(" ");
				}
			printf("\n");
		}
	}
}