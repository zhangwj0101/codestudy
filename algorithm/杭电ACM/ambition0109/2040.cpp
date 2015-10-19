////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-09 16:20:19
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2040
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,a,b,na,nb;
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d%d",&a,&b);
		for(i=1,na=0;i<=a/2;i++)
			if(!(a%i))
				na+=i;
		for(i=1,nb=0;i<=b/2;i++)
			if(!(b%i))
				nb+=i;
		if(na==b&&nb==a)
			printf("YES\n");
		else
			printf("NO\n");
	}
}