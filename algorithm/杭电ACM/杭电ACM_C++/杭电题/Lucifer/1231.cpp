////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-02 20:46:48
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1231
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:248KB
//////////////////System Comment End//////////////////
//�ص㣡
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <limits.h>
void main()
{
	int *num;
	int i,k,thisSum,maxSum,last;
	while (scanf("%d",&k),k)
	{
		num=(int *)malloc(k*sizeof(int));
		thisSum=0;
		maxSum=last=LONG_MIN;
		for (i=0;i<k;i++)
		{
			scanf("%d",&(num[i]));
			thisSum+=num[i];
			if(thisSum>maxSum)
			{
				last=i;
				maxSum=thisSum;
			}
			if(thisSum<0)
				thisSum=0;
		}
		if(maxSum>0)
		{
			thisSum=0;
			for(i=last;i>=0;i--)
			{
				thisSum+=num[i];
				if(thisSum==maxSum)
				{
					printf("%d %d %d\n",maxSum,num[i],num[last]);
					break;
				}
			}
		}
		else if(maxSum<0)printf("0 %d %d\n",num[0],num[k-1]);
		else  puts("0 0 0");

		free(num);
	}

}