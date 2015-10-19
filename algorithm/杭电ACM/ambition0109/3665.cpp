////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-29 17:10:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3665
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define MAXN 100

struct City{
	unsigned LCity;
	int Cost;
	void set(int nCity,int nCost){
		LCity=nCity;Cost=nCost;
	}
};

vector<vector<City> > Graph;
int Path[MAXN+1];
bool Hash[MAXN+1];
bool End[100];

void Init(int n){
	Graph.clear();
	Graph.resize(n+1);
	memset(Path,-1,sizeof(Path));
	memset(Hash,false,sizeof(Hash));
	memset(End,false,sizeof(End));
}

void SPFA(int START){
	Path[START]=0;
	queue<int> QUE;
	QUE.push(START);
	while(!QUE.empty()){
		int Ups=QUE.front();
		QUE.pop();
		Hash[Ups]=false;
		for(unsigned i=0;i<Graph[Ups].size();i++){
			int tCity=Graph[Ups][i].LCity;
			if(Path[tCity]==-1||Graph[Ups][i].Cost+Path[Ups]<Path[tCity]){
				Path[tCity]=Graph[Ups][i].Cost+Path[Ups];
				if(!Hash[tCity]){
					QUE.push(tCity);
					Hash[tCity]=true;
				}
			}
		}
	}
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		Init(n);
		for(int i=0;i<n;i++){
			int m,e;
			scanf("%d%d",&m,&e);
			End[i]=e;
			for(int j=0;j<m;j++){
				City CC;
				scanf("%d%d",&CC.LCity,&CC.Cost);
				Graph[i].push_back(CC);
			}
		}
		SPFA(0);
		int Min=10000000;
		for(int i=0;i<n;i++){
			if(End[i]&&Path[i]!=-1){
				if(Min>Path[i]){
					Min=Path[i];
				}
			}
		}
		printf("%d\n",Min);
	}
}
