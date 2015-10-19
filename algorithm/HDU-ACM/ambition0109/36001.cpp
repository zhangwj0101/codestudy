////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-02 19:03:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3600
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:608KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
#define Lowbit(x) (x&(-x))

int num[305][305],N;
bool Index[90005];

void Modify(int Pos){
	for(int i=Pos;i<=N;i+=Lowbit(i)){
		Index[i]^=1;
	}
}

int Query(int t)
{
	int result=0;
	for(int i=t;i>0;i-=Lowbit(i)){
		result^=Index[i];
	}
	return result;
}

int main()
{
	int n;
	while(scanf("%d",&n),n){
		memset(num,0,sizeof(num));
		int RS=0;N=n*n-1;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&num[i][j]);
				if(!num[i][j]) continue;
				RS^=Query(n*n-num[i][j]);
				Modify(n*n-num[i][j]);
			}
		}
		if(!(n&1)){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(!num[i][j]) continue;
					int tmp=(num[i][j]-1)/n;
					RS^=(tmp-i);
				}
			}
		}
		if(RS&1){
			puts("NO");
		}else{
			puts("YES");
		}
	}
}