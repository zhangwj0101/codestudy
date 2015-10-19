////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-28 13:30:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1548
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:304KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<vector>
using namespace std;
const int MAX_SIZE=200;
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
	int n;
	while(cin>>n,n)
	{
		cin>>START>>END;
		for(int i=1;i<=n;i++)
			Graph[i].clear();
		for(int i=1,cost;i<=n;i++)
		{
			City tcity;
			cin>>cost;
			if(i-cost>0)
			{
				tcity.LCity=i-cost;tcity.Cost=1;
				Graph[i].push_back(tcity);
			}
			if(i+cost<=n)
			{
				tcity.LCity=i+cost;tcity.Cost=1;
				Graph[i].push_back(tcity);
			}
		}
		for(int i=1;i<=n;i++)
        {
            Path[i]=INF;
            Hush[i]=true;
        }
		int Ups,Is=1;
		{
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
					Path[Graph[Ups][i].LCity]=Graph[Ups][i].Cost+Path[Ups];
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
			cout<<Path[END]<<endl;
		else
			cout<<"-1"<<endl;
	}
}