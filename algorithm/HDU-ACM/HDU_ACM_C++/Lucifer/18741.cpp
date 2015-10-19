////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-10 23:55:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1874
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:324KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define M 201
int mat[M][M];
#define inf 1000000000
//int inf=;
int n;
void Dijkstra(int s,int t)
{
	char v[M];
	memset(v,0,n);
	int min[M];
//	memset(min,100,sizeof(min));
// 
	int k;
	int i,j;
// // 	for (i=0;i<n;i++)
// // 	{
// // 		min[i]=mat[s][i];
// // 	}
// 	
// 	min[s]=0;
// 
// 	for (i=0;i<n;i++)
// 	{
// 		for (k=-1,j=0;j<n;j++)
// 			if (!v[j]&&(k==-1||min[j]<min[k]))
// 				k=j;
// 		
// 		v[k]=1;
// 		for (j=0;j<n;j++)
// 			if (!v[j]&&(mat[k][j]+min[k]<min[j]))
// 				min[j]=mat[k][j]+min[k];
// 
// 	}
// 	return (min[t]>=inf)?-1:min[t];
				for(i=0;i<n;i++)
					min[i]=inf,v[i]=0;//,pre[i]=-1;
				
				for(min[s]=0,j=0;j<n;j++)
				{
					for(k=-1,i=0;i<n;i++)
						if(!v[i]&&(k==-1||min[i]<min[k]))
							k=i;
						for(v[k]=1,i=0;i<n;i++)
							if(!v[i]&&min[k]+mat[k][i]<min[i])
								min[i]=min[k]+mat[k][i];
				}
				
				if(min[t]<inf) printf("%d\n",min[t]);
				else  printf("-1\n");
}
int main()
{
// 	int m;
// 	int a,b,x;
// 	int s,t;
// 	memset(&inf,100,sizeof(int));
// 	int i,j;
// 	while(scanf("%d%d",&n,&m)!=EOF)
// 	{
// 		//memset(mat,100,sizeof(mat));
// 		for(i=0;i<n;i++)
// 			for(j=0;j<n;j++)
// 				if(j==i) mat[i][j]=0;
// 				else mat[i][j]=mat[j][i]=inf;
// 
// 		while(m--)
// 		{
// 			scanf("%d%d%d",&a,&b,&x);
// 			if (x<mat[a][b])
// 			{
// 				mat[a][b]=mat[b][a]=x;
// 			}
// 		}
// 		scanf("%d%d",&s,&t);
// 		Dijkstra(s,t);
// 	}
	int m,i;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int j,k;
		int x,y,weight,s,t;
		
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(j==i) mat[i][j]=0;
				else mat[i][j]=mat[j][i]=inf;
				
				for(i=0;i<m;i++)
				{
					scanf("%d%d%d",&x,&y,&weight);
					//mat[x][y]=mat[x][y]=weight;
					if(weight<mat[x][y]) mat[x][y]=mat[y][x]=weight;
				}
				scanf("%d%d",&s,&t);
				Dijkstra(s,t);
	}
	return 0;
}