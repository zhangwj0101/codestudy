////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-06 12:34:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1532
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:348KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

int Map[205][205];
int pre[205], cur[205], dis[205], gap[205];

int SAP(int s, int e, int n) {
	memset(dis, 0, sizeof(dis));
	memset(gap, 0, sizeof(gap));
	memset(cur, 0, sizeof(cur));
	int MFlow = 0, ts = s;
	int mf = 0x7fffffff;
	gap[0] = n; pre[s]=s;
	while (dis[s] < n) {
		loop: for (int i = cur[ts]; i <= n; i++) {
//			printf("# %d %d\n",ts,i);
			if (Map[ts][i] && dis[ts] == dis[i] + 1) {
				if (mf > Map[ts][i]) {
					mf = Map[ts][i];
				}
				pre[i] = ts;
				ts = cur[ts] = i;
				if (i == e) {
					MFlow += mf;
					for (int j = e; j != s; j = pre[j]) {
						Map[pre[j]][j] -= mf;
						Map[j][pre[j]] += mf;
					}
					mf = 0x7fffffff;
					ts=s;
				}

				goto loop;
			}
		}
		int md = n - 1;
		for (int i = 1; i <= n; i++) {
			if (Map[ts][i] && md > dis[i]) {
				cur[ts] = i;
				md = dis[i];
			}
		}
		if ((--gap[dis[ts]]) == 0)
			break;
		gap[dis[ts] = md + 1]++;
		ts = pre[ts];
//		printf("&& ");
//		for(int i=1;i<=n;i++){
//			printf("%d ",dis[i]);
//		}
//		puts("");
//		printf("^^ ");
//		for(int i=1;i<=n;i++){
//			printf("%d ",cur[i]);
//		}
//		puts("");
//		printf("%%%% ");
//		for(int i=1;i<=n;i++){
//			printf("%d ",gap[i]);
//		}
//		puts("");
	}
	return MFlow;
}

int main(){
	int n,m;
	while(~scanf("%d%d",&m,&n)){
		memset(Map,0,sizeof(Map));
		for(int i=0;i<m;i++){
			int t1,t2,flow;
			scanf("%d%d%d",&t1,&t2,&flow);
			Map[t1][t2]+=flow;
		}
		printf("%d\n",SAP(1,n,n));
	}
	return 0;
}