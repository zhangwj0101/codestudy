////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-23 11:13:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1257
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define M 100000
int x[M], y[M];
int main() {

	int n, i, j, c;
	while (scanf("%d", &n) != EOF) {
		c = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &x[i]);
			for (j = 0; j < c; j++) {
				if (x[i] < y[j]) {
					y[j] = x[i];
					break;
				}
			}
			if (j == c) {
				y[c] = x[i];
				c++;
			}
		}
		printf("%d\n", c);
	}
	return 0;
}