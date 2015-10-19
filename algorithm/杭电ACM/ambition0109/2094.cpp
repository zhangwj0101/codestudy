////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-18 19:30:08
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2094
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:332KB
//////////////////System Comment End//////////////////
/*
 * 2094.cpp
 *
 *  Created on: 2010-7-18
 *      Author: ambition
 */

#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> all;
vector<string> winer;

int main()
{
	int n;
	while(cin>>n,n)
	{
		all.clear();
		winer.clear();
		string w,f;
		for(int i=0;i<n;i++){
			cin>>w>>f;
			unsigned i;
			for(i=0;i<all.size();i++)
				if(w==all[i]) break;
			if(i==all.size()){
				all.push_back(w);
				winer.push_back(w);
			}
			for(i=0;i<all.size();i++)
				if(f==all[i]) break;
			if(i==all.size()){
				all.push_back(f);
			}else{
				for(i=0;i<winer.size();i++)
					if(winer[i]==f) winer.erase(winer.begin()+i);
			}
		}
		if(winer.size()!=1) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
}
