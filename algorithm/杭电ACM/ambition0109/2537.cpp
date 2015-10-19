////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-20 19:35:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2537
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
/*
 * 2537.cpp
 *
 *  Created on: 2010-10-20
 *      Author: administrator
 */

#include<cstdio>
using namespace std;

char str[20];
int main(){
	int n;
	while(scanf("%d",&n),n){
		scanf("%s",str);
		int r=0,y=0;
		for(int i=0;i<n-1;i++){
			if(str[i]=='R'){
				r++;
			}else if(str[i]=='Y'){
				y++;
			}
		}
		if(str[n-1]=='B'){
			if(r==7){
				puts("Red");
			}else{
				puts("Yellow");
			}
		}else if(str[n-1]=='L'){
			if(y==7){
				puts("Yellow");
			}else{
				puts("Red");
			}
		}
	}
}
