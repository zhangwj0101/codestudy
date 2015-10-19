////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-19 21:29:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3117
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
/*
 * MatrixMul.cpp
 *
 *  Created on: 2010-9-17
 *      Author: Administrator
 */

#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define Type int
#define MaxN 3

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
	void Clear(){
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
	Size=2;
	while(scanf("%d",&n)!=EOF){
		Mat.Mat[1][1]=1;
		Mat.Mat[1][2]=1;
		Mat.Mat[2][1]=1;
		Mat.Mat[2][2]=0;
		if(n<40){
			Mod=100000000;
			Mat=MPow(Mat,n);
			printf("%d\n",Mat.Mat[2][1]);
		}else{
			double ffour=-0.5*(log10(5.0))+n*log10((sqrt(5.0)+1.0)/2.0);
			ffour=pow(10.0,double(ffour-(int)ffour));
			while(ffour<1000) ffour*=10;
			printf("%d...",int(ffour));
			Mod=10000;
			Mat=MPow(Mat,n);
			printf("%04d\n",Mat.Mat[2][1]);
		}
	}
}