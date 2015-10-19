////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-20 14:20:28
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1059
////Problem Title: 
////Run result: Accept
////Run time:375MS
////Run memory:408KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
int num[150001],v[90];
main()
{
	int m,i,j,sum,t=1;
	while(1)
	{
		for(i=0;i<91;i++)
			v[i]=0;
		for(i=0,sum=0;i<6;i++)
		{
			scanf("%d",&v[i*15]);
			sum+=v[i*15]*(i+1);
			for(j=1;j<15;j++)
			{
				if(v[i*15]>=pow(2,j-1))
				{
					v[i*15+j]=(int)pow(2,j-1)*(i+1);
					v[i*15]-=(int)pow(2,j-1);
				}
			}
			v[i*15]*=(i+1);
		}
		m=sum/2;
		if(sum==0) return 0;
		else if(sum%2) {printf("Collection #%d:\nCan't be divided.\n\n",t++);continue;}
		for(i=0;i<=m;i++)
			num[i]=0;
		for(i=0;i<90;i++)
		{
			if(v[i]!=0)
			for(j=m;j>=v[i];j--)
			{
				if(num[j-v[i]]+v[i]>num[j])
					num[j]=num[j-v[i]]+v[i];
			}
		}
		if(num[m]!=m) printf("Collection #%d:\nCan't be divided.\n\n",t++);
		else printf("Collection #%d:\nCan be divided.\n\n",t++);
	}
}