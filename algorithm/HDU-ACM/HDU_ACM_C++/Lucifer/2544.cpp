////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-22 11:28:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include <algorithm>
using namespace std;
#define M 101
int mat[M][M];
int n;
void dij(int s,int e)
{
	char v[M];
	int min[M],i,j,k;
	
	memset(v,0,n);
	memset(min,1,sizeof(min));
	min[s]=0;

	for(i=0;i<n;i++)
	{
		for(k=-1,j=0;j<n;j++)
			if(!v[j]&&(k==-1||min[k]>min[j]))
				k=j;

		v[k]=1;
		for(j=0;j<n;j++)
			if(!v[j]&&(min[k]+mat[k][j]<min[j]))
				min[j]=min[k]+mat[k][j];

	}
	printf("%d\n",min[e]);
}
int main( )
{
	int m;
	int a,b,c;
	while(scanf("%d%d",&n,&m),n||m)
	{
		memset(mat,1,sizeof(mat));

		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			mat[a-1][b-1]=mat[b-1][a-1]=c;
		}
		dij(0,n-1);
	}
	return 0;
}