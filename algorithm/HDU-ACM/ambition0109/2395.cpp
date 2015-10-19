////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-04 21:17:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2395
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
/*
 * 2397.cpp
 *
 *  Created on: 2010-10-4
 *      Author: administrator
 */

#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct TIME{
	int status;
	int step;
	void set(int nstatus,int nstep){
		status=nstatus;
		step=nstep;
	}
};
int Turn(int status,int time){
	int h=status/100;
	int tm=(status%100)/10;
	int m=status%10;
	if(time==-1||time==1){
		m+=time;
		if(m>10) m-=10;
		if(m<0) m+=10;
	}else if(time==-10||time==10){
		tm+=time/10;
		if(tm>6) tm-=6;
		if(tm<0) tm+=6;
	}else if(time==-100||time==100){
		h+=time/100;
		if(h>=12) h-=12;
		if(h<1) h+=12;
	}
	return h*100+tm*10+m;
}

int start,end;
bool Hash[1300];
int Bfs(){
	queue<TIME> QUE;
	TIME Tmp;
	Tmp.set(start,0);
	QUE.push(Tmp);
	Hash[start]=true;
	while(!QUE.empty()){
		int tstatus=QUE.front().status;
		int tstep=QUE.front().step;
		QUE.pop();
		int tts=Turn(tstatus,-1);
		if(!Hash[tts]){
			if(tts==end) return tstep+1;
			Hash[tts]=true;
			Tmp.set(tts,tstep+1);
			QUE.push(Tmp);
		}
		tts=Turn(tstatus,-10);
		if(!Hash[tts]){
			if(tts==end) return tstep+1;
			Hash[tts]=true;
			Tmp.set(tts,tstep+1);
			QUE.push(Tmp);
		}
		tts=Turn(tstatus,-100);
		if(!Hash[tts]){
			if(tts==end) return tstep+1;
			Hash[tts]=true;
			Tmp.set(tts,tstep+1);
			QUE.push(Tmp);
		}
		tts=Turn(tstatus,1);
		if(!Hash[tts]){
			if(tts==end) return tstep+1;
			Hash[tts]=true;
			Tmp.set(tts,tstep+1);
			QUE.push(Tmp);
		}
		tts=Turn(tstatus,10);
		if(!Hash[tts]){
			if(tts==end) return tstep+1;
			Hash[tts]=true;
			Tmp.set(tts,tstep+1);
			QUE.push(Tmp);
		}
		tts=Turn(tstatus,100);
		if(!Hash[tts]){
			if(tts==end) return tstep+1;
			Hash[tts]=true;
			Tmp.set(tts,tstep+1);
			QUE.push(Tmp);
		}
	}
	return -1;
}

int main()
{
	int n;
	char SS[20],EE[20];
	scanf("%d",&n);
	while(n--){
		memset(Hash,false,sizeof(Hash));
		scanf("%s %s",SS,EE);
		int h,m;
		char tsa[5],tsb[5];
		sscanf(SS,"%d:%d%s",&h,&m,tsa);
		start=h*100+m;
		sscanf(EE,"%d:%d%s",&h,&m,tsb);
		end=h*100+m;
		int Ans=0;
		if(strcmp(tsa,tsb)) Ans+=1;
		if(start!=end) Ans+=Bfs();
		printf("Going from %s to %s requires %d push",SS,EE,Ans);
		if(Ans!=1) printf("es");
		puts(".");
	}
}
