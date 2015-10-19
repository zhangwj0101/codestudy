////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-20 20:18:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1070
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:220KB
//////////////////System Comment End//////////////////
/*
 * 1070.cpp
 *
 *  Created on: 2010-10-20
 *      Author: administrator
 */

#include<cstdio>
#include<algorithm>
using namespace std;

struct Milk{
	char name[110];
	int val;
	double rc;
}milk[110];

bool CMP(const Milk& a,const Milk& b){
	if(a.rc==b.rc) return a.val>b.val;
	return a.rc>b.rc;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			int cost,val;
			scanf("%s %d %d",milk[i].name,&cost,&milk[i].val);
			val=milk[i].val;
			if(val>1000) val=1000;
			val=val/200*200;
			milk[i].rc=double(val)/double(cost);
		}
		sort(milk,milk+n,CMP);
		printf("%s\n",milk[0].name);
	}

}
