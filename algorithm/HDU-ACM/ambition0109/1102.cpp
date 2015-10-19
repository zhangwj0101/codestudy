////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-08 14:23:03
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1102
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:332KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int str[10000][5],sign[10000];
main()
{
	int n,i,ii,j,k1,k2,c1,c2,c,t,city[200],count,s;
	while(scanf("%d",&n)!=EOF&&n)
	{
		for(i=0;i<200;i++)
			city[i]=i;
		for(i=0,ii=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				scanf("%d",&c);
				if(i<j)
				{
					str[ii][0]=i;
					str[ii][1]=j;
					str[ii][2]=c;
					ii++;
				}
			}
		for(scanf("%d",&t),count=0;t>0;t--)
		{
			scanf("%d%d",&c1,&c2);
			c1-=1;c2-=1;
			k1=city[c1];
			while(city[k1]!=k1)
				k1=city[k1];
			k2=city[c2];
			while(city[k2]!=k2)
				k2=city[k2];
			if(k1!=k2)
			{
				if(city[k2]>city[k1])
					city[k2]=city[c1];
				else
					city[k1]=city[c2];
				count++;
			}
		}
		for(i=0;i<ii;i++)
			sign[i]=i;
		for(i=0,s=0;i<ii;i++)
		{
			for(j=i+1;j<ii;j++)
				if(str[sign[i]][2]>str[sign[j]][2])
				{t=sign[i];sign[i]=sign[j];sign[j]=t;}
			k1=city[str[sign[i]][0]];
			while(city[k1]!=k1)
				k1=city[k1];
			k2=city[str[sign[i]][1]];
			while(city[k2]!=k2)
				k2=city[k2];
			if(k1!=k2)
			{
				if(city[k2]>city[k1])
					city[k2]=city[str[sign[i]][0]];
				else
					city[k1]=city[str[sign[i]][1]];
				count++;s+=str[sign[i]][2];
			}
			if(count==n-1)
				break;
		}
			printf("%d\n",s);
	}
}