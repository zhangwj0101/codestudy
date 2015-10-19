////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-04 13:13:14
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1202
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,d;
	double sfd,f,sf,s;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0,sf=0,sfd=0;i<n;i++)
		{
			scanf("%lf%lf",&f,&s);
			if(s==-1)
				continue;
			else if(s<60)
				d=0;
			else if(s<70)
				d=1;
			else if(s<80)
				d=2;
			else if(s<90)
				d=3;
			else if(s<=100)
				d=4;
			sf+=f;
			sfd+=f*(double)d;
		}
		if(sf)
			printf("%.2lf\n",sfd/sf);
		else
			printf("-1\n");
	}
}