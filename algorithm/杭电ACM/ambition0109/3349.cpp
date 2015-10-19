////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-14 11:40:09
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 3349
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
main()
{
	int n;
	double a,b,l,temp,ans;
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%lf%lf%lf",&l,&a,&b);
		if(b>a)
			temp=a,a=b,b=temp;
		if(b>=2*sqrt(2.)*l)
			ans=l*l;
		else if(b>=sqrt(2.)*l)
			ans=l*l-(sqrt(2.)*l-1./2.*b)*(sqrt(2.)*l-1./2.*b);
		else
			ans=1./4.*b*b;
		printf("%.4lf\n",ans);
	}
}
