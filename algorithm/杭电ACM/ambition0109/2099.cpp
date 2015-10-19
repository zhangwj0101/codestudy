////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-16 20:20:48
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2099
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int num,mod,i,j,sam[100];
	while(scanf("%d%d",&num,&mod),num||mod)
	{
		num=num*100;
		for(i=0,j=0;i<100;i++)
			if(!((num+i)%mod))
			{sam[j]=i;j++;}
		if(j)
			printf("%02d",sam[0]);
		for(i=1;i<j;i++)
			printf(" %02d",sam[i]);
		printf("\n");
	}
}