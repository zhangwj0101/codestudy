////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-18 22:22:10
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1881
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:308KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;
int n;
int maxv;
struct REC
{
	int h,l,t;
}rec[32];
bool cmp(REC a,REC b)
{
	return a.t-b.t<0;
}

void dfs(int cur ,int v,int time)
{
	if(cur>=n)
		return ;
	dfs(cur+1,v,time);
	time+=rec[cur].l;
	if(time<=rec[cur].t)
	{
		v+=rec[cur].h;
		if(v>maxv)
			maxv=v;
		dfs(cur+1,v,time);
	}
}

int main()
{
	int i;
	while(scanf("%d",&n)&&n>=0)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&rec[i].h,&rec[i].l,&rec[i].t);	
		}
		sort(rec,rec+n,cmp);
		maxv=0;
		dfs(0,0,0);
		printf("%d\n",maxv);
	}
	return 0;
}