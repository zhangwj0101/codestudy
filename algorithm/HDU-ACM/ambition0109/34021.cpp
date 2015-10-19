////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-21 20:00:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3402
////Problem Title: 
////Run result: Accept
////Run time:203MS
////Run memory:636KB
//////////////////System Comment End//////////////////
/*
 * 3402.cpp
 *
 *  Created on: 2010-10-21
 *      Author: administrator
 */

#include<cstdio>
#include<algorithm>
using namespace std;

inline void scan_ud(int &num)
{
	char in;
	in=getchar();
	while(in<'0'||in>'9'){
		in=getchar();
	} num=in-'0';
	in=getchar();
	while(in>='0'&&in<='9'){
		num*=10;num+=in-'0';
		in=getchar();
	}
}

int num[100010];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,r;
		scanf("%d%d",&n,&r);
		for(int i=0;i<n;i++){
			scan_ud(num[i]);
		}
		sort(num,num+n);
		int max=0;
		for(int i=1;i<n;i++){
			if(num[i]-num[i-1]>max){
				max=num[i]-num[i-1];
			}
		}
		if(max==0) puts("Inf");
		else{
			double Ans=6.28318531*(double)r/(double)(n*max);
			printf("%.3lf\n",Ans);
		}
	}
}
