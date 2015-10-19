////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-11 10:13:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1881
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
using namespace std;
struct BG  
{
	int h,l,t;
}bg[30];
int n;
int max1;
int cmp(BG b1,BG b2)
{
	return (b1.t)<(b2.t);
}

void dfs(int k,int h,int time,int remain)
{
	if (k>=n)
	{
		if (h>max1)
			max1=h;
	}
	else
	{
		if (remain+h>max1)
		{
			remain-=bg[k].h;
			dfs(k+1,h,time,remain);
			if (time+bg[k].l<=bg[k].t)
			{
				dfs(k+1,h+bg[k].h,time+bg[k].l,remain);
			}
		}
	}
}

int main()
{
	int i;
	int remain;
	while (scanf("%d",&n),n>=0)
	{
		max1=0;
		for (i=0;i<n;i++)
		{
			scanf("%d%d%d",&bg[i].h,&bg[i].l,&bg[i].t);
		}
		sort(bg,bg+n,cmp);
		for (remain=i=0;i<n;i++)
		{
			remain+=bg[i].h;
		}

		dfs(0,0,0,remain);
		printf("%d\n",max1);
	}
	return 0;
}