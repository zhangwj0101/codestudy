////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-01-22 10:00:32
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1003
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int t,n,a,i,j,s,ss,qin,hou,k;
	while(scanf("%d",&t)!=EOF)
	{
		for(i=0;i<t;i++)
		{
			scanf("%d",&n);
			s=-9999;ss=0;qin=0;hou=0;k=0;
			for(j=0;j<n;j++)
			{
				scanf("%d",&a);
				ss+=a;
				if(ss>s)
				{s=ss;qin=k;hou=j;}
				if(ss<0)
				{ss=0;k=j+1;}
			}
			printf("Case %d:\n",i+1);
			printf("%d %d %d\n",s,qin+1,hou+1);
			if(i!=t-1)
				printf("\n");
		}
	}
}