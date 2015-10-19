////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-25 21:21:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3293
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:316KB
//////////////////System Comment End//////////////////
/*
 * 3293.cpp
 *
 *  Created on: 2010-9-25
 *      Author: administrator
 */

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;

struct Weapon{
	string name;
	string leave;
};
struct Origin{
	string Site;
	int id;
};

bool CMPW(const Weapon& a,const Weapon& b){
	if(a.leave==b.leave){
		return a.name<b.name;
	}else{
		if(a.leave=="wonderful"){
			return true;
		}else if(b.leave=="wonderful"){
			return false;
		}else if(a.leave=="so-so"){
			return false;
		}else if(b.leave=="so-so"){
			return true;
		}
	}
	return false;
}

bool CMPO(const Origin& a,const Origin& b){
	return a.Site<b.Site;
}

vector<Origin> origin;
vector<Weapon> List[505];

int main()
{
	int n,k,c=0;
	while(cin>>n){
		Origin to;
		Weapon tw;
		k=0;
		origin.clear();
		for(int i=0;i<=500;i++){
			List[i].clear();
		}
		for(int i=0;i<n;i++){
			cin>>tw.name>>to.Site>>tw.leave;
			int len=int(origin.size());
			bool flag=true;
			for(int j=0;j<len;j++){
				if(to.Site==origin[j].Site){
					List[j].push_back(tw);
					flag=false;
					break;
				}
			}
			if(flag){
				to.id=k++;
				origin.push_back(to);
				List[to.id].push_back(tw);
			}
		}
		sort(origin.begin(),origin.end(),CMPO);
		for(int i=0;i<k;i++){
			sort(List[i].begin(),List[i].end(),CMPW);
		}
		cout<<"Case "<<++c<<endl;
		for(int i=0;i<k;i++){
			cout<<origin[i].Site<<':'<<endl;
			int t=origin[i].id;
			for(int j=0;j<int(List[t].size());j++){
				cout<<"          "<<List[t][j].name<<' '<<List[t][j].leave<<endl;
			}
		}
	}
}
