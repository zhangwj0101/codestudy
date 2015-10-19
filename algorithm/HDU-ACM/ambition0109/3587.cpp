////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-31 17:57:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3587
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<map>
using namespace std;
struct player{
	__int64 money;
	int cnt;
	int update;
	int term;
};

map<string,player> all;
int main()
{
	int n,m,k;
	while(cin>>n>>m>>k){
		all.clear();
		string name;
		for(int i=0;i<n;i++){
			cin>>name;
			all[name].money=603;
			all[name].cnt=0;
			all[name].update=0;
			all[name].term=1;
		}
		for(int i=0;i<m;i++){
			cin>>name;
			all[name].money=603;
			all[name].cnt=0;
			all[name].update=0;
			all[name].term=2;
		}
		string cmd; bool fb=true;
		for(int i=0;i<k;i++){
			cin>>cmd;
			if(cmd=="K"){
				string p1,p2;int time;
				cin>>p1>>p2>>time;
				if(all[p1].term!=all[p2].term){
					all[p1].money+=time-all[p1].update;
					all[p1].update=time;
					all[p1].cnt++;
					all[p1].money+=200;
					if(all[p1].cnt>=3&&all[p1].cnt<=10){
						all[p1].money+=50*(all[p1].cnt-2);
					}else if(all[p1].cnt>10){
						all[p1].money+=400;
					}
					if(fb){
						all[p1].money+=200;
						fb=false;
					}

				}		
				all[p2].money+=time-all[p2].update;
				all[p2].update=time;
				all[p2].cnt=0;
				all[p2].money-=(300<all[p2].money?300:all[p2].money);
			}else if(cmd=="Q"){
				string p;int time;
				cin>>p>>time;
				all[p].money+=time-all[p].update;
				all[p].update=time;
				cout<<all[p].money<<endl;
			}
		}
	}
}
