////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-12 11:51:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2639
////Problem Title: 
////Run result: Accept
////Run time:1343MS
////Run memory:996KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
int v[101] , w[101];
set<int> dp[1001];
int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        int n , m , k;
        scanf("%d%d%d",&n,&m,&k);
        for (int i = 0 ; i < n ; i ++) scanf("%d",&w[i]);
        for (int i = 0 ; i < n ; i ++) scanf("%d",&v[i]);
        for (int i = 0 ; i <= m ; i ++) dp[i].clear() , dp[i].insert(0);
        for (int i = 0 ; i < n ; i ++) {
            for (int j = m ; j >= v[i] ; j --) {
                for (set<int>::iterator it = dp[j-v[i]].begin() ; it != dp[j-v[i]].end() ; it ++) {
                    dp[j].insert((*it) + w[i]);
                    if(dp[j].size() > k) dp[j].erase(dp[j].begin());
                }
            }
        }
        if(dp[m].size() < k) {
            puts("0");
        } else {
            printf("%d\n",*(dp[m].begin()));
        }
    }
    return 0;
}