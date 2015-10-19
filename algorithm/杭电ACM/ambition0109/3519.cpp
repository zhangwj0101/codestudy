////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-20 13:59:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3519
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:188KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
#define Type int
#define MaxN 4

int Size,Mod;
struct Matrix{
	Type Mat[MaxN][MaxN];
	Matrix(){
		memset(Mat,0,sizeof(Mat));
	}
	void Unit(){
		for(int i=1;i<MaxN;i++){
			for(int j=1;j<MaxN;j++){
				Mat[i][j]=(i==j);
			}
		}
	}
	void Init(){
		memset(Mat,0,sizeof(Mat));
		Mat[1][1]=Mat[1][2]=Mat[1][3]=Mat[2][1]=1;
		Mat[3][3]=2;
	}
};

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

Matrix MPow(Matrix Mat,int Pow){
	Matrix Ans,Tmp(Mat);
	for(Ans.Unit();Pow;Pow>>=1){
		if(Pow&1) Ans=MMul(Ans,Tmp);
		Tmp=MMul(Tmp,Tmp);
	}
	return Ans;
}

Matrix Mat;
int main()
{
	int n;
	Size=3;Mod=10007;
	while(scanf("%d",&n)!=EOF){
		if(n==1){
			puts("0");
			continue;
		}
		Mat.Init();
		Mat=MPow(Mat,n-2);
		printf("%d\n",(Mat.Mat[1][3]*2)%10007);
	}
}