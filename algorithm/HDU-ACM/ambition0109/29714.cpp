////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-21 13:04:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2971
////Problem Title: 
////Run result: Accept
////Run time:3453MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
#define Type __int64
#define MaxN 5

__int64 a,Mod;
int Size=4;
struct Matrix{
	Type Mat[MaxN][MaxN];
	Matrix(){
		memset(Mat,0,sizeof(Mat));
	}
	void Init(){
		memset(Mat,0,sizeof(Mat));
		Mat[1][1]=Mat[4][2]=1;
		Mat[1][2]=Mat[2][2]=(4*a*a)%Mod;
		Mat[1][3]=Mat[2][3]=-(4*a)%Mod;
		Mat[1][4]=Mat[2][4]=1;
		Mat[3][2]=(2*a)%Mod;
		Mat[3][3]=-1;
	}
	void Unit(){
		for(int i=1;i<=Size;i++){
			for(int j=1;j<=Size;j++){
				Mat[i][j]=(i==j);
			}
		}
	}
};

//�������
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
//�����������
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
	int t;
	int n;
	scanf("%d",&t);
	while(t--){
		scanf("%I64d %d %I64d",&a,&n,&Mod);
		if(a==1){
			printf("%d\n",n%int(Mod));
			continue;
		}
		M.Init();
		M=MPow(M,n-2);
		__int64 Ans=(M.Mat[1][1]*((a*a+1)%Mod))%Mod;
		Ans=(Ans+M.Mat[1][2]*((a*a)%Mod))%Mod;
		Ans=(Ans+M.Mat[1][3]*a)%Mod;
		Ans=(Ans+M.Mat[1][4])%Mod;
		if(Ans<0) Ans+=Mod;
		printf("%I64d\n",Ans);
	}
}