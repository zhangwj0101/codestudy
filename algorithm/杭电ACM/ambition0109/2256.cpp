////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-17 18:11:05
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2256
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:188KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
const int Max_Size=3;

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
	if(Pow==0){
		Mat[1][1]=Mat[2][2]=1;
		Mat[1][2]=Mat[2][1]=0;
		return;
	}
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

int Mat[3][3];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		Mat[1][1]=5;
		Mat[1][2]=12;
		Mat[2][1]=2;
		Mat[2][2]=5;
		MatrixPow(Mat,2,n-1,1024);
		int Ans=(Mat[1][1]*5+Mat[1][2]*2)*2-1;
		if(Ans>=1024) Ans%=1024;
		printf("%d\n",Ans);
	}
}