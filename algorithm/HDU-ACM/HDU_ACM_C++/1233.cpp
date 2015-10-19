////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-02 20:52:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1233
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:276KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include<string.h>
#include <limits.h>
char v[100];
char uv[100];
int vn,uvn;
int mat[100][100];
int Prim(int n)
{
	int i,j,k;
	vn=1;
	uvn=n-1;
	v[0]=0;
	uv[0]=uv[n-1];
	int res,min,mini,minj;
	res=0;
	for (i=0;i<n-1;i++)
	{
		min=INT_MAX;
		for (j=0;j<vn;j++)
		{
			for (k=0;k<uvn;k++)
			{
				if (min>mat[v[j]][uv[k]])
				{
					min=mat[v[j]][uv[k]];
					mini=v[j];
					minj=uv[k];
				}
			}
		}
		v[vn++]=minj;
		for (j=0;j<uvn;j++)
		{
			if (uv[j]==minj)
			{
				break;
			}
		}
		uv[j]=uv[--uvn];
		res+=min;
	}
	return res;

}

void main()
{
	int n,i,m,c1,c2,dist;
	while (scanf("%d",&n),n)
	{
		m=n*(n-1)/2;
		memset(mat,0,sizeof(mat));
		memset(v,0,n);
		for (i=0;i<n;i++)
			uv[i]=i;

		for (i=0;i<m;i++)
		{
			scanf("%d%d%d",&c1,&c2,&dist);
			mat[c1-1][c2-1]=dist;
			mat[c2-1][c1-1]=dist;
		}
		printf("%d\n",Prim(n));
	}
}