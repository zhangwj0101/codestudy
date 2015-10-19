////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-18 16:41:42
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1859
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:296KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;
#define inf 1000000
int main()
{
	int j;
	int minx,miny,maxx,maxy;
	int x,y;
	do
	{
		j=0;
		minx=miny=inf;
		maxx=maxy=-inf;
		while(scanf("%d%d",&x,&y),x||y)
		{
			if(x<minx)
				minx=x;
			if(x>maxx)
				maxx=x;
			if(y<miny)
				miny=y;
			if(y>maxy)
				maxy=y;
			j++;
		}
		if(j)
			printf("%d %d %d %d\n",minx,miny,maxx,maxy);	
	}while(j);
	return 0;
}