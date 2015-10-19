////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-07 21:58:34
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1863
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int str[1000000][3],sign[1000000];
main()
{
	int n,m,i,j,city[1000],k1,k2,t,count,s;
	while(scanf("%d%d",&m,&n),m)
	{
		for(i=1;i<=n;i++)
			city[i]=i;
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&str[i][0],&str[i][1],&str[i][2]);
			sign[i]=i;
		}
		for(count=0,s=0,i=0;i<m;i++)
		{
			t=1;
			for(j=i+1;j<m;j++)
				if(str[sign[i]][2]>str[sign[j]][2])
				{t=sign[i];sign[i]=sign[j];sign[j]=t;}
			k1=str[sign[i]][0];
			while(city[k1]!=k1)
				k1=city[k1];
			k2=str[sign[i]][1];
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
		if(count<n-1)
			printf("?\n");
		else
			printf("%d\n",s);
	}
}
