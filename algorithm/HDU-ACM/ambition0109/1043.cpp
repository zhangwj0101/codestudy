////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-13 17:08:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1043
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:4396KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<map>
#include<cstring>
#include<ctime>
#include<queue>
using namespace std;

//int t=0;
int fac[9]={1,1,2,6,24,120,720,5040,40320};
struct step{
	char s[10];
	int x;
};
struct pre{
	int next;
	char cmd;
};
inline int Hash(char s[])
{
	int h=0;
	for(int i=1;i<9;i++){
		int t=0;
		for(int j=i-1;j>=0;j--)
			if(s[j]>s[i]) t++;
		h+=t*fac[i];
	}
	return h;
}
bool hs[362880];
pre pres[362880];

void Bfs()
{
	queue<step> steps;
	step tstep;
	for(int i=0;i<8;i++)
		tstep.s[i]=i+'0';
	tstep.s[8]='x';
	tstep.x=8;
	steps.push(tstep);
	hs[Hash("12345678x")]=true;
	while(!steps.empty()){
		/*t++;*/
		step ts=steps.front();
		int tx=ts.x;
		int ph=Hash(ts.s);
		steps.pop();
		if(ts.x>2){
			step tts=ts;
			tts.s[tx]=tts.s[tx-3];
			tts.s[tx-3]='x';
			int th=Hash(tts.s);
			if(!hs[th]){
				tts.x-=3;
				steps.push(tts);
				pres[th].next=ph;
				pres[th].cmd='d';
				hs[th]=true;
			}
		}
		if(tx<6){
			step tts=ts;
			tts.s[tx]=tts.s[tx+3];
			tts.s[tx+3]='x';
			int th=Hash(tts.s);
			if(!hs[th]){
				tts.x+=3;
				steps.push(tts);
				pres[th].next=ph;
				pres[th].cmd='u';
				hs[th]=true;
			}
		}
		if(tx==1||tx==2||tx==4||tx==5||tx==7||tx==8){
			step tts=ts;
			tts.s[tx]=tts.s[tx-1];
			tts.s[tx-1]='x';
			int th=Hash(tts.s);
			if(!hs[th]){
				tts.x-=1;
				steps.push(tts);
				pres[th].next=ph;
				pres[th].cmd='r';
				hs[th]=true;
			}
		}
		if(tx==0||tx==1||tx==3||tx==4||tx==6||tx==7){
			step tts=ts;
			tts.s[tx]=tts.s[tx+1];
			tts.s[tx+1]='x';
			int th=Hash(tts.s);
			if(!hs[th]){
				tts.x+=1;
				steps.push(tts);
				pres[th].next=ph;
				pres[th].cmd='l';
				hs[th]=true;
			}
		}
	}
}

int main(){
	char n[100];
	Bfs();
	char start[10];
	while(gets(n)){
		for(unsigned i=0,t=0;i<strlen(n);i++){
			if((n[i]<='9'&&n[i]>='0')||n[i]=='x'){
				start[t]=n[i];
				t++;
			}
		}
		if(!strcmp("12345678x",start)){ puts("");continue;}
		if(!hs[Hash(start)]){ puts("unsolvable");continue;}
		int next=Hash(start);
		while(1){
			printf("%c",pres[next].cmd);
			next=pres[next].next;
			if(next==Hash("12345678x")) break;
		}
		puts("");
	}
}