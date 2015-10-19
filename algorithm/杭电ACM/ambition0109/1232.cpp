////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-06 22:15:22
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1232
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,i,j,k,min,max,s[1000],s1,s2,count;
	while(scanf("%d",&n),n)
	{
		for(i=1;i<=n;i++)
			s[i]=i;
		for(scanf("%d",&m);m>0;m--)
		{
			scanf("%d%d",&s1,&s2);
			max=s[s1]>s[s2]?s[s1]:s[s2];
			min=s[s1]>s[s2]?s[s2]:s[s1];
			for(i=1;i<=n;i++)
				if(s[i]==max)
					s[i]=min;
		}
		for(i=1,count=0;i<=n;i++)
		{
			for(k=1;k<i;k++)
				if(s[i]==s[k])
					break;
			if(k==i)
				count++;
		}
		printf("%d\n",count-1);
	}
}