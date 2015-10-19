////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-02-26 20:42:47
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1229
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
void main()
{
	int a,b,c,k;
	int i;
	while(scanf("%d%d%d",&a,&b,&k),a||b)
	{
		c=a-b;
		for(i=0;i<k;i++)
		{
			if(c%10==0)
				c/=10;
			else
				break;
		}
		printf("%d\n",(i!=k)?a+b:-1);
	}

}