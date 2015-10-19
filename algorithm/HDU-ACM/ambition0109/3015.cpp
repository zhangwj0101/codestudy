////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-29 14:47:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3015
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:1896KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;
#define Lowbit(x) (x&(-x))

struct Tree{
	int F,S;
};

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
			scanf("%d%d",&num[i].F,&num[i].S);
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


//树状数组
//题目描述：给定一个长为n的序列，元素有两个属性x,h(x代表坐标，h代表高度)
//求任意点(i,j)对的不调和值之和，不调和值有两部分组成F和S
//F是指i和j的x坐标(离散化后)差的绝对值F=abs(x[i]-x[j])
//S是指i和j的高度(离散化后)S=min(h[i],h[j]),这两者之积F*S就是(i,j)不可调和值
//分析：我们首先按高度从大到小排序，然后来统计这样我们解决了高度最小的问题 
//对于在i位置的元素，我们统计高度比h[i]大x比当x值小的x坐标和，同时统计高度比h[i]大，但坐标比x小的个数
//num=sum|x[i]-y[j]|*h[i](j<i) 设query1(x)查询比x小的个数，query2(x)查询比x小的x和 
//等价于a*x[i]-sum1+sum2-b*x[i]
//其中a表示比当前点x小的点数，b表示比当前点x大的点数，sum1表示比当前点x小的x和，sum2表示比当前点x大的x和
//可以表示成a=query1(x[i]-1),b=query1(n)-query1(x[i]),sum1=query2(x[i]-1),sum2=query2(n)-query2(x[i])
//得ans=query(x[i]-1)*x[i]-query2(x[i]-1)+query2(n)-query2(x[i])-(query1(n)-query1(x[i]))*x[i]
//然后ans*=h[i]，这就是当前项做为h最小的贡献量 
