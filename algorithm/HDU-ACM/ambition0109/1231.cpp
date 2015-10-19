////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-08 11:35:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1231
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include<stdio.h>
void main()
{
    int n,num[10020],start,end,t;
    int sum,max;
    while(scanf("%d",&n),n)
    {
		t=0;
        for(int i=0;i<n;i++){
            scanf("%d",&num[i]);
            if(num[i]>=0) t++;
        }
        if(t==0)
        {printf("0 %d %d\n",num[0],num[n-1]);continue;}
		max=-99999999;sum=0,start=0,end=0;
		for(int i=0,temp=0;i<n;i++)
		{
			sum+=num[i];
			if(sum>max)
			{max=sum;start=temp;end=i;}
			if(sum<0)
			{sum=0;temp=i+1;}
		}
		printf("%d %d %d\n",max,num[start],num[end]);
    }
}