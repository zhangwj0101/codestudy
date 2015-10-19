////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-21 14:18:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1719
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

int main(){
	int n;
	while(~scanf("%d",&n)){
		if(n==0){
			puts("NO!");
			continue;
		}
		n=n+1;
		while(!(n&1)){
			n>>=1;
		}
		while(!(n%3)){
			n/=3;
		}
		puts(n==1?"YES!":"NO!");
	}
}