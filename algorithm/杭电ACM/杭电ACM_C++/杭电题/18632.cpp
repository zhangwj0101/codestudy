////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-11 00:36:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1863
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:272KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define M 100
#define  inf 10000000
int Prim(int mat[][M],int m)
{
	int i,j,k;
	int min[M];
	char v[M];
	int ret=0;

	for (i=0;i<m;i++)min[i]=inf;
	memset(v,0,m);
	for (min[i=0]=0;i<m;i++)
	{
		for (k=-1,j=0;j<m;j++)
			if (!v[j]&&(k==-1||min[j]<min[k]))
				k=j;
		v[k]=1;
		for (ret+=min[k],j=0;j<m;j++)
			if (!v[j]&&(mat[k][j]<min[j]))
				min[j]=mat[k][j];
	}
	return ret;
}
void main()
{
	int mat[M][M],n,m;
	int c1,c2,cost,ret;
	int i,j;
	while(scanf("%d%d",&n,&m),n)
	{
		for (i=0;i<m;i++)
			for (j=0;j<m;j++)
				mat[i][j]=inf;

		while (n--)
		{
			scanf("%d%d%d",&c1,&c2,&cost);
			mat[c1-1][c2-1]=mat[c2-1][c1-1]=cost;
		}
		ret=Prim(mat,m);
		if (ret<inf)
			printf("%d\n",ret);
		else
			puts("?");
	}
}