////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-18 17:23:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2276
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:356KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<memory>
using namespace std;
const int Max_Size=101;

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


void MatrixMul(int MatA[][Max_Size],int MatB[],int AnsM[],int n,int mod)
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

int Fn[Max_Size];
int Mat[Max_Size][Max_Size];
int Ans[Max_Size][Max_Size];
void main()
{
	int n;string str;
	while(cin>>n)
	{
		cin>>str;
		int len=(int)str.length();
		for(int i=0;i<len;i++)
			if(str[i]=='1') Fn[i+1]=1;
			else Fn[i+1]=0;
		for(int i=1;i<=len;i++){
			memset(Mat[i],0,sizeof(int)*(len+1));
			memset(Ans[i],0,sizeof(int)*(len+1));
			if(i==1){
				Mat[1][1]=Mat[1][len]=1;
				Ans[1][1]=Ans[1][len]=1;
			}
			else{
				Mat[i][i]=Mat[i][i-1]=1;
				Ans[i][i]=Ans[i][i-1]=1;
			}
		}
		for(n-=1;n;n>>=1){
			if(n&1) MatrixMul(Ans,Mat,Ans,len,2);
			MatrixMul(Mat,Mat,Mat,len,2);
		}
		MatrixMul(Ans,Fn,Fn,len,2);
		for(int i=1;i<=len;i++)
			cout<<Fn[i];
		cout<<endl;
	}
}