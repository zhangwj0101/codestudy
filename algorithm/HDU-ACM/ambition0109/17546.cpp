////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-11 14:46:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1754
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:1776KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX(x,y) (x>y?x:y)
#define Lowbit(x) (x&(-x))

inline void in(int &num){
	char in=getchar();
	while(in<'0'||in>'9'){
		in=getchar();
	}
	num=in-'0';
	in=getchar();
	while(in>='0'&&in<='9'){
		num*=10; num+=in-'0';
		in=getchar();
	}
}

int num[200010],N;
int idx[200010];
void Init(){
	for(int ii=1;ii<=N;ii++){
		idx[ii]=num[ii];
		for(int i=1;i<Lowbit(ii);i<<=1){
			idx[ii]=MAX(idx[ii],idx[ii-i]);
		}
	}
}

void Modify(int p,int v){
	bool flag=num[p]>v; num[p]=v;
	for(int i=p;i<=N;i+=Lowbit(i)){
		idx[i]=MAX(idx[i],v);
		if(flag){
			for(int j=1;j<Lowbit(i);j<<=1){
				idx[i]=MAX(idx[i],idx[i-j]);
			}
		}
	}
}

int Query(int l,int r){
	int ans=num[r];
	while(true){
		ans=MAX(ans,num[r]);
		if(r==l) break;
		for(r-=1;r-l>=Lowbit(r);r-=Lowbit(r)){
			ans=MAX(ans,idx[r]);
		}
	}
	return ans;
}

int main(){
	int &n=N,m;
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++){
			in(num[i]);
		}
		Init();
		char cmd[5];
		for(int i=0;i<m;i++){
			scanf("%s",cmd);
			if(cmd[0]=='U'){
				int p,v;
				scanf("%d%d",&p,&v);
				Modify(p,v);
			}else if(cmd[0]=='Q'){
				int l,r;
				scanf("%d%d",&l,&r);
				printf("%d\n",Query(l,r));
			}

		}
	}
}