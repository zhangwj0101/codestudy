////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-29 18:31:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1052
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:220KB
//////////////////System Comment End//////////////////
/*
 * 1052.cpp
 *
 *  Created on: 2010-10-29
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

bool CMP(const int& a,const int& b){
	return a>b;
}

int tj[1005],ki[1005];
int main(){
	int n;
	while(scanf("%d",&n),n){
		for(int i=0;i<n;i++){
			scanf("%d",&tj[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%d",&ki[i]);
		}
		sort(tj,tj+n,CMP);
		sort(ki,ki+n,CMP);
		int t=n,Ans=0;
		int tjs=0,tje=n-1;
		int kis=0,kie=n-1;
		while(t--){
			if(tj[tjs]>ki[kis]){
				tjs++;kis++;
				Ans++;
			}else if(tj[tjs]<ki[kis]){
				tje--;kis++;
				Ans--;
			}else{
				if(tj[tje]<=ki[kie]){
					if(tj[tje]<ki[kis]){
						Ans--;
					}
					kis++; tje--;
				}else{
					tje--; kie--;
					Ans++;
				}
			}
		}
		printf("%d\n",Ans*200);
	}
}
