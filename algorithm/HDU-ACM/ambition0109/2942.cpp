////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-09 11:28:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2942
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
/*
 * 2942.cpp
 *
 *  Created on: 2010-10-4
 *      Author: administrator
 */

#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int num[105];
int main(){
	int n;
	while(scanf("%d",&n),n){
		int Sum=0;
		for(int i=0;i<n;i++){
			scanf("%d",&num[i]);
			Sum+=num[i];
		}
		if((Sum*2%n)||n%2){
			puts("No");
			continue;
		}
		int pair=Sum*2/n;
		bool flag=true;
		for(int i=0;i<n/2;i++){
			if(num[i]+num[n-i-1]!=pair){
				flag=false;
				break;
			}
		}
		puts(flag?"Yes":"No");
	}
}
