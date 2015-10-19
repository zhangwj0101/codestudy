////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-06 12:42:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1560
////Problem Title: 
////Run result: Accept
////Run time:4890MS
////Run memory:12668KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<bitset>
#include<string>
#include<queue>
using namespace std;

int n;
int edna;
string map[8];
char fdna[4]={'A','C','G','T'};
int te[10],tk[10];
bitset<100000000> Hash;
struct step{
	int dna;
	short unsigned t;
	void set(int ndna,int nt){
		dna=ndna;t=nt;
	}
};
int Bfs()
{
	queue<step> steps;
	Hash.reset();
	step temp;
	temp.set(0,0);
	steps.push(temp);
	Hash[0]=1;
	while(!steps.empty()){
		int tdna=steps.front().dna;
		int tt=steps.front().t;
		steps.pop();
		int ttdna=tdna;
		for(int i=0;i<n;i++){
			tk[i]=ttdna%10;
			ttdna/=10;
		}
		for(int i=0;i<4;i++){
			int ttdna=tdna;
			for(int j=0,k=1;j<n;j++,k*=10){
				if(tk[j]==te[j]) continue;
				if(map[j][tk[j]]==fdna[i])
					ttdna+=k;
			}
			if(Hash[ttdna]) continue;
			if(ttdna==edna) return tt+1;
			temp.set(ttdna,tt+1);
			Hash[ttdna]=1;
			steps.push(temp);
		}
	}
	return -1;
}
int main()
{
	int t;cin>>t;
	while(t--){
		cin>>n;edna=0;
		for(int i=0,k=1;i<n;i++,k*=10){
			cin>>map[i];
			te[i]=int(map[i].length());
			edna+=te[i]*k;
		}
		cout<<Bfs()<<endl;
	}
}