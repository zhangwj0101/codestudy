////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-28 12:44:18
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 3353
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
main()
{
	int n,m,i,k,kk,sum,num[2],o=1;
	while(scanf("%d%d",&n,&m),n||m)
	{
		for(i=2,kk=0,sum=0;i<=(m>n?m:n);i++)
		{
			if(!(n%i)||!(m%i))
			{
				for(k=0;!(n%i);k++)
					n=n/i;
				num[0]=k;
				for(k=0;!(m%i);k++)
					m=m/i;
				num[1]=k;
				sum+=abs(num[0]-num[1]);
				kk++;
			}
			if(!((n-1)||(m-1)))
				break;
		}
		printf("%d. %d:%d\n",o++,kk,sum);
	}
}