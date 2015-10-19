////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-27 20:56:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1864
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:256KB
//////////////////System Comment End//////////////////
/*
 * 1864.cpp
 *
 *  Created on: 2010-10-27
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

struct Node{
	double goods[3],all;
}Inv;

double dp[35];
int main(){
	int n;
	double q;
	while(scanf("%lf%d",&q,&n),n){
		dp[0]=0;
		double tInv;
		double mmax=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				Inv.goods[j]=0;
			}
			int m;
			scanf("%d",&m);
			bool flag=false;
			for(int j=0;j<m;j++){
				char tch,tmp[100];
				double tm;
				scanf("%[^A-Z]",tmp);
				scanf("%c:%lf",&tch,&tm);
				if(tch!='A'&&tch!='B'&&tch!='C'){
					flag=true;
					continue;
				}
				Inv.goods[tch-'A']+=tm;
			}
			if(flag) continue;
			Inv.all=0;
			flag=false;
			for(int j=0;j<3;j++){
				Inv.all+=Inv.goods[j];
				if(Inv.goods[j]>600){
					flag=true;
					break;
				}
			}
			if(flag) continue;
			double tmax=0;
			for(int j=0;j<i;j++){
				tInv=dp[j]+Inv.all;
				if(tInv<=q&&tInv>tmax){
					tmax=tInv;
				}
			}
			dp[i]=tmax;
			if(dp[i]>mmax) mmax=dp[i];
		}
		printf("%.2lf\n",mmax);
	}
}
