////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-18 15:09:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1757
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
const int Max_Size=11;

void MatrixMul(int MatA[][Max_Size],int MatB[][Max_Size],int AnsM[][Max_Size],int n,int mod)
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
				if(TempM[x][y]>=mod||TempM[x][y]<=-mod)
					TempM[x][y]%=mod;
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			AnsM[i][j]=TempM[i][j];
}
void _MatrixMul(int MatA[][Max_Size],int MatB[],int AnsM[],int n,int mod)
{
	int TempM[Max_Size];
	memset(TempM,0,sizeof(int)*(n+1));
	for(int i=1;i<=n;i++){
		if(!MatB[i]) continue;
		for(int j=1;j<=n;j++){
			if(!MatA[j][i]) continue;
			TempM[j]+=MatA[j][i]*MatB[i];
			if(TempM[j]>=mod||TempM[j]<=-mod)
				TempM[j]%=mod;
		}
	}
	for(int i=1;i<=n;i++)
		AnsM[i]=TempM[i];
}

int Mat[Max_Size][Max_Size],Fn[Max_Size];
int Ans[Max_Size][Max_Size];
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		for(int i=1;i<=10;i++){
			memset(Ans[i],0,sizeof(Ans[i]));
			memset(Mat[i],0,sizeof(Mat[i]));
			Mat[i][i-1]=1;
			Ans[i][i]=1;
			cin>>Mat[1][i];
			Fn[i]=10-i;
		}
		for(n-=9;n;n>>=1){
			if(n&1) MatrixMul(Ans,Mat,Ans,10,m);
			MatrixMul(Mat,Mat,Mat,10,m);
		}
		_MatrixMul(Ans,Fn,Fn,10,m);
		cout<<Fn[1]<<endl;
	}
}