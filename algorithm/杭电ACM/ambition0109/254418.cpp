////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-30 13:22:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:272KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define MAXN 100
struct Point{
	unsigned Link;
	int Cost;
	void set(int nLink,int nCost){
		Link=nLink; Cost=nCost;
	}
};
vector<vector<Point> > Graph;
int Path[MAXN+1];

struct CMP{
	bool operator() (const int& a,const int& b){
		return Path[a]>Path[b];
	}
};

//初始化...
void Init(int n){
	Graph.clear();
	Graph.resize(n+1);
	memset(Path,-1,sizeof(Path));
}
//返回START到END的最短路，如果不存在返回-1
int Dijkstra(int START,int END){
	priority_queue<int,vector<int>,CMP> QUE;
	Path[START]=0;
	QUE.push(START);
	while(!QUE.empty()){
		int Ups=QUE.top();
		if(Ups==END) return Path[Ups];
		QUE.pop();
		for(unsigned i=0;i<Graph[Ups].size();i++){
			int tLink=Graph[Ups][i].Link;
			int tCost=Graph[Ups][i].Cost;
			if(Path[tLink]==-1||tCost+Path[Ups]<Path[tLink]){
				Path[tLink]=tCost+Path[Ups];
				QUE.push(tLink);
			}
		}
	}
	return -1;
}
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m),n||m){
		Init(n);
		for(int i=0;i<m;i++){
			int c1,c2,cost;
			scanf("%d%d%d",&c1,&c2,&cost);
			Point temp;
			temp.set(c2,cost);
			Graph[c1].push_back(temp);
			temp.set(c1,cost);
			Graph[c2].push_back(temp);
		}
		printf("%d\n",Dijkstra(1,n));
	}
}