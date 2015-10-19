////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-25 14:59:41
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1058
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m=1,num[4],min,humble[6000],i1,i2,i3,i4;
	i1=i2=i3=i4=0;
	num[0]=num[1]=num[2]=num[3]=humble[0]=1;
	while(scanf("%d",&n),n)
	{
		for(;m<n;m++)
		{
			min=num[0]*2>num[1]*3?num[1]*3:num[0]*2;
			min=min>num[2]*5?num[2]*5:min;
			min=min>num[3]*7?num[3]*7:min;
			humble[m]=min;
			if(min==num[0]*2)
				num[0]=humble[++i1];
			if(min==num[1]*3)
				num[1]=humble[++i2];
			if(min==num[2]*5)
				num[2]=humble[++i3];
			if(min==num[3]*7)
				num[3]=humble[++i4];
		}
		printf("The %d",n);
		if(n%10==1&&n%100!=11) printf("st");
		else if(n%10==2&&n%100!=12) printf("nd");
		else if(n%10==3&&n%100!=13) printf("rd");
		else printf("th");
		printf(" humble number is ");
		printf("%d.\n",humble[n-1]);
	}
}