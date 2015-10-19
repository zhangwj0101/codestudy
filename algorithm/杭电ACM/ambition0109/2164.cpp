////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-23 13:33:25
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2164
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,fp,sp;
	char fch,sch;
	for(scanf("%d",&n);n>0;n--)
	{
		for(scanf("%d",&m),getchar(),fp=sp=0;m>0;m--)
		{
			scanf("%c %c",&fch,&sch);
			getchar();
			if(fch==sch) continue;
			else
			{
				if((fch=='R'&&sch=='S')||(fch=='P'&&sch=='R')||(fch=='S'&&sch=='P')) fp+=1;
				else if((sch=='R'&&fch=='S')||(sch=='P'&&fch=='R')||(sch=='S'&&fch=='P')) sp+=1;
			}
		}
		if(sp==fp) printf("TIE\n");
		else if(sp>fp) printf("Player 2\n");
		else if(fp>sp) printf("Player 1\n");
	}
}