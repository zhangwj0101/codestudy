////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-19 15:11:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1113
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
/*
 * 1113.cpp
 *
 *  Created on: 2010-11-19
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Dic{
	char str[10];
	int Hs[26];
	void Hash(){
		memset(Hs,0,sizeof(Hs));
		for(int i=0;str[i];i++){
			Hs[str[i]-'a']++;
		}
	}
	bool Same(const Dic& t){
		for(int i=0;i<26;i++){
			if(Hs[i]!=t.Hs[i]) return false;
		}
		return true;
	}
	void Put(){
		printf("%s ",str);
		for(int i=0;i<26;i++){
			printf("%d ",Hs[i]);
		}
		puts("");
	}
}dic[105];

bool cmp(const Dic& a,const Dic& b){
	if(strcmp(a.str,b.str)<0) return true;
	return false;
}

int main(){
	int t=0;
	while(scanf("%s",dic[t].str),strcmp(dic[t].str,"XXXXXX")){
		dic[t++].Hash();
		//dic[t-1].Put();
	}
	sort(dic,dic+t,cmp);
	Dic word;
	while(scanf("%s",word.str),strcmp(word.str,"XXXXXX")){
		word.Hash();
		//word.Put();
		bool f=false;
		for(int i=0;i<t;i++){
			if(word.Same(dic[i])){
				puts(dic[i].str);
				f=true;
			}
		}
		if(!f) puts("NOT A VALID WORD");
		puts("******");
	}
}
