////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-18 12:10:33
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1575
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:160KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
#define Type int
#define MaxN 11

struct Matrix{
	Type Mat[MaxN][MaxN];
	Matrix(){
		memset(Mat,0,sizeof(Mat));
	}
};

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

Matrix Mat;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&Mat.Mat[i][j]);
			}
		}
		MPow(Mat,m,n,9973);
		int Tr=0;
		for(int i=1;i<=n;i++){
			Tr+=Mat.Mat[i][i];
			if(Tr>=9973) Tr%=9973;
		}
		printf("%d\n",Tr);
	}
}