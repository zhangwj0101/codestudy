////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-30 13:28:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:276KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
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

void Init(int n){
	Map.clear();
	Map.resize(n+1);
	memset(Path,-1,sizeof(Path));
	memset(Hash,false,sizeof(Hash));
}
//Path数组中保存START到任意点最短路，如果不存在值为-1
void SPFA(int START){
	Path[START]=0;
	queue<int> QUE;
	QUE.push(START);
	while(!QUE.empty()){
		int Ups=QUE.front();
		Hash[Ups]=false;
		QUE.pop();
		for(unsigned i=0;i<Map[Ups].size();i++){
			int tLink=Map[Ups][i].Link;
			if(Path[tLink]==-1||Map[Ups][i].Cost+Path[Ups]<Path[tLink]){
				Path[tLink]=Map[Ups][i].Cost+Path[Ups];
				if(!Hash[tLink]){
					QUE.push(tLink);
					Hash[tLink]=true;
				}
			}
		}
	}
}
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
		SPFA(1);
		printf("%d\n",Path[n]);
	}
}