////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-01-26 12:36:42
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1235
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,num[1000],same,count;
	while(scanf("%d",&n),n)
	{
		count=0;
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);
		scanf("%d",&same);
		for(i=0;i<n;i++)
			if(num[i]==same)
				count++;
		printf("%d\n",count);
	}
}