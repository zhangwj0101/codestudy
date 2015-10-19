////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-09 15:04:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1074
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:544KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<stack>
#include<string>
using namespace std;
const int INF=0x7fffffff;

int n,ad,m;
int dfs[40000];
int dl[16],dn[16];
int Pre[40000];
int din[16]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
int Dfs(int get,int day)
{
	int max=INF;
	if(!get) return 0;
	for(int i=0,t=1;i<n;i++,t<<=1){
		if(get&t){
			if(dfs[get^t]==-1){
				dfs[get^t]=Dfs(get^t,day-dn[i]);
			}
			int cost=day-dl[i];
			if(cost<0) cost=0;
			if(cost+dfs[get^t]<=max){
				max=cost+dfs[get^t];
				Pre[get]=get^t;
			}
		}
	}
	return max;
}
string name[16];
stack<int> out;
int main()
{
	int t;cin>>t;
	while(t--){
		memset(dfs,-1,sizeof(dfs));
		cin>>n;ad=m=0;
		for(int i=0;i<n;i++){
			cin>>name[i]>>dl[i]>>dn[i];
			ad+=dn[i];
			m<<=1;m|=1;
		}
		dfs[m]=INF;
		dfs[m]=Dfs(m,ad);
		cout<<dfs[m]<<endl;
		int k=m;
		out.push(k);
		while(Pre[k]){
			out.top()-=Pre[k];
			out.push(Pre[k]);
			k=Pre[k];
		}
		while(!out.empty()){
			for(int i=0;i<16;i++){
				if(din[i]==out.top()){
					cout<<name[i]<<endl;
					break;
				}
			}
			out.pop();
		}
	}
}