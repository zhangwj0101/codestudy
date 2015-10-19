////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-10 10:54:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1181
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:320KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;
#include<memory.h>

string word[100];
bool Hash[100];
int n;
bool dfs(char top){
	if(top=='m') return true;
	for(int i=0;i<n;i++){
		if(Hash[i]&&word[i][0]==top){
			Hash[i]=false;
			if(dfs(word[i][1])) return true;
			Hash[i]=true;
		}
	}
	return false;
}
int main(){
	n=0;
	while(cin>>word[n]){
		if(word[n]!="0"&&word[n].length()==1){
			n--;continue;
		}
		word[n][1]=word[n][word[n].length()-1];
		if(word[n]=="0"){
			int i;
			memset(Hash,true,sizeof(Hash));
			for(i=0;i<n;i++){
				if(word[i][0]=='b'){
					Hash[i]=false;
					if(dfs(word[i][1])){
						cout<<"Yes."<<endl;
						break;
					}
					Hash[i]=true;
				}
			}
			if(i==n){
				cout<<"No."<<endl;
			}
			n=0;
		}
		n++;
	}
}
