////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-19 13:54:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1871
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:240KB
//////////////////System Comment End//////////////////
/*
 * 1871.cpp
 *
 *  Created on: 2010-11-19
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Hot{
	int id,fre,pri;
}H[105];

bool cmp(const Hot& a,const Hot& b){
	return a.pri<b.pri;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&H[i].id,&H[i].fre,&H[i].pri);
		}
		sort(H,H+n,cmp);
		int m;
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			int num;
			scanf("%d",&num);
			int j;
			for(j=0;j<n;j++){
				if(H[j].fre>=num){
					printf("%d\n",H[j].id);
					H[j].fre-=num;
					break;
				}
			}
			if(j==n) puts("sorry");
		}
	}
}
