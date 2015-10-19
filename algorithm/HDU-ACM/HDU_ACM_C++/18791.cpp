////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-18 23:23:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1879
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:340KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
#define M 100
#define inf 1000000000
int mat[M][M];
char v[M];
int n;
int prim()
{
	int min[M];
	int i,j,k,ret;
	for(i=0;i<n;i++)
		min[i]=inf;
	memset(v,0,sizeof(v));
	
	ret=min[0]=0;
	for(i=0;i<n;i++)
	{
		for(k=-1,j=0;j<n;j++)
			if(!v[j]&&(k==-1||min[k]>min[j]))
				k=j;
		v[k]=1;
		ret+=min[k];
		for(j=0;j<n;j++)
			if(!v[j]&&(mat[j][k]<min[j]))
				min[j]=mat[j][k];
	}

	return ret;
}
int main()
{
	int len;
	int a,b,cost,state;
	while(scanf("%d",&n),n)
	{
		len=n*(n-1)/2;
		while(len--)
		{
			scanf("%d%d%d%d",&a,&b,&cost,&state);
			mat[a-1][b-1]=mat[b-1][a-1]=(state)?0:cost;
		}
		printf("%d\n",prim());
	}
	return 0;
}