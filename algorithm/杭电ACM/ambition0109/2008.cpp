////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-04 12:31:28
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2008
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	float num;
	int n,i,s1,s2,s3;
	while(scanf("%d",&n),n!=0)
	{
		for(i=0,s1=s2=s3=0;i<n;i++)
		{
			scanf("%f",&num);
			if(num<0)
				s1++;
			else if(num==0)
				s2++;
			else
				s3++;
		}
		printf("%d %d %d\n",s1,s2,s3);
	}
}