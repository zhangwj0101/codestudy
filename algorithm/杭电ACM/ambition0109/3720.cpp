////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-28 19:17:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3720
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:256KB
//////////////////System Comment End//////////////////
/*
 * tju_a.cpp
 *
 *  Created on: 2010-10-31
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<string>
using namespace std;

struct Player{
	int id,val;
};
struct Link{
	int ida,idb,val;
};
vector<Player> play[4];
vector<Link> Links;
map<string,int> ID;
bool Hash[24];
int m;

int Dfs(int deep){
	int t,s;
	if(deep==0){ t=0; s=0;}
	else if(deep<=4){ t=1; s=deep-1;}
	else if(deep<=8){ t=2; s=deep-5;}
	else if(deep<=10){ t=3; s=deep-9;}
	else if(deep==11){
		int Sum=0;
		for(int i=0;i<m;i++){
			if(Hash[Links[i].ida]&&Hash[Links[i].idb]){
				Sum+=Links[i].val;
			}
		}
		return Sum;
	}
	int Max=-1000000;
	for(int i=0;i<int(play[t].size());i++){
		if(Hash[play[t][i].id]){
			s--;
			continue;
		}
		if(s) continue;
		Hash[play[t][i].id]=true;
		int tmp=Dfs(deep+1)+play[t][i].val;
		if(tmp>Max) Max=tmp;
		Hash[play[t][i].id]=false;
	}
	return Max;
}

void Init(){
	memset(Hash,false,sizeof(Hash));
	Links.clear();
	for(int i=0;i<4;i++){
		play[i].clear();
	}
	ID.clear();
}
int main(){
	char name[35],kind[15];
	Player tmp;
	while(~scanf("%s %d %s",name,&tmp.val,kind)){
		Init();
		ID[name]=tmp.id=0;
		if(kind[0]=='g'){
			play[0].push_back(tmp);
		}else if(kind[0]=='d'){
			play[1].push_back(tmp);
		}else if(kind[0]=='m'){
			play[2].push_back(tmp);
		}else if(kind[0]=='s'){
			play[3].push_back(tmp);
		}
		for(int i=1;i<=22;i++){
			scanf("%s %d %s",name,&tmp.val,kind);
			ID[name]=tmp.id=i;
			if(kind[0]=='g'){
				play[0].push_back(tmp);
			}else if(kind[0]=='d'){
				play[1].push_back(tmp);
			}else if(kind[0]=='m'){
				play[2].push_back(tmp);
			}else if(kind[0]=='s'){
				play[3].push_back(tmp);
			}
		}
		scanf("%d",&m);
		char na[35],nb[35];
		Link ttmp;
		for(int i=0;i<m;i++){
			scanf("%s %s %d",na,nb,&ttmp.val);
			ttmp.ida=ID[na];
			ttmp.idb=ID[nb];
			Links.push_back(ttmp);
		}
		if(play[0].size()<1||play[1].size()<4||play[2].size()<4||play[3].size()<2){
			puts("impossible");
			continue;
		}
		int Ans=Dfs(0);
		printf("%d\n",Ans);
	}
}
