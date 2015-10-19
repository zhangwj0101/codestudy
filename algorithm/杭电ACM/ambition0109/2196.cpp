////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-11 21:10:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2196
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:796KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

struct Unit{
	int num,val;
};
vector<vector<Unit> > Tree;
int deep[10010][2];
int len[10010],sw[10010];

int Max(const int& a,const int& b){
	int dif=b-a;
	return b-(dif&(dif>>31));
}

int Dfs_up(int idx){
	int SZ=Tree[idx].size();
	int Max=0;
	for(int i=0;i<SZ;i++){
		int tmp=Dfs_up(Tree[idx][i].num)+Tree[idx][i].val;
		if(tmp>deep[idx][1]) deep[idx][1]=tmp;
		if(tmp>deep[idx][0]){
			deep[idx][1]=deep[idx][0];
			Max=deep[idx][0]=tmp;
			sw[idx]=i;
		}
	}
	return Max;
}

void Dfs_down(int idx){
	int SZ=Tree[idx].size();
	for(int i=0;i<SZ;i++){
		if(i==sw[idx]){
			len[Tree[idx][i].num]=Max(len[idx],deep[idx][1])+Tree[idx][i].val;
		}else{
			len[Tree[idx][i].num]=Max(len[idx],deep[idx][0])+Tree[idx][i].val;
		}
		Dfs_down(Tree[idx][i].num);
	}
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(deep,0,sizeof(deep));
		memset(sw,-1,sizeof(sw));
		Tree.clear();
		Tree.resize(n+1);
		for(int i=2;i<=n;i++){
			int tl,tc;
			scanf("%d%d",&tl,&tc);
			Unit tmp;
			tmp.num=i; tmp.val=tc;
			Tree[tl].push_back(tmp);
		}
		Dfs_up(1);
		Dfs_down(1);
		for(int i=1;i<=n;i++){
			printf("%d\n",Max(deep[i][0],len[i]));
		}
	}
}