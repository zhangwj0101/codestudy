////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-05 21:04:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2157
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:232KB
//////////////////System Comment End//////////////////
/*
 * 2157.cpp
 *
 *  Created on: 2010-10-5
 *      Author: administrator
 */

#include<cstdio>
#include<cstring>
using namespace std;
#define Type int
#define MAXN 25

int Size,Mod=1000;
struct Matrix{
	Type Mat[MAXN][MAXN];
	Matrix(){
		memset(Mat,0,sizeof(Mat));
	}
	void Clear(){
		memset(Mat,0,sizeof(Mat));
	}
	void Unit(){
		for(int i=1;i<=Size;i++){
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
			if(!A.Mat[x][i]) continue;
			for(int y=1;y<=Size;y++){
				if(!B.Mat[i][y]) continue;
				Ans.Mat[x][y]+=A.Mat[x][i]*B.Mat[i][y];
				if(Ans.Mat[x][y]>=Mod) Ans.Mat[x][y]%=Mod;
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

Matrix Mat,Ans;
int main(){
	int n;
	while(scanf("%d%d",&Size,&n),Size||n){
		Mat.Clear();
		for(int i=0;i<n;i++){
			int c1,c2;
			scanf("%d%d",&c1,&c2);
			Mat.Mat[c1+1][c2+1]=1;
		}
		int m;
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			int c1,c2,k;
			scanf("%d%d%d",&c1,&c2,&k);
			Ans=MPow(Mat,k);
			printf("%d\n",Ans.Mat[c1+1][c2+1]);
		}
	}
}




