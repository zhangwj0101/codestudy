////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-10 19:19:08
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2053
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,lamp;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1,lamp=1;i<n;i++)
			if(!(n%i))
			{
				if(lamp)
					lamp=0;
				else
					lamp=1;
			}
		printf("%d\n",lamp);
	}
}