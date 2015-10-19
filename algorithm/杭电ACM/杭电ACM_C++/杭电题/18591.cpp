////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-04 22:59:57
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1859
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
void main()
{
	int x,y,k;
	int minx,miny,maxx,maxy;
	do
	{
		k=0;
		minx=miny=300;
		maxx=maxy=-300;
		while (scanf("%d%d",&x,&y)==2,x||y)
		{
			if (minx>x)
				minx=x;
			if (maxx<x)
				maxx=x;

			if (miny>y)
				miny=y;
			if (maxy<y)
				maxy=y;
			k++;
		}
		if (!k)break;
		printf("%d %d %d %d\n",minx,miny,maxx,maxy);
	}while(1);
}
