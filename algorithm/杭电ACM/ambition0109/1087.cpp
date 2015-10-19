////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-24 12:32:22
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1087
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,j,num[1000],sum[1000],max,mmax;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);
		mmax=sum[0]=num[0];
		for(i=1;i<n;i++)
		{
			for(j=0,max=0;j<i;j++)
				if(num[j]<num[i])
					if(sum[j]>max)
						max=sum[j];
			sum[i]=max+num[i];
			if(mmax<sum[i])
				mmax=sum[i];
		}
		printf("%d\n",mmax);
	}
}