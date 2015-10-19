////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-02 22:23:26
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2209
////Problem Title: 
////Run result: Accept
////Run time:656MS
////Run memory:5408KB
//////////////////System Comment End//////////////////
/*
 * 2209.cpp
 *
 *  Created on: 2010-10-2
 *      Author: administrator
 */

#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct Step{
	int num,step;
	void set(int tn,int ts){
		num=tn;step=ts;
	}
};

int Hash[1050000];
int len;
int Bfs(int start){
	queue<Step> QUE;
	Step TS;
	TS.set(start,0);
	QUE.push(TS);
	Hash[start]=true;
	while(!QUE.empty()){
		int tnum=QUE.front().num;
		int tstep=QUE.front().step;
		QUE.pop();
		int ttn=tnum,Bit=3;
		ttn^=Bit;
		if(ttn==0) return tstep+1;
		if(!Hash[ttn]){
			TS.set(ttn,tstep+1);
			QUE.push(TS);
			Hash[ttn]=true;
		}
		if(len>2){
			for(int i=0;i<len-2;i++){
				Bit<<=1;
				if(i==0) Bit++;
				ttn=tnum;
				ttn^=Bit;
				if(ttn==0) return tstep+1;
				if(!Hash[ttn]){
					TS.set(ttn,tstep+1);
					QUE.push(TS);
					Hash[ttn]=true;
				}
			}
			Bit-=(Bit&(-Bit));
			ttn=tnum;
			ttn^=Bit;
			if(ttn==0) return tstep+1;
			if(!Hash[ttn]){
				TS.set(ttn,tstep+1);
				QUE.push(TS);
				Hash[ttn]=true;
			}
		}
	}
	return -1;
}

int main(){
	int n;
	char str[25];
	while(scanf("%s",str)!=EOF){
		len=strlen(str);
		n=0;
		memset(Hash,false,sizeof(Hash));
		for(int i=0;i<len;i++){
			n*=2;
			n+=str[i]-'0';
		}
		if(n&&len!=1){
			int Ans=Bfs(n);
			if(Ans==-1){
				puts("NO");
			}else{
				printf("%d\n",Ans);
			}
		}else{
			puts(n?"1":"0");
		}
	}
}
