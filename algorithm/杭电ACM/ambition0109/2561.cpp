////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-11 22:57:30
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2561
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,i,j,num[10],tmp;
	for(scanf("%d",&n);n>0;n--)
	{
		for(scanf("%d",&m),i=0;i<m;i++)
			scanf("%d",&num[i]);
		for(i=0;i<2;i++)
			for(j=i+1;j<m;j++)
				if(num[i]>num[j])
				 {tmp=num[i];num[i]=num[j];num[j]=tmp;}
		printf("%d\n",num[1]);
	}
}