////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-29 17:08:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3664
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:8156KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

long long map[1010][1010];
int main()
{
	memset(map,0,sizeof(map));
	map[0][0]=1;
	for(int i=0;i<1000;i++){
		map[i][0]=1;
		for(int j=1;j<=i;j++){
			long long t1=map[i][j-1]*(i-j+1);
			long long t2=map[i][j]*(j+1);
			map[i+1][j]=t1+t2;
			if(map[i+1][j]>1000000007) map[i+1][j]%=1000000007;
		}
	}
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		printf("%lld\n",map[n][m]);
	}
}
