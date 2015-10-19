////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-30 11:13:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3008
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:252KB
//////////////////System Comment End//////////////////
/*
 * 3008.cpp
 *
 *  Created on: 2010-10-30
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
using namespace std;

struct Skill {
	int cos, atk;
} ski[105];
int dp[105][105];

int main() {
	int n, t, q;
	while (scanf("%d%d%d", &n, &t, &q), n || t || q) {
		ski[0].atk = 1;
		ski[0].cos = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &ski[i].cos, &ski[i].atk);
		}
		int tim = (99 + q) / q, Ans;
		memset(dp, -1, sizeof(dp));
		dp[0][100] = 100;
		bool flag = false;
		for (int i = 0; i < tim; i++) {
			for (int j = 0; j <= 100; j++) {
				if (dp[i][j] == -1)
					continue;
				int mag = (j + t) > 100 ? 100 : (j + t);
				for (int k = 0; k <= n; k++) {
					if(mag - ski[k].cos<0) continue;
					if (dp[i + 1][mag - ski[k].cos] == -1 ||
							dp[i + 1][mag - ski[k].cos] > dp[i][j] - ski[k].atk) {
						dp[i + 1][mag - ski[k].cos] = dp[i][j] - ski[k].atk;
						//printf("$$ %d %d : %d\n",i+1,mag-ski[k].cos,dp[i + 1][mag - ski[k].cos]);
						if (dp[i + 1][mag - ski[k].cos] <= 0) {
							flag = true;
							Ans = i + 1;
							break;
						}
					}
				}
				if (flag)
					break;
			}
			if (flag)
				break;
		}
		if (flag)
			printf("%d\n", Ans);
		else
			puts("My god");
	}
}
