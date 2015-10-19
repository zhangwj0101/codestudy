////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-26 19:11:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2845
////Problem Title: 
////Run result: Accept
////Run time:375MS
////Run memory:224KB
//////////////////System Comment End//////////////////
/*
 * 2845.cpp
 *
 *  Created on: 2010-10-26
 *      Author: hduacm
 */

#include<cstdio>
using namespace std;

int Max(const int& a,const int& b){
	int dif=b-a;
	return b-(dif&(dif>>31));
}

int Min(const int& a,const int& b){
	int dif=b-a;
	return a+(dif&(dif>>31));
}

int Dp(int num[],int n){
	int mmax=num[0];
	for(int i=1;i<n;i++){
		int tmax=0;
		for(int j=Max(0,i-3);j<i-1;j++){
			tmax=Max(num[j],tmax);
		}
		num[i]+=tmax;
		mmax=Max(num[i],mmax);
	}
	return mmax;
}

int nn[200010],mm[200010];
int main()
{
	int x,y;
	while(scanf("%d%d",&x,&y)!=EOF){
		for(int i=0;i<x;i++){
			for(int j=0;j<y;j++){
				scanf("%d",&nn[j]);
			}
			mm[i]=Dp(nn,y);
		}
		int Ans=Dp(mm,x);
		printf("%d\n",Ans);
	}
}
