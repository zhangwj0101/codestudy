////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-04 10:56:31
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2033
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int ah,bh,am,bm,as,bs,n,i,ch,cm,cs;
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d%d%d%d%d%d",&ah,&am,&as,&bh,&bm,&bs);
		ch=cm=0;
		cs=as+bs;
		if(cs>=60)
		{cm+=1;cs-=60;}
		cm+=am+bm;
		if(cm>=60)
		{ch+=1;cm-=60;}
		ch+=ah+bh;
		printf("%d %d %d\n",ch,cm,cs);
	}
}