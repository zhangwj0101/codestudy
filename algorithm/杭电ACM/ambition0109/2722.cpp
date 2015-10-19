////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-05 11:30:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2722
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:272KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<vector>
using namespace std;
const int MAX_SIZE=500;
const int INF=2147483647;

struct City
{
	int LCity;
	int Cost;
};
vector<City> Graph[MAX_SIZE+1];
int len[10]={INF,2520,1260,840,630,504,420,360,315,280};
int Path[MAX_SIZE+1];
bool Hush[MAX_SIZE+1];
int n,m;

int Dijkstra(int START,int END)
{
	for(int i=1;i<=(n+1)*(m+1);i++){
		Path[i]=INF;
		Hush[i]=true;
	}
	int Ups=START;
	Path[Ups]=0;
	Hush[Ups]=false;
	while(Ups!=END)
	{
		for(unsigned i=0;i<Graph[Ups].size();i++)
			if(Graph[Ups][i].Cost+Path[Ups]<Path[Graph[Ups][i].LCity])
				Path[Graph[Ups][i].LCity]=Graph[Ups][i].Cost+Path[Ups];
		int Min=INF;
		for(int i=1;i<=(n+1)*(m+1);i++){
			if(Path[i]<Min&&Hush[i]){
				Min=Path[i];
				Ups=i;
			}
		}
		if(Min==INF) return -1;
		Hush[Ups]=false;
	}
	return Path[END];
}

int main()
{
	while(cin>>n>>m,n||m)
	{
		for(int i=1;i<=(n+1)*(m+1);i++)
			Graph[i].clear();
		for(int i=1;i<=m;i++)
		{
			int cost;char mod;
			cin>>cost>>mod;
			if(cost==0) continue;
			City tcity;
			tcity.Cost=len[cost];
			if(mod=='*'||mod=='>'){
				tcity.LCity=i+1;
				Graph[i].push_back(tcity);
			}
			if(mod=='*'||mod=='<'){
				tcity.LCity=i;
				Graph[i+1].push_back(tcity);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m+1;j++){
				int cost;char mod;
				cin>>cost>>mod;
				if(cost==0) continue;
				City tcity;
				tcity.Cost=len[cost];
				if(mod=='*'||mod=='v'){
					tcity.LCity=i*(m+1)+j;
					Graph[(i-1)*(m+1)+j].push_back(tcity);
				}
				if(mod=='*'||mod=='^'){
					tcity.LCity=(i-1)*(m+1)+j;
					Graph[i*(m+1)+j].push_back(tcity);
				}
			}
			for(int j=1;j<=m;j++){
				int cost;char mod;
				cin>>cost>>mod;
				if(cost==0) continue;
				City tcity;
				tcity.Cost=len[cost];
				if(mod=='*'||mod=='>'){
					tcity.LCity=i*(m+1)+j+1;
					Graph[i*(m+1)+j].push_back(tcity);
				}
				if(mod=='*'||mod=='<'){
					tcity.LCity=i*(m+1)+j;
					Graph[i*(m+1)+j+1].push_back(tcity);
				}
			}
		}
		int Allcost=Dijkstra(1,(n+1)*(m+1));
		if(Allcost==-1)
			cout<<"Holiday"<<endl;
		else
			cout<<Allcost<<" blips"<<endl;
	}
	return 0;
}