////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-12 18:27:26
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2503
////Problem Title: 
////Run result: Accept
////Run time:437MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,a,b,c,d,x,y,m;
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		x=a*d+c*b;
		y=b*d;
		m=(x>y?y:x)/2;
		for(i=2;i<=m;)
		{
			if(!(x%i)&&!(y%i))
				x/=i,y/=i;
			else
				i++;
		}
		printf("%d %d\n",x,y);
	}
}