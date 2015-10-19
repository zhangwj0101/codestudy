////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-19 09:05:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2604
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:188KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
#define Type int
#define MaxN 3

int Size=2,Mod;
struct Matrix{
	Type Mat[MaxN][MaxN];
	Matrix(){
		memset(Mat,0,sizeof(Mat));
	}
};

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

Matrix Mat;
int main()
{
	int n;
	while(scanf("%d%d",&n,&Mod)!=EOF){
		Mat.Mat[1][1]=1;
		Mat.Mat[1][2]=1;
		Mat.Mat[2][1]=1;
		Mat.Mat[2][2]=0;
		Mat=MPow(Mat,(n+1)>>1);
		int M1=Mat.Mat[1][1]+Mat.Mat[1][2];
		int M2=Mat.Mat[2][1]+Mat.Mat[2][2];
		if(n&1){
			printf("%d\n",(M1*M2)%Mod);
		}else{
			printf("%d\n",(M1*M1)%Mod);
		}
	}
}