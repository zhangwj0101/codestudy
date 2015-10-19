////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-18 21:37:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2254
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:608KB
//////////////////System Comment End//////////////////
#include<map>
#include<cstdio>
#include<cstring>
using namespace std;
#define Type int
#define MaxN 31

int Size,Mod=2008;
struct Matrix{
	Type Mat[MaxN][MaxN];
	Matrix(){
		memset(Mat,0,sizeof(Mat));
	}
	void init(){
		memset(Mat,0,sizeof(Mat));
	}
};

//矩阵求和
Matrix MAdd(Matrix A,Matrix B){
	Matrix Ans;
	for(int i=1;i<=Size;i++){
		for(int j=1;j<=Size;j++){
			Ans.Mat[i][j]=A.Mat[i][j]+B.Mat[i][j];
			if(Ans.Mat[i][j]>=Mod){
				Ans.Mat[i][j]%=Mod;
			}
		}
	}
	return Ans;
}
//矩阵求积
Matrix MMul(Matrix A,Matrix B){
	Matrix Ans;
	for(int i=1;i<=Size;i++){
		for(int x=1;x<=Size;x++){
			if(!B.Mat[x][i]) continue;
			for(int y=1;y<=Size;y++){
				if(!A.Mat[i][y]) continue;
				Ans.Mat[x][y]+=A.Mat[i][y]*B.Mat[x][i];
				if(Ans.Mat[x][y]>=Mod){
					Ans.Mat[x][y]%=Mod;
				}
			}
		}
	}
	return Ans;
}
//矩阵二分求幂
Matrix MPow(Matrix Mat,int Pow){
	Matrix Ans(Mat),Tmp(Mat);
	for(Pow-=1;Pow;Pow>>=1){
		if(Pow&1) Ans=MMul(Ans,Tmp);
		Tmp=MMul(Tmp,Tmp);
	}
	return Ans;
}
//等比矩阵二分求和
Matrix MSum(Matrix Mat,int Exp){
	if(Exp==1) return Mat;
	if(Exp&1){
		return MAdd(MSum(Mat,Exp-1),MPow(Mat,Exp));
	}else{
		Matrix Tmp1,Tmp2;
		Tmp1=MSum(Mat,Exp>>1);
		Tmp2=MMul(Tmp1,MPow(Mat,Exp>>1));
		return MAdd(Tmp1,Tmp2);
	}
}

Matrix Map;
map<__int64,int> City;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		int t=1;
		Map.init();
		City.clear();
		for(int i=0;i<n;i++){
			__int64 c1,c2;
			scanf("%I64d%I64d",&c1,&c2);
			if(!City[c1]) City[c1]=t++;
			if(!City[c2]) City[c2]=t++;
			Map.Mat[City[c1]][City[c2]]++;
		}
		int m;Size=t-1;
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			__int64 c1,c2;
			int t1,t2;
			scanf("%I64d%I64d%d%d",&c1,&c2,&t1,&t2);
			int cc1=City[c1],cc2=City[c2];
			if(t1>t2) t1^=t2^=t1^=t2;
			if(cc1==0||cc2==0||(t1==0&&t2==0)){
				puts("0");
				continue;
			}
			if(t1<=1){
				Matrix Tmp=MSum(Map,t2);
				printf("%d\n",Tmp.Mat[cc1][cc2]);
			}else{
				Matrix Tmp1=MSum(Map,t1-1);
				Matrix Tmp2=MSum(Map,t2);
				int Ans=(Tmp2.Mat[cc1][cc2]-Tmp1.Mat[cc1][cc2])%Mod;
				if(Ans<0) Ans+=Mod;
				printf("%d\n",Ans);
			}
		}
	}
}