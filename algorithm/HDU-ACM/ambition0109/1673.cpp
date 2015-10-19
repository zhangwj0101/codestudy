////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-04 13:32:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1673
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:160KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,min=100,max=0,num;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&num);
			if(num<min) min=num;
			if(num>max) max=num;
		}
		printf("%d\n",(max-min)*2);
	}
}
