////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-19 17:57:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2602
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include <algorithm>
using namespace std;
#define M 1010

int maxv(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int t,i,j;
	int val[M],vol[M];
	int c1[M],c2[M];
	int n,v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&v);
		for(i=0;i<n;i++)
			scanf("%d",val+i);
		for(i=0;i<n;i++)
			scanf("%d",vol+i);
		
		memset(c1,0,(v+1)*sizeof(int));
		memset(c2,0,(v+1)*sizeof(int));

		for(i=0;i<n;i++)
		{
			for(j=0;j<=v;j++)
			{
				if(j-vol[i]>=0)
					c1[j]=maxv(c2[j],c2[j-vol[i]]+val[i]);
				else
					c1[j]=c2[j];
			}
			memcpy(c2,c1,(v+1)*sizeof(int));
		}
		printf("%d\n",c2[v]);
	}
	return 0;
}