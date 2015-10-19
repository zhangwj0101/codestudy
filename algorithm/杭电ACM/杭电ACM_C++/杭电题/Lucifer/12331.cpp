////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-17 11:36:34
////Compiler: GUN C
//////////////////////////////////////////////////////
////Problem ID: 1233
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define M 100
#define inf 1000000000
int mat[M][M],n;
int prim()
{
	int min[M],ret;
	int i,j,k;
	char v[M];
	for(i=0;i<n;i++)
		min[i]=inf;
	memset(v,0,n);

	min[0]=0;
	
	for(ret=j=0;j<n;j++)
	{
		
		for(k=-1,i=0;i<n;i++)
		if(!v[i]&&(k==-1||min[k]>min[i]))
			k=i;

		v[k]=1;
		ret+=min[k];
		
		for(i=0;i<n;i++)
		{
			if(!v[i]&&(mat[k][i]<min[i]))
				min[i]=mat[k][i];
		}
	}
	return ret;

}
int main()
{
	int i,j,len;
	int a,b,dist;
	while(scanf("%d",&n),n)
	{
		len=n*(n-1)/2;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				mat[i][j]=inf;
		for(i=0;i<len;i++)
		{
			scanf("%d%d%d",&a,&b,&dist);
			mat[a-1][b-1]=mat[b-1][a-1]=dist;
		}
		printf("%d\n",prim());
	}
	return 0;
}