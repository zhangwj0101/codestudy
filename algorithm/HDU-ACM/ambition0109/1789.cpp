////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-01 13:18:52
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1789
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,i,ii,max,mm,num[1001][2],ans;
	for(scanf("%d",&n);n>0;n--)
	{
		for(scanf("%d",&m),i=0,max=0;i<m;i++)
		{
			scanf("%d",&num[i][0]);
			if(num[i][0]>max)
				max=num[i][0];
		}
		for(i=0;i<m;i++)
			scanf("%d",&num[i][1]);
		num[1000][1]=0;
		for(i=max;i>0;i--)
		{
			for(ii=0,mm=1000;ii<m;ii++)
				if(num[ii][0]==i)
					if(num[ii][1]>num[mm][1])
						mm=ii;
			for(ii=0;ii<m;ii++)
				if(num[ii][0]==i&&ii!=mm)
					num[ii][0]-=1;
		}
		for(i=0,ans=0;i<m;i++)
			if(num[i][0]==0)
				ans+=num[i][1];
		printf("%d\n",ans);
	}
}