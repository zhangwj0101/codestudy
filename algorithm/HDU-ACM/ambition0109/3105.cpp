////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-29 18:22:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3105
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:192KB
//////////////////System Comment End//////////////////
/*
 * 3105.cpp
 *
 *  Created on: 2010-9-29
 *      Author: administrator
 */

#include<cstdio>
#include<cstring>
using namespace std;

bool Lotto[50];
int main()
{
	int n;
	while(scanf("%d",&n),n){
		memset(Lotto,false,sizeof(Lotto));
		int num;
		for(int i=0;i<n;i++){
			for(int j=0;j<6;j++){
				scanf("%d",&num);
				Lotto[num]=true;
			}
		}
		for(int i=1;i<50;i++){
			if(!Lotto[i]){
				goto No;
			}
		}
		puts("Yes");
		continue;
No:
		puts("No");
	}
}
