////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-22 23:52:21
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1303
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int hush[100];
main()
{
	int n,i,count;
	while(scanf("%d",&n),n+1)
	{
		for(i=0;i<100;i++) hush[i]=0;
		hush[n]=1;
		while(scanf("%d",&n),n)
			hush[n]=1;
		for(i=1,count=0;i<50;i++)
			if(hush[i]&&hush[2*i])
				count++;
		printf("%d\n",count);
	}
}