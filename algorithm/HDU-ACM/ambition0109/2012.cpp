////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-06 09:45:03
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2012
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int x,y,i,tmp,m,j;
	while(scanf("%d%d",&x,&y),x||y)
	{
		for(i=x,j=0;i<=y;i++)
		{
			for(tmp=i*i-i+41,m=tmp-1;m>1;m--)
				if(!(tmp%m))
				{j=1;break;}
			if(j) break;
		}
		if(j)
			printf("Sorry\n");
		else
			printf("OK\n");
	}
}