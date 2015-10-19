////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-07 09:57:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1272
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:688KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int Set[100001];
bool Hash[100001];
int Find(int n) {
	if(Set[n]==-1) return n;
	return Set[n]=Find(Set[n]);
}
bool Merge(int s1,int s2)
{
	int r1=Find(s1);
	int r2=Find(s2);
	if(r1==r2) return false;
	if(r1<r2) Set[r2]=r1;
	else Set[r1]=r2;
	return true;
}
void main()
{
	int n,m,max; bool t;
	while(scanf("%d%d",&n,&m),n+1||m+1){
		if(n==m&&n==0){
			printf("Yes\n");
			continue;
		}
		memset(Set,-1,sizeof(Set));
		memset(Hash,false,sizeof(Hash));
		Merge(n,m);t=true;
		max=n>m?n:m;
		Hash[n]=Hash[m]=true;
		while(scanf("%d%d",&n,&m),n||m){
			Hash[n]=Hash[m]=true;
			if(n>max) max=n;
			if(m>max) max=m;
			if(n==m) continue;
			if(t&&!Merge(n,m)){
				t=false;
			}
		}
		if(t){
			bool root=false;
			for(int i=1;i<=max;i++){
				if(!Hash[i]) continue;
				if(!root&&Set[i]==-1){
					root=true;
				}else if(Set[i]==-1){
					t=false;break;
				}
			}
		}
		if(t) printf("Yes\n");
		else printf("No\n");
	}
}