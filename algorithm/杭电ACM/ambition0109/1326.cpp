////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-30 20:44:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1326
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:152KB
//////////////////System Comment End//////////////////
/*
 * 1326.cpp
 *
 *  Created on: 2010-8-30
 *      Author: ambition
 */

#include<cstdio>
using namespace std;

int num[50];
int main()
{
	int n,c=0;
	while(scanf("%d",&n),n){
		int sum=0;
		for(int i=0;i<n;i++){
			scanf("%d",&num[i]);
			sum+=num[i];
		}
		int ave=sum/n;
		sum=0;
		for(int i=0;i<n;i++){
			if(num[i]>ave){
				sum+=num[i]-ave;
			}
		}
		printf("Set #%d\n",++c);
		printf("The minimum number of moves is %d.\n\n",sum);
	}
}
