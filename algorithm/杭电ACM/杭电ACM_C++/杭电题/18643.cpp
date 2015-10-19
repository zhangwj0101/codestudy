////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-18 20:22:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1864
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:308KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;
double ticket[32];
int k;
double maxv,limit;
#define eps 1e-6
void dfs(int cur,double v,double remain)
{
	if(cur>=k)
		return ;
	if(remain+v>maxv)
	{
		remain-=ticket[cur];
		dfs(cur+1,v,remain);
		v+=ticket[cur];
		if(v<limit+eps)
		{
			if(v>maxv)maxv=v;
			dfs(cur+1,v,remain);
		}
	}
}
int main()
{
	int n,m;
	double a[3];
	int i,j;
	int flag;
	char type;
	double price;
	double remain;
	while(scanf("%lf%d",&limit,&n),n)
	{
		k=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&m);
			flag=1;
			a[0]=a[1]=a[2]=0;
			while(m--)
			{
				scanf(" %c:%lf",&type,&price);
				if(type>'C'||type<'A')flag=0;
				if(flag)
				{
					a[type-'A']+=price;
				}
			}
			for(j=0;j<3;j++)
				if(a[j]>600)
				{
					flag=0;
					break;
				}
			if(flag)
			{
				ticket[k++]=a[0]+a[1]+a[2];
			}
		}
		maxv=0;
		for(remain=i=0;i<k;i++)
			remain+=ticket[i];
		dfs(0,0,remain);
		printf("%.2lf\n",maxv);
	}
	return 0;
}