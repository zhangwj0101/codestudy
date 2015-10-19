////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-15 12:10:08
////Compiler: GUN C
//////////////////////////////////////////////////////
////Problem ID: 1231
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int main()
{
	int k,arr[10000],i;
	int sum,thissum,last;
	while(scanf("%d",&k),k)
	{
		sum=-1;
		thissum=0;
		last=0;
		for(i=0;i<k;i++)
		{
			scanf("%d",&arr[i]);
			thissum+=arr[i];
			if(thissum>=0)
			{
				if(thissum>sum)
					sum=thissum,last=i;
			}
			else
			{
				thissum=0;
			}
		}
		if(sum<0)
		{
			printf("0 %d %d\n",arr[0],arr[k-1]);
			continue;
		}
		thissum=0;
		for(i=last;i>=0;i--)
		{
			thissum+=arr[i];
			if(thissum>=sum)
				break;
		}
		printf("%d %d %d\n",sum,arr[i],arr[last]);
	}
	return 0;
}
