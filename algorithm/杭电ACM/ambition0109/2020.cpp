////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-05 16:01:57
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2020
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
main()
{
	int n,i,j,num[100],tmp;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
				if(abs(num[i])<abs(num[j]))
					tmp=num[i],num[i]=num[j],num[j]=tmp;
		printf("%d",num[0]);
		for(i=1;i<n;i++)
			printf(" %d",num[i]);
		printf("\n");
	}
}