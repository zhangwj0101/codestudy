////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-21 15:50:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1587
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		int min=1000000;
		for(int i=0;i<n;i++){
			int num;
			scanf("%d",&num);
			if(num<min) min=num;
		}
		printf("%d\n",m/min);
	}
}
