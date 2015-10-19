////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-03 16:37:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2079
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:288KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int f[41],t[41];
int v,kk;
void main()
{
	int n,m,vv,i,j,k;
	for(cin>>n;n>0;n--)
	{
		cin>>vv>>m;
		memset(f,0,sizeof(f));
		f[0]=1;
		for(i=0;i<m;i++)
		{
			cin>>v>>kk;
			memset(t,0,sizeof(t));
			for(j=0;j<=vv;j++)
			{
				if(f[j]!=0)
				for(k=1;k<=kk&&(k*v+j)<=vv;k++)
					t[k*v+j]+=f[j];
			}
			for(j=0;j<=vv;j++)
				f[j]+=t[j];
		}
		printf("%d\n",f[vv]);
	}
}