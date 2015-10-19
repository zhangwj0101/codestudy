////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-12 18:31:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3201
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:196KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;
#define Pi 3.1415926535897935354626

int main(){
	int n;
	while(scanf("%d",&n),n){
		printf("%.2lf\n",double(n*n)/Pi/2.0);
	}
}