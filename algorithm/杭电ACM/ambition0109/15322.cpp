////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-07 17:31:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1532
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:400KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
#define M 205
#define INF 0x7fffffff
#define MIN(x,y) (x>y?y:x)

int Map[M][M];
int pre[M], q[M];

int EK(int s, int t, int n) {
	int MFlow = 0;
	while (true) {
		memset(pre, -1, sizeof(pre));
		int ss, ee;
		q[ss = ee = 0] = s;
		while (ss <= ee) {
			int u = q[ss++];
			for (int v = 1; v <= n; v++) {
				if (pre[v] == -1 && Map[u][v]) {
					pre[v] = u;
					q[++ee] = v;
				}
			}
			if (pre[t] != -1) break;
		}
		if (pre[t] == -1) break;
		int mf = INF;
		for (int v = t; v != s; v = pre[v]) {
			mf = MIN(mf, Map[pre[v]][v]);
		}
		for (int v = t; v != s; v = pre[v]) {
			Map[pre[v]][v] -= mf;
			Map[v][pre[v]] += mf;
		}
		MFlow += mf;
	}
	return MFlow;
}

int main(){
    int n,m;
    while(~scanf("%d%d",&m,&n)){
        memset(Map,0,sizeof(Map));
        for(int i=0;i<m;i++){
            int c1,c2,val;
            scanf("%d%d%d",&c1,&c2,&val);
            Map[c1][c2]+=val;
        }
        int Ans=EK(1,n,n);
        printf("%d\n",Ans);
    }
}