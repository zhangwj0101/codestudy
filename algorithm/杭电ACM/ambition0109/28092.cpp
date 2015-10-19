////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-09 20:32:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2809
////Problem Title: 
////Run result: Accept
////Run time:640MS
////Run memory:8420KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;

struct per{
	int ati,def,hp,exp;
}lb;
int n,m,aexp;
int dfs[2100000];
per emy[21];
per pu;

int Dfs(int step,int exp){
	int max=0;
	for(int i=0,t=1;i<n;i++,t<<=1){
		if(!(step&t)) continue;
		if(dfs[step^t]==-1){
			dfs[step^t]=Dfs(step^t,exp-emy[i].exp);
		}
		if(dfs[step^t]<=0) continue;
		int emyhp=emy[i].hp;
		int lv=(exp-emy[i].exp)/100;
		int ati=lb.ati+pu.ati*lv;
		int def=lb.def+pu.def*lv;
		int hp=dfs[step^t];
		int hit=ati>emy[i].def?(ati-emy[i].def):1;
		int lose=emy[i].ati>def?(emy[i].ati-def):1;
		emyhp-=hit;
		while(emyhp>0){
			hp-=lose;
			if(hp<=0) break;
			emyhp-=hit;
		}
		if(hp<=0) continue;
		if(exp/100>(exp-emy[i].exp)/100)
			hp+=pu.hp;
		if(hp>max) max=hp;
	}
	return max;
}

int main()
{
	while(scanf("%d%d%d",&lb.ati,&lb.def,&lb.hp)!=EOF){
		
		scanf("%d%d%d",&pu.ati,&pu.def,&pu.hp);
		scanf("%d",&n);m=aexp=0;
		for(int i=0;i<n;i++){
			char name[20];
			scanf("%s %d%d%d%d",name,&emy[i].ati,&emy[i].def,&emy[i].hp,&emy[i].exp);
			m<<=1;m+=1;aexp+=emy[i].exp;
		}
		memset(dfs,-1,sizeof(int)*2*m);
		dfs[0]=lb.hp;
		dfs[m]=Dfs(m,aexp);
		if(dfs[m]<=0){
			puts("Poor LvBu,his period was gone.");
			continue;
		}
		printf("%d\n",dfs[m]);
	}
}