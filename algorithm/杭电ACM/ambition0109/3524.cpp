////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-21 16:51:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3524
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:188KB
//////////////////System Comment End//////////////////

//1 2
//2 2
//3 3
//4 4
//5 7
//6 12
//7 23
//8 44
//9 87
//10 172
//11 343
//12 684
//13 1367
//14 2732
//15 5463
//16 10924
//17 21847
//18 43692
//19 87383


#include<cstdio>
#include<cstring>
using namespace std;
#define Type int
#define MaxN 3

int x,y;
int Size=2,Mod=10007;
struct Matrix{
	Type Mat[MaxN][MaxN];
	Matrix(){
		memset(Mat,0,sizeof(Mat));
	}
	void Init(){
		Mat[1][1]=4;
		Mat[2][2]=1;
		Mat[1][2]=-1;
		Mat[2][1]=0;
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
				if(Ans.Mat[x][y]>=Mod||Ans.Mat[x][y]<=-Mod){
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
int main(){
	int t,cas=0;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		M.Init();
		M=MPow(M,(n-1)>>1);
		int Ans=M.Mat[1][1]*2;
		if(n&1) Ans+=M.Mat[1][2]*5;
		else Ans+=M.Mat[1][2]*4;
		Ans%=Mod;
		if(Ans<0) Ans+=Mod;
		printf("Case #%d: %d\n",++cas,Ans);
	}
}