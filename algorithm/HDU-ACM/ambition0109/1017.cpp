////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-20 20:28:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1017
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:208KB
//////////////////System Comment End//////////////////
/*
 * 1017.cpp
 *
 *  Created on: 2010-10-20
 *      Author: administrator
 */

#include<cstdio>
using namespace std;

int S[110];
int main(){
	for(int i=1;i<100;i++){
		S[i]=i*i;
	}
	int t;
	scanf("%d",&t);
	while(t--){
		int cas=0;
		int n,m;
		while(scanf("%d%d",&n,&m),n||m){
			int cnt=0;
			for(int i=1;i<n;i++){
				for(int j=i+1;j<n;j++){
					if((S[i]+S[j]+m)%(i*j)==0){
						cnt++;
					}
				}
			}
			printf("Case %d: %d\n",++cas,cnt);
		}
		if(t) puts("");
	}
}
