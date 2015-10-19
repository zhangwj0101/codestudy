////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-04 20:21:26
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2010
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int m,n,u,t,h,i,j;
	int num,sum,all[5];
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		for(num=m,i=0;num<=n;num++)
		{
			u=num%10;
			t=(num/10)%10;
			h=(num/100);
			sum=u*u*u+t*t*t+h*h*h;
			if(sum==num)
				all[i]=num,i++;
		}
		if(!i)
			printf("no\n");
		else
		{
			printf("%d",all[0]);
			j=1;
			while(j<i)
			{
				printf(" %d",all[j]);
				j++;
			}
			printf("\n");
		}
	}
}