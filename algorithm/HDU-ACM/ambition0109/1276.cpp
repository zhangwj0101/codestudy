////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-05 19:20:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1276
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:312KB
//////////////////System Comment End//////////////////
/*
 * 1276.cpp
 *
 *  Created on: 2010-7-5
 *      Author: ambition
 */

#include<iostream>
using namespace std;

int num[5001];
int main()
{
	int t;
	for(cin>>t;t--;)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			num[i]=i;
		while(n>3){
			int i,j;
			for(i=j=1;i<=n;i++){
				if(i%2){
					num[j]=num[i];
					j++;
				}
			}
			n=j-1;
			if(n>3){
				for(i=j=1;i<=n;i++){
					if(i%3){
						num[j]=num[i];
						j++;
					}
				}
				n=j-1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(i!=1) cout<<' ';
			cout<<num[i];
		}
		cout<<endl;
	}
}
