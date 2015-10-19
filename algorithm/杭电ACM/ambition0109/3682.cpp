////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-15 17:52:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3682
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:4148KB
//////////////////System Comment End//////////////////
/*
 * 3682.cpp
 *
 *  Created on: 2010-12-15
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int Hash[1000005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		char str[50]; int tt=0;
		for(int i=0;i<m;i++){
			scanf("%s",str);
			char c1,c2; int cc1,cc2;
			sscanf(str,"%c=%d,%c=%d",&c1,&cc1,&c2,&cc2);
			int xx=0,yy=0,zz=0;
			if(c1=='X') xx=cc1;
			if(c1=='Y') yy=cc1;
			if(c1=='Z') zz=cc1;
			if(c2=='X') xx=cc2;
			if(c2=='Y') yy=cc2;
			if(c2=='Z') zz=cc2;
			if(zz==0){
				for(int j=1;j<=n;j++){
					Hash[tt++]=xx*1000000+yy*1000+j;
				}
			}
			if(yy==0){
				for(int j=1;j<=n;j++){
					Hash[tt++]=xx*1000000+j*1000+zz;
				}
			}
			if(xx==0){
				for(int j=1;j<=n;j++){
					Hash[tt++]=j*1000000+yy*1000+zz;
				}
			}
		}
		sort(Hash,Hash+tt);
		int Ans=1;
		for(int i=1;i<tt;i++){
			if(Hash[i]==Hash[i-1]) continue;
			Ans++;
		}
		printf("%d\n",Ans);
	}
}
