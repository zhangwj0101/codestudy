////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-02 20:44:51
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1234
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
void main()
{
	int t,n,i,m,j,min,max,hh,mm,ss,time,k;
	char openman[80],closeman[80],temp[80];
	while (scanf("%d",&n)==1)
	{
		for (i=0;i<n;i++)
		{
			min=1000000,max=-1;
			scanf("%d",&m);
			for (j=0;j<m;j++)
			{
				scanf("%s",temp);
				for (k=0;k<2;k++)
				{
					scanf("%d:%d:%d",&hh,&mm,&ss);
					time=hh*10000+mm*100+ss;
					if (min>time)
					{
						min=time;
						strcpy(openman,temp);
					}
					if(max<time)
					{
						max=time;
						strcpy(closeman,temp);
					}
				}
			}
			printf("%s %s\n",openman,closeman);
		}
	}
}