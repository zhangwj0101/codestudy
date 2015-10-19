////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-20 18:40:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3554
////Problem Title: 
////Run result: Accept
////Run time:281MS
////Run memory:192KB
//////////////////System Comment End//////////////////
/*
 * 3554.cpp
 *
 *  Created on: 2010-8-20
 *      Author: ambition
 */

#include<cstdio>
using namespace std;
#include<memory.h>

bool ac[1010];
int acmer[1010][2];
int main()
{
	int n,s,p;
	while(scanf("%d%d%d",&n,&s,&p)!=EOF){
		memset(ac,false,sizeof(ac));
		memset(acmer,0,sizeof(acmer));
		for(int i=0;i<n;i++){
			int sum=0;
			for(int j=0;j<s;j++){
				scanf("%d",&ac[j]);
				if(ac[j]) sum++;
			}
			for(int j=0;j<s;j++){
				if(ac[j]){
					acmer[j][0]++;
					acmer[j][1]+=s-sum;
				}
			}
		}
		int count=0;
		for(int i=0;i<s;i++){
			if(acmer[i][1]>acmer[p-1][1]){
				count++;continue;
			}else if(acmer[i][1]<acmer[p-1][1]){
				continue;
			}else{
				if(acmer[i][0]>acmer[p-1][0]){
					count++;continue;
				}else if(acmer[i][0]<acmer[p-1][0]){
					continue;
				}else{
					if(i<p-1){
						count++;
					}
				}
			}
		}
		printf("%d %d\n",acmer[p-1][1],count+1);
	}
}
