////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-25 14:45:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2688
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:11972KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
#define Lowbit(x) (x&(-x))

int Index[10010];
int num[3000010];

inline bool scan_ud(int &num)
{
	char in;
	in=getchar();
	while(in<'0'||in>'9') in=getchar();
	num=in-'0';
	while(in=getchar(),in>='0'&&in<='9'){
		num*=10,num+=in-'0';
	}
	return true;
}

inline int Sum(int t)
{
	__int64 sum=0;
	while(t>0){
		sum+=Index[t];
		t-=Lowbit(t);
	}
	return sum;
}

inline void Add(int Pos)
{
	while(Pos<=10000){
		Index[Pos]++;
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
			scan_ud(num[i]);
			Add(num[i]);
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
				scan_ud(s);
				scan_ud(e);
				int mem=num[s];
				for(int i=s;i<e;i++){
					num[i]=num[i+1];
					if(num[i]<mem) SS++;
					else if(num[i]>mem) SS--;
				}
				num[e]=mem;
			}
		}
	}
}