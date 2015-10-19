////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-30 14:08:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3033
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:728KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<vector>
using namespace std;

int bag[11][10001],v[101],w[101];
vector<int> brand[11];

void main()
{
	int n,aw,ak;
	while(cin>>n>>aw>>ak)
	{
		for(int i=1;i<=ak;i++)
			brand[i].clear();
		for(int i=1;i<=ak;i++)
			for(int j=0;j<=aw;j++)
				bag[i][j]=-1;
		for(int i=1,k;i<=n;i++)
		{
			cin>>k>>w[i]>>v[i];
			brand[k].push_back(i);
		}
		for(int k=1;k<=ak;k++)
			for(unsigned i=0;i<brand[k].size();i++)
				for(int j=aw;j>=w[brand[k][i]]+1;j--)
				{
					if(bag[k][j-w[brand[k][i]]]!=-1&&bag[k][j-w[brand[k][i]]]+v[brand[k][i]]>bag[k][j])
						bag[k][j]=bag[k][j-w[brand[k][i]]]+v[brand[k][i]];
					if(bag[k-1][j-w[brand[k][i]]]!=-1&&bag[k-1][j-w[brand[k][i]]]+v[brand[k][i]]>bag[k][j])
						bag[k][j]=bag[k-1][j-w[brand[k][i]]]+v[brand[k][i]];
				}
		if(bag[ak][aw]==-1) cout<<"Impossible"<<endl;
		else cout<<bag[ak][aw]<<endl;
	}
}