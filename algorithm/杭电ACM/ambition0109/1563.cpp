////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-05 16:54:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1563
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:288KB
//////////////////System Comment End//////////////////
/*
 * 1563.cpp
 *
 *  Created on: 2010-7-5
 *      Author: ambition
 */

#include<iostream>
using namespace std;

int num[201];
int main()
{
	int n;
	while(cin>>n,n)
	{
		for(int i=0;i<n;i++)
			cin>>num[i];
		for(int i=0;i<n;i++){
			int j;
			for(j=0;j<n;j++)
				if(i!=j&&num[i]==num[j]){
					break;
				}
			if(j==n){
				cout<<num[i]<<endl;
				break;
			}
		}
	}
}
