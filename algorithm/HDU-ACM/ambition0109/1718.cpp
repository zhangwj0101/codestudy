////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-02 11:33:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1718
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
/*
 * 1718.cpp
 *
 *  Created on: 2010-12-2
 *      Author: hduacm
 */

#include<cstdio>
#include<algorithm>
using namespace std;

struct Stu{
	int id, sco;
	friend bool operator <(const Stu& a,const Stu& b){
		return a.sco>b.sco;
	}
}S[1010];

int main(){
	int t;
	while(~scanf("%d",&t)){
		int n=0,rank=1;
		while(scanf("%d%d",&S[n].id,&S[n].sco),S[n].id||S[n].sco){
			n++;
		}
		sort(S,S+n);
		if(S[0].id==t){
			printf("%d\n",rank);
		}else{
			for(int i=1;i<n;i++){
				if(S[i].sco!=S[i-1].sco) rank=i+1;
				if(S[i].id==t){
					printf("%d\n",rank);
					break;
				}
			}
		}
	}
}
