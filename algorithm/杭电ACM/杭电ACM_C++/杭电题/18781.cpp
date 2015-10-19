////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-18 23:25:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1878
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:1288KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
#define M 1000
char mat[M][M];
char v[M];
int n;
int ct[M];
void dfs(int vi)
{
	int i;
	v[vi]=1;
	for(i=0;i<n;i++)
	{
		if(mat[vi][i])
		{
			if(!v[i])
			{
				dfs(i);
			}
		}
	}
}

int main()
{
	int m,a,b,cnt,flag,i;
	while(scanf("%d",&n),n)
	{
		scanf("%d",&m);
		memset(mat,0,sizeof(mat));
		memset(ct,0,sizeof(ct));
		memset(v,0,n);
		flag=1;
		while(m--)
		{
			scanf("%d%d",&a,&b);
			mat[a-1][b-1]=mat[b-1][a-1]=1;
			ct[a-1]++;
			ct[b-1]++;
		}
		for(cnt=i=0;(i<n)&&(flag);i++)
		{
			if(!v[i]&&flag)
			{
				cnt++;
				if(cnt>1)
					flag=0;
				dfs(i);
			}
		}
		for(i=0;(i<n)&&flag;i++)
			if(ct[i]&1)
				flag=0;
		printf("%d\n",flag);
	}
	return 0;
}