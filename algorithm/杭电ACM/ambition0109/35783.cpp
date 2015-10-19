////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-09 20:52:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3578
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1008KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

inline int Abs(const int& num){
	int temp=(num>>31);
	return (num+temp)^temp;
}
inline int Max(const int& a,const int& b){
	int dif=b-a;
	return b-(dif&(dif>>31));
}

inline void scan_ud(int &num)
{
	char in;
	in=getchar();
	while(in<'0'||in>'9'){
		in=getchar();
	}
	num=in-'0';
	in=getchar();
	while(in>='0'&&in<='9'){
		num*=10;num+=in-'0';
		in=getchar();
	}
}

int dp[105][2010];
int main()
{
	int t,cas=0;
	scanf("%d",&t);
	while(t--){
		int n,wi;
		bool flag=true;
		scanf("%d",&n);
		memset(dp,-1,sizeof(dp));
		dp[0][0]=0;
		for(int i=1;i<=n;i++){
			scan_ud(wi);
			if(wi==0) flag=false;
			for(int j=0;j<=2000;j++){
				if(dp[i-1][j]==-1) continue;
				dp[i][Abs(j-wi)]=Max(dp[i][Abs(j-wi)],dp[i-1][j]+wi);
				dp[i][Abs(j+wi)]=Max(dp[i][Abs(j+wi)],dp[i-1][j]+wi);
				dp[i][j]=Max(dp[i][j],dp[i-1][j]);
			}
		}
		int Ans=-1;
		for(int i=1;i<=n;i++){
			Ans=Max(Ans,dp[i][0]);
		}
		printf("Case %d: ",++cas);
		if(Ans==0&&flag) puts("-1");
		else printf("%d\n",Ans/2);
	}
}