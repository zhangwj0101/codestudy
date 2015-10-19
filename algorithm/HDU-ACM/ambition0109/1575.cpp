////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-18 14:16:32
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

void MatrixMul(int MatA[][Max_Size],int MatB[][Max_Size],int AnsM[][Max_Size],int n,int mod)
{
	int TempM[Max_Size][Max_Size];
	for(int i=1;i<=n;i++)
		memset(TempM[i],0,sizeof(int)*(n+1));
	for(int i=1;i<=n;i++){
		for(int x=1;x<=n;x++){
			if(!MatB[x][i]) continue;
			for(int y=1;y<=n;y++){
				if(!MatB[i][y]) continue;
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

int Mat[Max_Size][Max_Size];
int Ans[Max_Size][Max_Size];

int main()
{
	int t,n,k;cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&Mat[i][j]);
		for(int i=0;i<=n;i++){
			memset(Ans[i],0,sizeof(int)*(n+1));
			Ans[i][i]=1;
		}
		for(;k;k>>=1){
			if(k&1) MatrixMul(Ans,Mat,Ans,n,9973);
			MatrixMul(Mat,Mat,Mat,n,9973);
		}
		int tr=0;
		for(int i=1;i<=n;i++){
			tr+=Ans[i][i];
			if(tr>9973) tr%=9973;
		}
		cout<<tr<<endl;
	}
}