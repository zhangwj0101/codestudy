////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-13 19:58:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2066
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:4220KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
const int INF=1000000000;
int cross[1001][1001],sstr[1001];
bool hush[1001];
void main()
{
	int n,m,k;
	while(cin>>n>>m>>k)
	{
		for(int i=1;i<=1000;i++)
			for(int j=1;j<=1000;j++)
				cross[i][j]=0;
		int c1,c2,time;
		for(int i=0;i<n;i++)
		{
			cin>>c1>>c2>>time;
			if(!cross[c1][c2]||(cross[c1][c2]&&cross[c1][c2]>time))
			{
				cross[c1][c2]=time;
				cross[c2][c1]=time;
			}
		}
		for(int i=1;i<=1000;i++)
		{
			sstr[i]=INF;
			hush[i]=false;
		}

		for(int i=0,c;i<m;i++)
		{
			cin>>c;
			sstr[c]=0;hush[c]=true;
			for(int i=1;i<=1000;i++)
			{
				if(cross[c][i]!=0)
				if(sstr[c]+cross[c][i]<sstr[i])
					sstr[i]=sstr[c]+cross[c][i];
			}
		}
		int ups;
		while(1)
		{
			int min=INF;
			for(int i=1;i<=1000;i++)
			{
				if(sstr[i]<min&&!hush[i])
				{min=sstr[i];ups=i;}
			}
			for(int i=1;i<=1000;i++)
			{
				if(cross[ups][i]!=0)
				if(sstr[ups]+cross[ups][i]<sstr[i])
					sstr[i]=sstr[ups]+cross[ups][i];
			}
			if(min==INF) break;
			hush[ups]=true;
		}
		int min=INF;
		for(int i=0,c;i<k;i++)
		{
			cin>>c;
			if(min>sstr[c])
				min=sstr[c];
		}
		cout<<min<<endl;
	}
}