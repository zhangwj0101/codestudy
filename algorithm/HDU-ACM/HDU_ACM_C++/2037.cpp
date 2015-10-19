////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-03 08:42:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2037
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
struct ORD
{
	int s,e,ord;
}D[101];
int cmp(const void *a, const void *b)
{
	ORD*c=(ORD*)a;
	ORD*d=(ORD*)b;
	if((*c).s==(*d).s)
		return (*c).e-(*d).e;
	else
		return (*c).s-(*d).s;
}

int main()                                //合理安排（目标是能看尽量多的完整节目）
{
	int i,n,j,max;
	while(cin>>n&&n)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&D[i].s,&D[i].e);
			D[i].ord=1;
		}
		qsort(D,n,sizeof(D[0]),cmp);
		for(max=0,i=n-2;i>=0;i--)
		{
			for(j=i+1;j<n;j++)
			{
				if(D[i].e<=D[j].s&&D[i].ord<D[j].ord+1)
					D[i].ord=D[j].ord+1;
			}
			if(max<D[i].ord)
				max=D[i].ord;
		}
		printf("%d\n",max);
	}
   return 0;
}