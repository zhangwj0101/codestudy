////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-21 12:30:50
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
const int MAX_SIZE=150;
const int INF=2147483647;

struct City
{
	int LCity;
	int Cost;
};
vector<City> Graph[MAX_SIZE+1];
int Path[MAX_SIZE+1];
bool Hush[MAX_SIZE+1];
int START,END;

void main()
{
	int n,m;
	while(cin>>n>>m,n||m)
	{
		for(int i=1;i<=MAX_SIZE;i++)
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
            Hush[i]=true;
			//Pre[i]=0;
        }
		int Ups,Is=1;
		{
			START=1;END=n;
			//起始位置START
			Ups=START;
			Path[Ups]=0;	//如有多个起始位置，全部值0
			Hush[Ups]=false;
			//如有多个起始位置，只设置期中一个Hush为FALSE，且该项为更新前驱Ups
		}
		while(Ups!=END)		//Dijkstra
        {
			for(unsigned i=0;i<Graph[Ups].size();i++)
            {
				if(Graph[Ups][i].Cost+Path[Ups]<Path[Graph[Ups][i].LCity])
				{
					Path[Graph[Ups][i].LCity]=Graph[Ups][i].Cost+Path[Ups];
					//Pre[i]=Ups;
				}
            }
			int Min=INF;
            for(int i=1;i<=n;i++)
            {
                if(Path[i]<Min&&Hush[i])
                {
					Min=Path[i];
					Ups=i;
				}
            }
			if(Min==INF) {Is=0;break;}
            Hush[Ups]=false;
        }
		if(Is)
		{
			// for(int Min;;);如有多个终点，找出最小值
			cout<<Path[END]<<endl;
		}
		else
			cout<<"-1"<<endl;
	}
}