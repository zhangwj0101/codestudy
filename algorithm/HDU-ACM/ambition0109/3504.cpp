////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-04 08:26:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3504
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:260KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<set>
#include<vector>
#include<string>
#include<memory>
#include<sstream>
#include<algorithm>
using namespace std;

struct lit{
	char ch;
	int count;
	void set(char nc,int ncount){
		ch=nc;count=ncount;
	}
};
bool compare(const lit &a,const lit &b){
	return a.ch>b.ch;
}
vector<lit> Lit;
int main()
{
	int t;cin>>t;
	while(t--){
		bool T=false;
		string str;
		cin>>str;
		Lit.clear();
		for(unsigned i=0;i<str.length();i++){
			unsigned j;
			for(j=0;j<Lit.size();j++){
				if(str[i]==Lit[j].ch){
					Lit[j].count++;
					break;
				}
			}
			if(j==Lit.size()){
				lit temp;
				temp.set(str[i],1);
				Lit.push_back(temp);
			}
		}
		sort(Lit.begin(),Lit.end(),compare);
		int sum=str.length();
		char pre='-',tc;
		while(1){
			int len=int(Lit.size());
			int max=0;
			for(int i=0;i<len;i++){
				if(Lit[i].count>max){
					max=Lit[i].count;
					tc=Lit[i].ch;
				}
			}
			if(max==0) break;
			if(max>sum/2&&pre!=tc){
				printf("%c",tc);pre=tc;
				sum--;
				for(unsigned i=0;i<Lit.size();i++){
					if(Lit[i].ch==tc){
						Lit[i].count--;
						break;
					}
				}
			}else{
				for(unsigned i=0;i<Lit.size();i++)
					if(Lit[i].count&&pre!=Lit[i].ch){
						pre=Lit[i].ch;sum--;
						printf("%c",Lit[i].ch);
						Lit[i].count--;
						break;
					}
			}
		}
		printf("\n");
	}
}
