////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-07 11:55:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2510
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

int Ans[25]={0,0,0,4,6,0,0,12,40,0,0,171,410,0,0,1896,5160,0,0,32757,59984,0,0,431095,822229};
int main(){
	int n;
	while(scanf("%d",&n),n){
		printf("%d %d\n",n,Ans[n]);
	}
}