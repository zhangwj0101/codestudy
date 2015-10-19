////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-21 13:25:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:364KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<vector>
using namespace std;
const int MAX_SIZE=100;
const int INF=2147483647;

struct City
{
	int LCity;
	int Cost;
};
vector<City> Graph[MAX_SIZE+1];
int Path[MAX_SIZE+1];
bool SHush[MAX_SIZE+1];
int CHush[MAX_SIZE+1];
//int Pre[i];
int START,END;

void main()
{
	int n,m;
	while(cin>>n>>m,n||m)
	{
		for(int i=1;i<=n;i++)
			Graph[i].clear();
		for(int i=0,c1,c2,cost;i<m;i++)
		{
			City tcity;
			cin>>c1>>c2>>cost;
			tcity.LCity=c2;tcity.Cost=cost;
			Graph[c1].push_back(tcity);
			tcity.LCity=c1;tcity.Cost=cost;
			Graph[c2].push_back(tcity);
		}
		for(int i=1;i<=n;i++)		//初始化Path[],Hush[]
        {
            Path[i]=INF;
            SHush[i]=false;
			CHush[i]=0;
			//Pre[i]=0;
        }
		int Ups,Is=1;
		{
			START=1;END=n;
			//起始位置START
			Ups=START;
			Path[Ups]=0;
			SHush[Ups]=true;
			CHush[Ups]+=1;
		}
		while(1)		//SPFA
        {
			int i=1;
			for(;i<=n;i++)
				if(SHush[i])
				{Ups=i;SHush[i]=false;break;}
			if(i==n+1) break;
			for(unsigned i=0;i<Graph[Ups].size();i++)
			{
				if(Graph[Ups][i].Cost+Path[Ups]<Path[Graph[Ups][i].LCity])
				{
					Path[Graph[Ups][i].LCity]=Graph[Ups][i].Cost+Path[Ups];
					SHush[Graph[Ups][i].LCity]=true;
					CHush[Graph[Ups][i].LCity]+=1;
					if(CHush[Graph[Ups][i].LCity]==n)
					{Is=0;break;}
					//Pre[i]=Ups;
				}
			}
			if(!Is) break;
        }
		if(Is&&Path[END]!=INF)
		{
			// for(int Min;;);如有多个终点，找出最小值
			cout<<Path[END]<<endl;
		}
		else
			cout<<"-1"<<endl;
	}
}