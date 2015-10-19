////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-09 23:57:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1875
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:344KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
#include <string.h>
#define M 100
double mat[M+1][M+1];
char matt[M+1][M+1];
double eps=1e-6;
int inf=2000;
char v[M+1];
int c;
void dfs(int i)
{
	int j;
	v[i]=1;
	for (j=0;j<c;j++)
	{
		if (!v[j]&&matt[i][j])
		{
			dfs(j);
		}
	}

}
double prim()
{
	double min[M];
	int i,j;
	for (i=0;i<c;i++)
		min[i]=inf;
	min[0]=0;
	int k;
	double ret=0;
	memset(v,0,c);
	for (i=0;i<c;i++)
	{
		for (k=-1,j=0;j<c;j++)
			if (!v[j]&&(k==-1||min[j]<min[k]))
				k=j;
		v[k]=1;
		for (ret+=min[k],j=0;j<c;j++)
		{
			if (!v[j]&&(min[j]>mat[k][j]))
			{
				min[j]=mat[k][j];
			}
		}
	}
	return ret;
}

void main()
{
	int t,x[M],y[M],i,j;
	
	int cnt;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&c);
		for (i=0;i<c;i++)
			scanf("%d%d",&x[i],&y[i]);
		memset(v,0,c);
		cnt=0;
		for (i=0;i<c;i++)
		{
			for (j=0;j<c;j++)
			{
				mat[i][j]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
				if (mat[i][j]>1000000||mat[i][j]<100)
				{
					mat[i][j]=inf;
					matt[i][j]=0;
				}
				else
				{
					mat[i][j]=sqrt(mat[i][j]);
					matt[i][j]=1;
				}
			}
		}
		for (i=0;i<c&&(cnt<2);i++)
		{
			if (!v[i])
			{
				dfs(i);
				cnt++;
			}
		}
		if (cnt>1)
		{
			puts("oh!");
		}
		else
			printf("%.1lf\n",prim()*100);
	}
}