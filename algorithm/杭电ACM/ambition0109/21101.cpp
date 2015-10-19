////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-30 18:08:46
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2110
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:232KB
//////////////////System Comment End//////////////////
/*
 * 2110.cpp
 *
 *  Created on: 2010-9-28
 *      Author: administrator
 */

#include<cstdio>
#include<cstring>
using namespace std;

int bag[10000];
int val[100],cnt[100];
int main()
{
	int n;
	while(scanf("%d",&n),n){
		int sum=0;
		for(int i=0;i<n;i++){
			scanf("%d%d",&val[i],&cnt[i]);
			sum+=val[i]*cnt[i];
		}
		if(sum%3){
			puts("sorry");
			continue;
		}
		int m=sum/3;
		memset(bag,0,sizeof(bag));
		bag[0]=1;
		for(int i=0;i<n;i++){
			for(int k=m;k>=0;k--){
				for(int j=1;j<=cnt[i];j++){
					if(k<j*val[i]) break;
					bag[k]+=bag[k-j*val[i]];
					if(bag[k]>=10000) bag[k]%=10000;
				}
			}
		}
		if(bag[m]==0){
			puts("sorry");
		}else{
			printf("%d\n",bag[m]);
		}
	}
}
