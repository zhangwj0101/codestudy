////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-19 15:09:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1575
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<memory>
using namespace std;
const int Max_Size=11;

void MatrixMul(int MatA[][Max_Size],int MatB[][Max_Size],int AnsM[][Max_Size],int n,int Mod)
{
	int TempM[Max_Size][Max_Size];
	for(int i=1;i<=n;i++)
		memset(TempM[i],0,sizeof(int)*(n+1));
	for(int i=1;i<=n;i++){
		for(int x=1;x<=n;x++){
			if(!MatB[x][i]) continue;
			for(int y=1;y<=n;y++){
				if(!MatA[i][y]) continue;
				TempM[x][y]+=MatA[i][y]*MatB[x][i];
				if(TempM[x][y]>=Mod||TempM[x][y]<=-Mod)
					TempM[x][y]%=Mod;
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			AnsM[i][j]=TempM[i][j];
}

void MatrixPow(int Mat[][Max_Size],int n,int Pow,int Mod)
{
	int Temp[Max_Size][Max_Size];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			Temp[i][j]=Mat[i][j];
	for(Pow-=1;Pow;Pow>>=1){
		if(Pow&1) MatrixMul(Mat,Temp,Mat,n,Mod);
		MatrixMul(Temp,Temp,Temp,n,Mod);
	}
}
/*
void MatrixMul(int MatA[][Max_Size],int MatB[],int AnsM[],int n,int Mod)
{
	int TempM[Max_Size];
	memset(TempM,0,sizeof(int)*(n+1));
	for(int i=1;i<=n;i++){
		if(!MatB[i]) continue;
		for(int j=1;j<=n;j++){
			if(!MatA[j][i]) continue;
			TempM[i]+=MatA[j][i]*MatB[i];
			if(TempM[i]>=Mod||TempM[i]<=-Mod)
				TempM[i]%=Mod;
		}
	}
	for(int i=1;i<=n;i++)
		AnsM[i]=TempM[i];
}
*/
int Mat[Max_Size][Max_Size];

int main()
{
    int t,n,k;cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&Mat[i][j]);
		MatrixPow(Mat,n,k,9973);
        int tr=0;
        for(int i=1;i<=n;i++){
            tr+=Mat[i][i];
            if(tr>9973) tr%=9973;
        }
        cout<<tr<<endl;
    }
}