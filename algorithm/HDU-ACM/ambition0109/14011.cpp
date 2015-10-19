////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-05 19:58:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1401
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:24796KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<algorithm>
using namespace std;


bitset<100000000> Hash1;
bitset<100000000> Hash2;
int dir[4]={10,01,-10,-01};
int S1,S2;
struct Map{
	int ans;
	void set(){
		int num[4];
		num[0]=ans%100;
		num[1]=ans/100%100;
		num[2]=ans/10000%100;
		num[3]=ans/1000000%100;
		for(int i=0;i<4;i++){
			for(int j=i+1;j<4;j++){
				if(num[i]>num[j])
				{num[i]^=num[j];num[j]^=num[i];num[i]^=num[j];}
			}
		}
		ans=num[0]*1000000+num[1]*10000+num[2]*100+num[3];
	}
};
Map SS1,SS2;

bool RE(int nm){
	int num[4];
	num[0]=nm%100;
	num[1]=nm/100%100;
	num[2]=nm/10000%100;
	num[3]=nm/1000000%100;
	for(int i=0;i<4;i++){
		for(int j=i+1;j<4;j++){
			if(num[i]==num[j])
				return true;
		}
	}
	return false;
}

bool DBfs(){
	queue<Map> step[5][2];
	Hash1.reset();
	Hash2.reset();
	SS1.ans=S1;
	SS2.ans=S2;
	SS1.set();
	SS2.set();
	if(RE(SS1.ans)||RE(SS2.ans)) return false;
	if(SS1.ans==SS2.ans) return true;
	step[0][0].push(SS1);
	Hash1[SS1.ans]=true;
	step[0][1].push(SS2);
	Hash2[SS2.ans]=true;

	for(int TT=0;TT<4;TT++){
		for(int t=0;t<2;t++){
			while(!step[TT][t].empty()){
				int temp;Map T;
				temp=step[TT][t].front().ans;
				for(int i=1;i<=1000000;i*=100){
					for(int j=0;j<4;j++){
						if(j==1&&temp/i%10>=8) continue;
						else if(j==0&&temp/i/10%10>=8) continue;
						else if(j==3&&temp/i%10<=1) continue;
						else if(j==2&&temp/i/10%10<=1) continue;
						int tt=temp+dir[j]*i;
						if(RE(tt)){
							if(j==1&&tt/i%10>=8) continue;
							else if(j==0&&tt/i/10%10>=8) continue;
							else if(j==3&&tt/i%10<=1) continue;
							else if(j==2&&tt/i/10%10<=1) continue;
							tt+=dir[j]*i;
							if(RE(tt)) continue;
						}
						T.ans=tt;T.set();
						if(t==0){
							if(Hash1[T.ans]) continue;
							if(Hash2[T.ans]) return true;
						}
						if(t==1){
							if(Hash2[T.ans]) continue;
							if(Hash1[T.ans]) return true;
						}
						step[TT+1][t].push(T);
						if(t==0) Hash1[T.ans]=true;
						else Hash2[T.ans]=true;
					}
				}
				step[TT][t].pop();
			}
		}
	}
	return false;
}

int main()
{
	int num[4][2];
	while(scanf("%d%d",&num[0][0],&num[0][1])!=EOF){
		for(int i=1;i<4;i++){
			scanf("%d%d",&num[i][0],&num[i][1]);
		}
		S1=0;
		for(int i=0;i<4;i++){
			S1*=100;
			S1+=num[i][0]*10+num[i][1];
		}
		for(int i=0;i<4;i++){
			scanf("%d%d",&num[i][0],&num[i][1]);
		}
		S2=0;
		for(int i=0;i<4;i++){
			S2*=100;
			S2+=num[i][0]*10+num[i][1];
		}
		if(DBfs()) printf("YES\n");
		else printf("NO\n");
	}
}
