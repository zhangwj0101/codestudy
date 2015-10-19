////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-26 11:07:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3465
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:3524KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;
#define Lowbit(x) (x&(-x))

struct Insert{
	double r,l;
};
struct Line{
	double lx,ly;
	double rx,ry;
};

inline double Get(Line ll,double tx){
	return ll.ly-(ll.lx-tx)/(ll.rx-ll.lx)*(ll.ry-ll.ly);
}
int Index[50010],n;
double Dis[50010];

bool cmp(const Insert& a,const Insert& b)
{
	if(a.r==b.r) return a.l>b.l;
	else return a.r>b.r;
}
int Sum(int t)
{
	int sum=0;
	while(t>0){
		sum+=Index[t];
		t-=Lowbit(t);
	}
	return sum;
}

void Add(int Pos,int Num)
{
	while(Pos<=n){
		Index[Pos]+=Num;
		Pos+=Lowbit(Pos);
	}
}

int bfind(double num,int t){
	int top=t,bot=1;
	int mid=(top+bot)/2,ans=mid;
	while(bot<=top){
		if(Dis[mid]<=num){
			bot=(ans=mid)+1;
		}else{
			top=mid-1;
		}
		mid=(top+bot)/2;
	}
	return ans;
}

Line L[50010];
Insert P[50010];
double num[50010];
int main()
{
	while(scanf("%d",&n)!=EOF){
		double l,r;
		scanf("%lf%lf",&l,&r);
		int m=0,cnt=0,cnts=0;
		memset(Index,0,sizeof(Index));
		for(int i=0;i<n;i++){
			scanf("%lf%lf%lf%lf",&L[i].lx,&L[i].ly,&L[i].rx,&L[i].ry);
			if(L[i].lx==L[i].rx){
				if(L[i].lx<r&&L[i].lx>l){
					cnt++;
				}
					continue;
			}
			P[m].l=Get(L[i],l);
			P[m++].r=Get(L[i],r);
			cnts++;
		}
		sort(P,P+m,cmp);
		for(int i=0;i<m;i++){
			num[i]=P[i].l;
		}
		sort(num,num+m);
		int t=2;Dis[1]=num[0];
		for(int i=1;i<m;i++){
			if(num[i]!=num[i-1]){
				Dis[t++]=num[i];
			}
		}
		int SS=0;
		for(int i=0;i<m;i++){
			int Pos=bfind(P[i].l,t);
			Add(Pos,1);
			SS+=Sum(Pos-1);
		}
		printf("%d\n",SS+cnt*cnts);
	}
}