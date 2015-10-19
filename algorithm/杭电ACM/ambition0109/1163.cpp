////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-10 20:38:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1163
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:260KB
//////////////////System Comment End//////////////////
/*
 * 1163.cpp
 *
 *  Created on: 2010-8-10
 *      Author: ambition
 */

#include<iostream>
#include<cmath>
using namespace std;

inline int groot(int n){
	int r=n;
	while(r/10){
		n=r%10;
		while(r/=10){
			n+=r%10;
		}
		r=n;
	}
	return r;
}
int bpow(int n,int p){
	int ans;
	for(ans=1;p;p>>=1){
		if(p&1){
			ans=ans*n;
			ans=groot(ans);
		}
		n=n*n;
		n=groot(n);
//		cout<<n<<":"<<ans<<endl;
	}
	return groot(ans);
}
int main()
{
	int n;
	while(cin>>n,n){
//		cout<<groot(n)<<endl;
		cout<<bpow(groot(n),n)<<endl;
	}
}
