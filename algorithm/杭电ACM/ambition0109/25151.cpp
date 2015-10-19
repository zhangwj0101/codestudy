////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-27 19:11:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2515
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int num[55][55];
int nn[55];
void main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				scanf("%d",&num[i][j]);
		for(int i=1;i<n-1;i++)
			nn[i]=(num[i][i+1]+num[i][i+2]-num[i+1][i+2])/2;
		nn[n-1]=num[n-2][n-1]-nn[n-2];
		nn[n]=num[n-1][n]-nn[n-1];
		for(int i=1;i<=n;i++)
			printf("%d\n",nn[i]);
	}
}