////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-07 10:42:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2522
////Problem Title: 
////Run result: Accept
////Run time:281MS
////Run memory:332KB
//////////////////System Comment End//////////////////
/*
 * 2522.cpp
 *
 *  Created on: 2010-12-7
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
using namespace std;

bool Hash[100010];
int main(){
	int n,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n<0){
			printf("-");
			n=-n;
		}
		if(n==1){
			puts("1");
			continue;
		}
		int t=10;
		memset(Hash,false,sizeof(Hash));
		Hash[0]=Hash[1]=true;
		printf("0.");
		while(true){
			printf("%d",t/n);
			int r=t%n;
			if(Hash[r]) break;
			Hash[r]=true;
			t=r*10;
		}
		puts("");
	}
}
