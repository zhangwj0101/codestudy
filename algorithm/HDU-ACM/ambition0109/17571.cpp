////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-16 21:25:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1757
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:156KB
//////////////////System Comment End//////////////////
/*
 * MatrixMul.cpp
 *
 *  Created on: 2010-9-16
 *      Author: ambition
 */

#include<cstdio>
#include<cstring>
using namespace std;
const int Max_Size=11;

void MatrixMul(int MatA[][Max_Size],int MatB[][Max_Size],int AnsM[][Max_Size],int Size,int Mod)
{
	int TempM[Max_Size][Max_Size];
	memset(TempM,0,sizeof(TempM));
	for(int i=1;i<=Size;i++){
		for(int x=1;x<=Size;x++){
			if(!MatB[x][i]) continue;
			for(int y=1;y<=Size;y++){
				if(!MatA[i][y]) continue;
				TempM[x][y]+=MatA[i][y]*MatB[x][i];
				if(TempM[x][y]>=Mod){
					TempM[x][y]%=Mod;
				}
			}
		}
	}
	for(int i=1;i<=Size;i++){
		for(int j=1;j<=Size;j++){
			AnsM[i][j]=TempM[i][j];
		}
	}
}

void MatrixPow(int Mat[][Max_Size],int Size,int Pow,int Mod)
{
	if(Pow==1) return;
	int Temp[Max_Size][Max_Size];
	for(int i=1;i<=Size;i++){
		for(int j=1;j<=Size;j++){
			Temp[i][j]=Mat[i][j];
		}
	}
	for(Pow-=1;Pow;Pow>>=1){
		if(Pow&1){
			MatrixMul(Mat,Temp,Mat,Size,Mod);
		}
		MatrixMul(Temp,Temp,Temp,Size,Mod);
	}
}

int Mat[Max_Size][Max_Size];
int Fn[Max_Size];
int main()
{
	int p,m;
	while(scanf("%d%d",&p,&m)!=EOF){
		memset(Mat,0,sizeof(Mat));
		for(int i=1;i<=10;i++){
			scanf("%d",&Mat[1][i]);
			if(i!=10) Mat[i+1][i]=1;
		}
		int Ans=0;
		if(p<10){
			Ans=p%m;
		}else{
			MatrixPow(Mat,10,p-9,m);
			Ans=0;
			for(int i=1;i<=10;i++){
				Ans+=(10-i)*Mat[1][i];
				if(Ans>m) Ans%=m;
			}
		}
		printf("%d\n",Ans);
	}
}


