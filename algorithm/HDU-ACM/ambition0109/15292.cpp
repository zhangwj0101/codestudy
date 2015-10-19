////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-11 18:43:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1529
////Problem Title: 
////Run result: Accept
////Run time:375MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
using namespace std;

int s[30],num[30],x[30],r[30];
int n,t,ans;
bool v[30][30];
int map[30][30];//也可用邻接表保存边

void init()
{
	int i;
	memset(map,0,sizeof(map));
	memset(v,false,sizeof(v));
	for(i=0;i<=24;i++) {//make Graphi
		v[i][i+1] = true;
		map[i][i+1] = 0;
		v[i+1][i] = true;
		map[i+1][i] = -num[i+1];
	}
	for(i=9;i<=24;i++) {//s[I] - s[I-8] >= r[I]    (8 <= I <= 23)
		v[i-8][i] = true;
		map[i-8][i] = r[i];
	}
	for(i=1;i<=24;i++) {
		v[0][i] = true;
		map[0][i] = 0;
	}
}

bool bellman_ford()
{
	int i,j,k;
	bool flag ;

	memset(s,0,sizeof(s));
	for (i=1;i<=8;i++) {//s[I] - s[I+16] >= r[I] - s[23]    (0 <= I <= 7)
		v[i+16][i] = true;
		map[i+16][i] = r[i] - ans;
	}
	map[0][24] = ans;
	for (i=0; i<=71 ;i++) {
		flag = true;
		for (j=0;j<=24;j++) {
			for (k=0;k<=24;k++) {
				if (v[j][k] && s[j]+map[j][k] > s[k]) {// >=最长路, <=最短路
					s[k] = s[j] + map[j][k];
					flag = false;
				}
			}
		}
		if (flag) {
			break ;
		}
	}
	return ans == s[24];
}

int main()
{
	int i,k;
	scanf("%d",&t);
	while (t--) {
		memset(num,0,sizeof(num));
		for (i=1;i<=24;i++) {
			scanf("%d",&r[i]);
		}
		scanf("%d",&n);
		for (i=0;i<n;i++) {
			scanf("%d",&k);
			num[k+1] ++;
		}

		ans = n;
		init();
		if (!bellman_ford()) {
			printf("No Solution\n");
		}
		else {
			for (ans=0;ans<=n;ans++) {// 枚举s[23]，可优化为二分枚举
				if (bellman_ford()) {
					printf("%d\n", ans);
					break;
				}
			}
		}//if
	}
}
