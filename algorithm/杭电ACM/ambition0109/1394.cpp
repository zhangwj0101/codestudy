////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-03 09:17:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1394
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
#define Lowbit(x) (x&(-x))

int Index[5005],N;
int num[5005];
void Modify(int Pos,int Val)
{
	for(int i=Pos;i<=N;i+=Lowbit(i)){
		Index[i]+=Val;
	}
}
int Query(int Pos){
	int result=0;
	for(int i=Pos;i>0;i-=Lowbit(i)){
		result+=Index[i];
	}
	return result;
}

int main()
{
	while(scanf("%d",&N)!=EOF){
		memset(Index,0,sizeof(Index));
		int RS=0;
		for(int i=0;i<N;i++){
			scanf("%d",&num[i]);
			RS+=Query(N-num[i]);
			Modify(N-num[i],1);
		}
		int Min=RS;
		for(int i=0;i<N-1;i++){
			RS-=num[i];
			(--RS)+=N-num[i];
			if(RS<Min) Min=RS;
		}
		printf("%d\n",Min);
	}
}