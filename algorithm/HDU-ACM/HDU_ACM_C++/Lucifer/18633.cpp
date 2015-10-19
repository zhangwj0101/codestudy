////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-18 17:46:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1863
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:340KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;
#define M 100
#define inf 100000000
int mat[M][M];
char v[M];
int m;
int prim()
{
	int i,j,k;
	int ret;
	int min[M];
	for(i=0;i<m;i++)
		min[i]=inf;
	memset(v,0,M);
	min[0]=0;
	ret=0;
	for(i=0;i<m;i++)
	{
		for(k=-1,j=0;j<m;j++)
			if(!v[j]&&(k==-1||min[k]>min[j]))
				k=j;
		v[k]=1;
		ret+=min[k];
		if(ret>inf)
		{
			ret=inf;
			return ret;
		}
		for(j=0;j<m;j++)
			if(!v[j]&&(min[j]>mat[k][j]))
				min[j]=mat[k][j];


	}
	return ret;
}
int main()
{
	int n,a,b,cost;
	int i,j;
	while(scanf("%d%d",&n,&m),n)
	{
		for(i=0;i<m;i++)
			for(j=0;j<m;j++)
				mat[i][j]=inf;
		while(n--)
		{
			scanf("%d%d%d",&a,&b,&cost);
			mat[a-1][b-1]=mat[b-1][a-1]=cost;
		}
		n=prim();
		if(n>=inf)
			puts("?");
		else
			printf("%d\n",n);
	}
	return 0;
}