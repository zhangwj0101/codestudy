////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-29 14:50:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3015
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:1896KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;
#define Lowbit(x) (x&(-x))

struct Tree{
	int F,S;
};

inline bool scan_ud(int &num)
{
	char in;
	in=getchar();
	if(in==EOF) return false;
	while(in<'0'||in>'9') in=getchar();
	num=in-'0';
	while(in=getchar(),in>='0'&&in<='9'){
		num*=10,num+=in-'0';
	}
	return true;
}


bool cmp(const Tree &a,const Tree &b){
	return a.S<b.S;
}

int IndexA[100010],IndexB[100010],N;
void Modify(int Index[],int Pos,int Num)
{
	for(int i=Pos;i<=N;i+=Lowbit(i)){
		Index[i]+=Num;
	}
}

__int64 Sum(int Index[],int pos)
{
	__int64 result=0;
	for(int i=pos;i>0;i-=Lowbit(i)){
		result+=Index[i];
	}
	return result;
}

int Find(int Dis[],int t){
	int top=1,bot=N;
	int mid=(top+bot)/2;
	int ans=mid;
	while(top<=bot){
		if(Dis[mid]<t){
			top=mid+1;
		}else{
			bot=(ans=mid)-1;
		}
		mid=(top+bot)/2;
	}
	return ans;
}

Tree num[100010];
int tf[100010];
int FDis[100010],SDis[100010];
int main()
{
	while(scanf("%d",&N)!=EOF){
		memset(IndexA,0,sizeof(IndexA));
		memset(IndexB,0,sizeof(IndexB));
		for(int i=0;i<N;i++){
			scan_ud(num[i].F);
			scan_ud(num[i].S);
			tf[i]=num[i].F;
		}
		sort(num,num+N,cmp);
		sort(tf,tf+N);
		for(int i=0,tmp=1;i<N;i++){
			FDis[i+1]=tf[i];
			if(i&&tf[i]!=tf[i-1]){
				tmp=i+1;
			}
			Modify(IndexA,tmp,1);
			Modify(IndexB,tmp,tmp);
			SDis[i+1]=num[i].S;
		}
		__int64 SS=0;
		__int64 asum=Sum(IndexB,N);
		int acnt=int(Sum(IndexA,N));
		for(int i=0;i<N-1;i++){
			int spos=Find(SDis,num[i].S);
			int fpos=Find(FDis,num[i].F);
			int cs=int(Sum(IndexA,fpos-1));
			int cb=int(Sum(IndexA,fpos));
			__int64 fs=Sum(IndexB,fpos-1);
			__int64 fb=Sum(IndexB,fpos);
			SS+=spos*(cs*fpos-fs);
			SS+=spos*((asum-fb)-(acnt-cb)*fpos);
			Modify(IndexA,fpos,-1);
			Modify(IndexB,fpos,-fpos);
			asum-=fpos;
			acnt-=1;
		}
		printf("%I64d\n",SS);
	}
}