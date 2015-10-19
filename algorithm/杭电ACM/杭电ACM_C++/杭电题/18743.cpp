////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-11 00:00:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1874
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:288KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define M 201
int mat[M][M];
#define inf 10000000
int n;
void Dijkstra(int s,int t)
{
	char v[M];
	memset(v,0,n);
	int min[M];
	int k;
	int i,j;
	for (i=0;i<n;i++)
		min[i]=inf;
	
	min[s]=0;

	for (i=0;i<n;i++)
	{
		for (k=-1,j=0;j<n;j++)
			if (!v[j]&&(k==-1||min[j]<min[k]))
				k=j;
		
		v[k]=1;
		for (j=0;j<n;j++)
			if (!v[j]&&(mat[k][j]+min[k]<min[j]))
				min[j]=mat[k][j]+min[k];

	}
	printf("%d\n",(min[t]>=inf)?-1:min[t]);
}
int main()
{
	int m;
	int a,b,x;
	int s,t;
	int i,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		//memset(mat,100,sizeof(mat));
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(j==i) mat[i][j]=0;
				else mat[i][j]=mat[j][i]=inf;

		while(m--)
		{
			scanf("%d%d%d",&a,&b,&x);
			if (x<mat[a][b])
			{
				mat[a][b]=mat[b][a]=x;
			}
		}
		scanf("%d%d",&s,&t);
		Dijkstra(s,t);
	}
	return 0;
}