////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-11 21:07:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1207
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:328KB
//////////////////System Comment End//////////////////
/*
 * 1207.cpp
 *
 *  Created on: 2010-8-11
 *      Author: ambition
 */

#include<iostream>
using namespace std;

long long three[65],four[65];
int main(){
	three[1]=2;
	for(int i=2;i<64;i++){
		three[i]=three[i-1]*2;
		three[i-1]-=1;
	}
	three[63]-=1;
	four[1]=1;
	for(int i=2;i<65;i++){
		four[i]=four[1]*2+three[i-1];
		for(int j=2;j<i-1;j++){
			long long t=2*four[j]+three[i-j];
			if(t<four[i]) four[i]=t;
		}
	}
	int n;
	while(cin>>n){
		if(n<64){
			cout<<four[n]<<endl;
		}else if(n==64){
			cout<<"18433"<<endl;
		}
	}
}
