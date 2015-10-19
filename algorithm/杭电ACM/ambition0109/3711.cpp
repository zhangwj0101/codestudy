////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-16 13:13:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3711
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<algorithm>
using namespace std;

inline int CntBit(int num){
	int cnt=0;
	while(num){
		num&=(num-1);
		cnt++;
	}
	return cnt;
}

int numa[105],numb[105];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%d",&numa[i]);
		}
		sort(numa,numa+n);
		for(int i=0;i<m;i++){
			scanf("%d",&numb[i]);
		}
		for(int i=0;i<m;i++){
			int min=100000,ans=numa[0];
			for(int j=0;j<n;j++){
				int t=CntBit(numb[i]^numa[j]);
//				printf("-- %d\n",t);
				if(min>t){
					min=t;
					ans=numa[j];
				}
			}
			printf("%d\n",ans);
		}
	}
}