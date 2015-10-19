////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-11 19:34:02
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1230
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int i,j,a[25],b[25],ra[25],rb[25],sum[26],m,x;
	int system[26]={101,97,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
	while(1)
	{
		for(i=0,x=0;i<25;i++)
		{a[i]=b[i]=ra[i]=rb[i]=sum[i]=0;}
		sum[25]=0;
		scanf("%d",&a[0]);i=1;
		while(getchar()==',')
			scanf("%d",&a[i++]);
		m=i;
		for(i=0;i<m;i++)
			ra[25-m+i]=a[i];
		scanf("%d",&b[0]);i=1;
		while(getchar()==',')
			scanf("%d",&b[i++]);
		m=i;
		for(i=0;i<m;i++)
			rb[25-m+i]=b[i];
		for(i=0,x=1;i<25;i++)
			if(a[i]||b[i])
			{x=0;break;}
		if(x)	break;
		for(i=25;i>1;i--)
		{
			sum[i]+=ra[i-1]+rb[i-1];
			if(sum[i]>=system[i])
			{
				sum[i]-=system[i];
				sum[i-1]+=1;
			}
		}
		for(i=0;i<26;i++)
			if(sum[i])
				break;
		printf("%d",sum[i]);
		for(i+=1;i<26;i++)
			printf(",%d",sum[i]);
		printf("\n");
	}
}