////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-08 18:36:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1022
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<queue>
#include<stack>
using namespace std;

stack<int> Sta;
queue<bool> Que;
int main()
{
	int n;
	while(cin>>n){
		string s1,s2;
		cin>>s1>>s2;
		int i=0,j=0;
		Sta.push(s1[i++]);
		Que.push(true);
		while(1){
			if(!Sta.empty()&&s2[j]==Sta.top()){
				Sta.pop();
				Que.push(false);
				j++;
			}else if(i<n){
				Sta.push(s1[i++]);
				Que.push(true);
			}else{
				break;
			}
		}
		if(Sta.empty()){
			cout<<"Yes."<<endl;
			while(!Que.empty()){
				if(Que.front()) cout<<"in"<<endl;
				else cout<<"out"<<endl;
				Que.pop();
			}
		}else{
			cout<<"No."<<endl;
			while(!Que.empty()) Que.pop();
			while(!Sta.empty()) Sta.pop();
		}
		cout<<"FINISH"<<endl;
	}
}