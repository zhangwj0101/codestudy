////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-21 14:44:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1339
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int o=0;
		while(!(n&1)){
			n>>=1;
			o++;
		}
		printf("%d %d\n",n,o);
	}
}
