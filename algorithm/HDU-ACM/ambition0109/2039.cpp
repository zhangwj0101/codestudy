////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-08 12:28:51
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2039
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	double a,b,c;
	int n;
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%lf%lf%lf",&a,&b,&c);
		if(((a+b)>c)&&((a+c)>b)&&((b+c)>a))
			printf("YES\n");
		else
			printf("NO\n");
	}
}