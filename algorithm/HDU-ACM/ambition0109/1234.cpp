////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-15 23:02:00
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1234
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,i,j,time[3],open,close,tmp,mo,mc;
	char id[100][15];
	for(scanf("%d",&n);n>0;n--)
	{
		open=240000;close=0;
		for(scanf("%d",&m),i=0;i<m;i++)
		{
			scanf("%s %d:%d:%d",id[i],&time[0],&time[1],&time[2]);
			tmp=time[0]*10000+time[1]*100+time[2];
			if(tmp<open) {open=tmp;mo=i;}
			scanf("%d:%d:%d",&time[0],&time[1],&time[2]);
			tmp=time[0]*10000+time[1]*100+time[2];
			if(tmp>close) {close=tmp;mc=i;}
		}
		printf("%s %s\n",id[mo],id[mc]);
	}
}