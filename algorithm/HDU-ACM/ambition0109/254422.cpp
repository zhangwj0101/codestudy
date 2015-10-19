////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-30 14:40:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:276KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;
#define MAXN 100
struct Unit{
	unsigned Link;
	int Cost;
	void set(int nLink,int nCost){
		Link=nLink; Cost=nCost;
	}
};
vector<vector<Unit> > Map;
int Path[MAXN+1];
bool Hash[MAXN+1];
//int CNT[MAXN+1];

void Init(int n){
	Map.clear();
	Map.resize(n+1);
	memset(Path,-1,sizeof(Path));
	memset(Hash,false,sizeof(Hash));
}

bool SPFA_Dfs(int t){
	for(int i=0;i<int(Map[t].size());i++){
		int tLink=Map[t][i].Link;
		if(Path[tLink]==-1||Map[t][i].Cost+Path[t]<Path[tLink]){
			if(Hash[tLink]) return false;
			Path[tLink]=Map[t][i].Cost+Path[t];
			Hash[tLink]=true;
			if(!SPFA_Dfs(tLink)) return false;
			Hash[tLink]=false;
		}
	}
	return true;
}
//Path数组中保存START到任意点最短路，如果不存在值为-1
//bool SPFA(int START,int n){
//	Path[START]=0;
//	stack<int> QUE;
//	QUE.push(START);
//	while(!QUE.empty()){
//		int Ups=QUE.top();
//		Hash[Ups]=false;
//		QUE.pop();
//		for(unsigned i=0;i<Map[Ups].size();i++){
//			int tLink=Map[Ups][i].Link;
//			if(Path[tLink]==-1||Map[Ups][i].Cost+Path[Ups]<Path[tLink]){
//				Path[tLink]=Map[Ups][i].Cost+Path[Ups];
//				//CNT[tLink]++;
//			//	if(CNT[tLink]>=n) return false;
//				if(Hash[tLink]) return false;
//					QUE.push(tLink);
//					Hash[tLink]=true;
//			}
//		}
//	}
//	return true;
//}
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m),n||m){
		Init(n);
		for(int i=0;i<m;i++){
			int c1,c2,cost;
			scanf("%d%d%d",&c1,&c2,&cost);
			Unit temp;
			temp.set(c2,cost);
			Map[c1].push_back(temp);
			temp.set(c1,cost);
			Map[c2].push_back(temp);
		}
		Path[1]=0;
		SPFA_Dfs(1);
		printf("%d\n",Path[n]);
	}
}