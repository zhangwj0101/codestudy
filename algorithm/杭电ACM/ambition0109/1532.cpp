////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-04 20:10:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1532
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:360KB
//////////////////System Comment End//////////////////
/*
 * 1532.cpp
 *
 *  Created on: 2010-11-4
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int Map[205][205];
int QUE[1000000];
int pre[205];
int EK(int START,int END,int n){
	int MFlow=0,qs,qe;
	while(true){
		QUE[qs=qe=0]=START;
		memset(pre,0,sizeof(pre));
		while(qs<=qe){
			int ts=QUE[qs++];
			for(int i=1;i<=n;i++){
				if(pre[i]==0&&Map[ts][i]){
					pre[i]=ts;
					QUE[++qe]=i;
				}
			}
			if(pre[END]){
				break;
			}
		}
		if(!pre[END]){
			break;
		}
		int mval=Map[pre[END]][END],tt=pre[END];
		while(tt!=START){
			if(mval>Map[pre[tt]][tt]){
				mval=Map[pre[tt]][tt];
			}
			tt=pre[tt];
		}
		tt=END;
		while(tt!=START){
			Map[pre[tt]][tt]-=mval;
			Map[tt][pre[tt]]+=mval;
			tt=pre[tt];
		}
		MFlow+=mval;
	}
	return MFlow;
}


int main(){
	int n,m;
	while(~scanf("%d%d",&m,&n)){
		memset(Map,0,sizeof(Map));
		for(int i=0;i<m;i++){
			int c1,c2,val;
			scanf("%d%d%d",&c1,&c2,&val);
			Map[c1][c2]+=val;
//			Map[c2][c1]-=val;
		}
		int Ans=EK(1,n,n);
		printf("%d\n",Ans);
	}
}
