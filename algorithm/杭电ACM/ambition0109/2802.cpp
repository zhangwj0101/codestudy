////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-29 19:58:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2802
////Problem Title: 
////Run result: Accept
////Run time:671MS
////Run memory:196KB
//////////////////System Comment End//////////////////
/*
 * 2802.cpp
 *
 *  Created on: 2010-9-29
 *      Author: administrator
 */

#include<cstdio>
#include<cstring>
using namespace std;
#define Type int
#define MaxN 5

int Size,Mod;
struct Matrix{
	Type Mat[MaxN][MaxN];
	Matrix(){
		memset(Mat,0,sizeof(Mat));
	}
	void Init(){
		Mat[1][1]=Mat[1][4]=Mat[2][2]=1;
		Mat[1][2]=3;
		Mat[1][3]=-3;
		Mat[2][1]=Mat[3][1]=Mat[3][2]=0;
		Mat[4][1]=Mat[4][2]=Mat[4][3]=0;
		Mat[2][3]=Mat[2][4]=4;
		Mat[3][3]=Mat[4][4]=1;
		Mat[3][4]=2;
	}
	void Unit(){
		for(int i=0;i<=Size;i++){
			for(int j=1;j<=Size;j++){
				Mat[i][j]=(i==j);
			}
		}
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
				if(Ans.Mat[x][y]>=Mod||Ans.Mat[x][y]<=-Mod){
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
	Size=4;Mod=2009;
	int n;
	while(scanf("%d",&n),n){
		Mat.Init();
		Mat=MPow(Mat,((n-1)>>1));
		if(n&1){
			int Ans=(Mat.Mat[1][1]+Mat.Mat[1][2]*9+Mat.Mat[1][3]*3+Mat.Mat[1][4])%Mod;
			if(Ans<0) Ans+=Mod;
			printf("%d\n",Ans);
		}else{
			int Ans=(Mat.Mat[1][1]*7+Mat.Mat[1][2]*16+Mat.Mat[1][3]*4+Mat.Mat[1][4])%Mod;
			if(Ans<0) Ans+=Mod;
			printf("%d\n",Ans);
		}
	}
}