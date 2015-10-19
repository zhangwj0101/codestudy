////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-09 20:25:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2809
////Problem Title: 
////Run result: Accept
////Run time:703MS
////Run memory:8484KB
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
		per temp(lb);int emyhp=emy[i].hp;
		int lv=(exp-emy[i].exp)/100;
		temp.ati+=pu.ati*lv;
		temp.def+=pu.def*lv;
		temp.hp=dfs[step^t];
		int hit=temp.ati>emy[i].def?(temp.ati-emy[i].def):1;
		int lose=emy[i].ati>temp.def?(emy[i].ati-temp.def):1;
		emyhp-=hit;
		while(emyhp>0){
			temp.hp-=lose;
			if(temp.hp<=0) break;
			emyhp-=hit;
		}
		if(temp.hp<=0) continue;
		if(exp/100>(exp-emy[i].exp)/100)
			temp.hp+=pu.hp;
		if(temp.hp>max) max=temp.hp;
	}
	return max;
}

int main()
{
	while(cin>>lb.ati>>lb.def>>lb.hp){
		
		cin>>pu.ati>>pu.def>>pu.hp;
		cin>>n;m=aexp=0;
		for(int i=0;i<n;i++){
			string name;
			cin>>name>>emy[i].ati>>emy[i].def>>emy[i].hp>>emy[i].exp;
			m<<=1;m+=1;aexp+=emy[i].exp;
		}
		memset(dfs,-1,sizeof(int)*2*m);
		dfs[0]=lb.hp;
		dfs[m]=Dfs(m,aexp);
		if(dfs[m]<=0){
			cout<<"Poor LvBu,his period was gone."<<endl;
			continue;
		}
		cout<<dfs[m]<<endl;
	}
}