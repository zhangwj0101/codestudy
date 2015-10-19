////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-21 09:18:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3306
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:188KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
#define Type int
#define MaxN 5

int x,y;
int Size=4,Mod=10007;
struct Matrix{
	Type Mat[MaxN][MaxN];
	Matrix(){
		memset(Mat,0,sizeof(Mat));
	}
	void Init(){
		memset(Mat,0,sizeof(Mat));
		Mat[1][1]=Mat[4][2]=1;
		Mat[1][2]=Mat[2][2]=(x*x)%Mod;
		Mat[1][3]=Mat[2][3]=(2*x*y)%Mod;
		Mat[1][4]=Mat[2][4]=(y*y)%Mod;
		Mat[3][2]=x;
		Mat[3][3]=y;
	}
	void Unit(){
		for(int i=1;i<=Size;i++){
			for(int j=1;j<=Size;j++){
				Mat[i][j]=(i==j);
			}
		}
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
	Matrix Ans,Tmp(Mat);
	for(Ans.Unit();Pow;Pow>>=1){
		if(Pow&1) Ans=MMul(Ans,Tmp);
		Tmp=MMul(Tmp,Tmp);
	}
	return Ans;
}

Matrix M;
int main()
{
	int n;
	while(scanf("%d%d%d",&n,&x,&y)!=EOF){
		if(x>=Mod) x%=Mod;
		if(y>=Mod) y%=Mod;
		M.Init();
		M=MPow(M,n-1);
		int Ans=(M.Mat[1][1]*2+M.Mat[1][2]+M.Mat[1][3]+M.Mat[1][4])%Mod;
		printf("%d\n",Ans);
	}
}

