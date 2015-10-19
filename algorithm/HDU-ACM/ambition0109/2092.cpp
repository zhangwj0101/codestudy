////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-15 20:48:12
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2092
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
main()
{
	int i,x,y,t,w;
	while(scanf("%d%d",&x,&y),x||y)
	{
		if(x>0) t=1;
		else t=-1;
		for(i=t,w=0;abs(i)<=abs(y);i+=t)
			if(!(y%i))
				if(y/i+i==x)
				{w=1;break;}
		if(w)
			printf("Yes\n");
		else
			printf("No\n");
	}
}