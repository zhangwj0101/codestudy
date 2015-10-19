////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-25 14:29:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2688
////Problem Title: 
////Run result: Accept
////Run time:671MS
////Run memory:12048KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
#define Lowbit(x) (x&(x^(x-1)))

__int64 Index[10010];
int Hash[10010];
int num[3000010];

int Sumt(int t)
{
	int sum=0;
	while(t>0){
		sum+=Hash[t];
		t-=Lowbit(t);
	}
	return sum;
}

void Addt(int Pos,int N)
{
	while(Pos<=N){
		Hash[Pos]+=1;
		Pos+=Lowbit(Pos);
	}
}

__int64 Sum(int t)
{
	__int64 sum=0;
	while(t>0){
		sum+=Index[t];
		t-=Lowbit(t);
	}
	return sum;
}

void Add(int Pos,int Num,int N)
{
	while(Pos<=N){
		Index[Pos]+=Num;
		Pos+=Lowbit(Pos);
	}
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(Hash,0,sizeof(Hash));
		memset(Index,0,sizeof(Index));
		for(int i=0;i<n;i++){
			scanf("%d",num+i);
			Addt(num[i],10000);
			Add(num[i],Sumt(num[i]-1),10000);
		}
		__int64 SS=Sum(10000);
		int m;
		scanf("%d",&m);
		while(m--){
			char cmd[2];
			scanf("%s",cmd);
			if(cmd[0]=='Q'){
				printf("%I64d\n",SS);
			}else if(cmd[0]=='R'){
				int s,e;
				scanf("%d%d",&s,&e);
				int mem=num[s];
				for(int i=s;i<e;i++){
					num[i]=num[i+1];
					if(num[i]<mem){
						SS++;
					}else if(num[i]>mem){
						SS--;
					}
				}
				num[e]=mem;
			}
		}
	}
}