////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-07 13:24:05
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1272
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:980KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,r1,r2,o,s[100001],is[100001],s1=0,s2=0,t;
	while(scanf("%d%d",&s1,&s2),s1+1||s2+1)
	{
		for(i=1,t=1;i<100001;i++)
		{s[i]=i;is[i]=0;}
		while(s1||s2)
		{
			if(s1!=s2)
			{
				r1=s1;
				while(s[r1]!=r1)
					r1=s[r1];
				r2=s2;
				while(s[r2]!=r2)
					r2=s[r2];
				if(r1==r2)
					t=0;
				if(t)
				{
					is[s1]=is[s2]=1;
					if(s[r2]>s[r1])
						s[r2]=s[s1];
					else
						s[r1]=s[s2];
				}
			}
			scanf("%d%d",&s1,&s2);
		}
		if(t)
		{
			for(i=1;i<100001;i++)
			{
				r1=i;
				while(s[r1]!=r1)
					r1=s[r1];
				s[i]=r1;
			}

			for(i=1,o=0;i<100001;i++)
					if(is[i]&&o==0)
						o=s[i];
					else if(is[i]&&o)
					{
						if(o!=s[i])
						{t=0;break;}
					}
		}/*
		for(i=1;i<=10;i++)
				printf("%d ",is[i]);
			printf("\n");
			for(i=1;i<=10;i++)
				printf("%d ",s[i]);
			printf("\n");*/
		if(t)
			printf("Yes\n");
		else
			printf("No\n");
	}
}