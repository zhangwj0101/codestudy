////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-07 17:46:46
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1532
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:11988KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
#define M 205
#define INF 0x7fffffff
#define MIN(x,y) (x>y?y:x)

struct Edge{
	int id,flow,next;
	Edge(int i=0,int f=0,int n=0):
		id(i),flow(f),next(n){}
}E[999999];
int pre[M], cur[M], que[M];
int head[M],node;

int EK(int s, int t) {
	int MFlow = 0;
	while (true) {
		memset(pre, -1, sizeof(pre));
		int ss, ee;
		que[ss = ee = 0] = s;
		while (ss <= ee) {
			int u = que[ss++];
			for (int i = head[u]; i != -1; i=E[i].next) {
				int v=E[i].id;
				if (pre[v] == -1 && E[i].flow) {
					pre[v] = u;
					cur[v] = i;
					que[++ee] = v;
				}
			}
			if (pre[t] != -1) break;
		}
		if (pre[t] == -1) break;
		int mf = INF;
		for (int v = t; v != s; v = pre[v]) {
			mf = MIN(mf, E[cur[v]].flow);
		}
		for (int v = t; v != s; v = pre[v]) {
			E[cur[v]].flow -= mf;
			E[cur[v]^1].flow += mf;
		}
		MFlow += mf;
	}
	return MFlow;
}

void Init(){
	memset(head,-1,sizeof(head));
	node=0;
}

void Insert(int u,int v,int f){
	E[node]=Edge(v,f,head[u]);
	head[u]=node++;
	E[node]=Edge(u,0,head[v]);
	head[v]=node++;
}

int main(){
    int n,m;
    while(~scanf("%d%d",&m,&n)){
    	Init();
        for(int i=0;i<m;i++){
            int c1,c2,val;
            scanf("%d%d%d",&c1,&c2,&val);
            Insert(c1,c2,val);
        }
        int Ans=EK(1,n);
        printf("%d\n",Ans);
    }
}
