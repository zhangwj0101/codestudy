////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-20 19:24:08
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1259
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:152KB
//////////////////System Comment End//////////////////
/*
 * 1259.cpp
 *
 *  Created on: 2010-8-20
 *      Author: ambition
 */

#include<cstdio>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int j=2;
		for(int i=0;i<n;i++){
			int c1,c2;
			scanf("%d%d",&c1,&c2);
			if(c1==j) j=c2;
			else if(c2==j) j=c1;
		}
		printf("%d\n",j);
	}
}
