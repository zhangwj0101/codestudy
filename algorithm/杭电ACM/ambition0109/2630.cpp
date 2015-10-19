////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-10 19:17:56
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2630
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:324KB
//////////////////System Comment End//////////////////
/*
 * 2630.cpp
 *
 *  Created on: 2010-7-10
 *      Author: ambition
 */

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		string name;
		int mm,ss;
		long long time=0;
		while(n--){
			cin>>name;
			scanf("%d:%d",&mm,&ss);
			if((name=="S.H.E")||(name=="Jay")||(name=="Elva")||(name=="Jolin")
					||(name=="Aska")||(name=="Yoga"))
			time+=mm*60+ss;
		}
		int H,M,S;
		H=time/3600;
		M=(time%3600)/60;
		S=time%60;
		cout<<"Samuel will watch Channel[V] for "<<H;
		cout<<" hour(s),"<<M<<" minute(s),";
		cout<<S<<" second(s)."<<endl;

	}
}
