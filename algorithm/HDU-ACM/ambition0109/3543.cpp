////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-18 10:31:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3543
////Problem Title: 
////Run result: Accept
////Run time:562MS
////Run memory:10016KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
#include <bitset>
#include <ctime>
#include <map>
#include <cmath>
#include <stack>
using namespace std;
bool Hash[40000001];
int ohnn[20000001];

int main()
{

	int pp = (int)sqrt(40000000.0);
	int nn = (int)sqrt(pp * 1.0);

	for (int i = 2; i <= nn; i++) {
		if (!Hash[i] ) {//575795
			for (int j = i * i; j <= pp; j += i) {
				Hash[j] = true;
			}
		}         
	}

	int k = 0;
	for (int i = 2; i <= pp; i++) {
		if (!Hash[i]) {
			ohnn[k++] = i;
		}
	}

	for (int i = 0; i < k; i++) {
		for (int j = 30000000/ohnn[i]*ohnn[i]; j <= 40000000; j += ohnn[i]) {
			Hash[j] = true;
		}
	}

	int nnum = 0;
	for (int i = 30000001; i <= 40000000; i += 2) {
		if (!Hash[i]) {
			printf("%d\n", i);
		}
	}
	return 0;
}