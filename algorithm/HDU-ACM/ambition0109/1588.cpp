////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-18 18:56:37
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1588
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
#define Type __int64
#define MaxN 3

struct Matrix{
	Type Mat[MaxN][MaxN];
	Matrix(){
		memset(Mat,0,sizeof(Mat));
	}
};

Matrix MAdd(Matrix A,Matrix B,int Size,int Mod){
	Matrix Ans;
	for(int i=1;i<=Size;i++){
		for(int j=1;j<=Size;j++){
			Ans.Mat[i][j]=A.Mat[i][j]+B.Mat[i][j];
			if(Ans.Mat[i][j]>=Mod) Ans.Mat[i][j]%=Mod;
		}
	}
	return Ans;
}

Matrix MMul(Matrix A,Matrix B,int Size,int Mod){
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

void MPow(Matrix& Mat,int Pow,int Size,int Mod){
	Matrix Tmp(Mat);
	for(Pow-=1;Pow;Pow>>=1){
		if(Pow&1) Mat=MMul(Mat,Tmp,Size,Mod);
		Tmp=MMul(Tmp,Tmp,Size,Mod);
	}
}

Matrix MSum(Matrix Mat,int Exp,int Size,int Mod){
	Matrix Ans(Mat);
	if(Exp==1) return Ans;
	if(Exp&1){
		Matrix Tmp(Mat);
		MPow(Tmp,Exp,Size,Mod);
		return MAdd(MSum(Ans,Exp-1,Size,Mod),Tmp,Size,Mod);
	}else{
		Matrix Tmp1,Tmp2;
		Tmp1=MSum(Mat,Exp>>1,Size,Mod);
		MPow(Ans,Exp>>1,Size,Mod);
		Tmp2=MMul(Tmp1,Ans,Size,Mod);
		return MAdd(Tmp1,Tmp2,Size,Mod);
	}
}

Matrix Mat;
int main(){
	int k,b,n,m;
	while(scanf("%d%d%d%d",&k,&b,&n,&m)!=EOF){
		Mat.Mat[1][1]=1;
		Mat.Mat[1][2]=1;
		Mat.Mat[2][1]=1;
		Mat.Mat[2][2]=0;
		Matrix tM(Mat);
		MPow(Mat,k,2,m);
		Mat=MSum(Mat,n-1,2,m);
		if(b){
			MPow(tM,b,2,m);
			Mat=MMul(Mat,tM,2,m);
			Mat=MAdd(Mat,tM,2,m);
		}
		printf("%I64d\n",Mat.Mat[2][1]);
	}
}