////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-07 18:12:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3610
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
const int Max_Size=21;

void MatrixMul(__int64 MatA[][Max_Size],__int64 MatB[][Max_Size],__int64 AnsM[][Max_Size],int n,int Mod)
{
	__int64 TempM[Max_Size][Max_Size];
	memset(TempM,0,sizeof(TempM));
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

__int64 Temp[Max_Size][Max_Size];
__int64 Mat[Max_Size][Max_Size];
int main()
{
	int s,e,d,n;
	while(scanf("%d%d%d%d",&s,&e,&d,&n)!=EOF){
		memset(Mat,0,sizeof(Mat));
		memset(Temp,0,sizeof(Temp));
		for(int i=s;i<=e;i++){
			Mat[1][i]=1;
			Temp[1][i]=1;
		}
		for(int i=2;i<=d;i++){
			Mat[i][i-1]=1;
			Temp[i][i-1]=1;
		}
		for(n-=1;n;n>>=1){
			if(n&1) MatrixMul(Mat,Temp,Mat,d,1000000007);
			MatrixMul(Temp,Temp,Temp,d,1000000007);
		}
		__int64 Sum=0;
		for(int i=2;i<=d;i++){
			Sum+=Mat[i][1];
			if(Sum>=1000000007){
				Sum%=1000000007;
			}
		}
		printf("%I64d\n",Sum);
	}
}