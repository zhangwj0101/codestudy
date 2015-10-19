////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-11 13:39:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1244
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int sum[2][1001];
int num[1001],len[21],sp[21];
void main()
{
	int n,m;
	while(cin>>n,n)
	{
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>len[i];
			sp[i]=len[i];
			sp[i]+=sp[i-1];
		}
		for(int i=1;i<=n;i++){
			cin>>num[i];
			num[i]+=num[i-1];
		}
		memset(sum[0],0,sizeof(sum[0]));
		for(int i=1;i<=m;i++)
		{
			for(int j=sp[i];j<=n;j++)
			{
				if(j==sp[i]) sum[1][j]=sum[0][j-len[i]]+num[j]-num[j-len[i]];
				else{
					if(sum[1][j-1]>sum[0][j-len[i]]+num[j]-num[j-len[i]])
						sum[1][j]=sum[1][j-1];
					else sum[1][j]=sum[0][j-len[i]]+num[j]-num[j-len[i]];
				}
			}
			copy(sum[1]+len[i],sum[1]+n,sum[0]+len[i]);
		}
		cout<<sum[1][n]<<endl;
	}
}