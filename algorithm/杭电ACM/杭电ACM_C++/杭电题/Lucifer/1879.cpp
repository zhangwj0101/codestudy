////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-09 17:36:20
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1879
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define M 100

int Prim(int mat[M][M],int n)
{
	int min[M];
	char v[M];
	int k,i,j;
	int ret=0;
	memset(v,0,n);
	memset(min,100,n*sizeof(int));
	min[0]=0;
	for (i=0;i<n;i++)
	{
		for (k=-1,j=0;j<n;j++)
			if (!v[j]&&(k==-1||min[j]<min[k]))
				k=j;
		v[k]=1;
		for (ret+=min[k],j=0;j<n;j++)
			if (mat[k][j]<min[j])
				min[j]=mat[k][j];
	}
	return ret;
}
void main()
{
	int mat[100][100];
	int n,len,i;
	int a,b,cost,s;
	int inf=100<<16+100;
	while (scanf("%d",&n),n)
	{
		memset(mat,100,sizeof(mat));
		len=n*(n-1)/2;
		for (i=0;i<len;i++)
		{
			scanf("%d%d%d%d",&a,&b,&cost,&s);
			if (s==1)cost=0;
			mat[a-1][b-1]=mat[b-1][a-1]=cost;
		}
		printf("%d\n",Prim(mat,n));
	}
}