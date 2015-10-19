////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-13 19:01:46
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:336KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
const int INF=10000000;
int cross[101][101],sstr[101];
bool hush[101];
void main()
{
	int n,m,k;
	while(cin>>n>>m,n||m)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cross[i][j]=0;
		int c1,c2,time;
		for(int i=0;i<m;i++)
		{
			cin>>c1>>c2>>time;
			cross[c1][c2]=time;
			cross[c2][c1]=time;
		}
		for(int i=1;i<=n;i++)
		{
			sstr[i]=INF;
			hush[i]=false;
		}
		sstr[1]=0;hush[1]=true;
		int ups=1,min;
		while(ups!=n)
		{
			for(int i=1;i<=n;i++)
			{
				if(cross[ups][i])
				if(sstr[ups]+cross[ups][i]<sstr[i])
					sstr[i]=sstr[ups]+cross[ups][i];
			}
			for(int i=2,min=INF;i<=n;i++)
			{
				if(sstr[i]<min&&!hush[i])
				{min=sstr[i];ups=i;}
			}
			hush[ups]=true;
		}
		cout<<sstr[n]<<endl;
	}
}