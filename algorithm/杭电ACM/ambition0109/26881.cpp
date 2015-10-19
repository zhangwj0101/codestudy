////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-25 14:37:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2688
////Problem Title: 
////Run result: Accept
////Run time:578MS
////Run memory:11968KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
#define Lowbit(x) (x&(x^(x-1)))

int Index[10010];
int num[3000010];

int Sum(int t)
{
	__int64 sum=0;
	while(t>0){
		sum+=Index[t];
		t-=Lowbit(t);
	}
	return sum;
}

void Add(int Pos,int N)
{
	while(Pos<=N){
		Index[Pos]+=1;
		Pos+=Lowbit(Pos);
	}
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(Index,0,sizeof(Index));
		__int64 SS=0;
		for(int i=0;i<n;i++){
			scanf("%d",num+i);
			Add(num[i],10000);
			SS+=Sum(num[i]-1);
		}
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