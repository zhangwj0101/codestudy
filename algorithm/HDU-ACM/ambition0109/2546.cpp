////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-20 15:46:48
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2546
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int money[1001],num[1001];
main()
{
    int n,m,i,j,max;
    while(scanf("%d",&n),n)
    {
		for(i=0,max=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			if(num[i]>num[max]) max=i;
		}
		if(max!=0)
		{num[0]^=num[max];num[max]^=num[0];num[0]^=num[max];}
		scanf("%d",&m);
		if(m<5) {printf("%d\n",m);continue;}
		m=m-5;
		for(i=0;i<=m;i++)
			money[i]=-1;
		money[0]=0;
		for(i=1;i<n;i++)
		{
			for(j=m;j>=num[i];j--)
			{
				if(money[j-num[i]]!=-1)
				if(money[j-num[i]]+num[i]>money[j])
					money[j]=money[j-num[i]]+num[i];
			}
		}
		for(i=m;i>0;i--)
			if(money[i]!=-1)break;
		printf("%d\n",m-i+5-num[0]);
    }
}