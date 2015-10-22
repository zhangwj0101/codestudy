////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-16 19:38:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2830
////Problem Title: 
////Run result: Accept
////Run time:578MS
////Run memory:4104KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstdlib>
using namespace std;

int compare(const void* a,const void* b){
	return *(int*)b-*(int*)a;
}
int num[1001][1001];
void main()
{
	int n,m;char ch;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=n;i++){
			getchar();
			for(int j=1;j<=m;j++){
				scanf("%c",&ch);
				if(ch=='1') num[i][j]=num[i-1][j]+1;
				else num[i][j]=0;
			}
		}
		int Max=0;
		for(int i=1;i<=n;i++){
			qsort(num[i]+1,m,sizeof(int),compare);
			for(int j=1;j<=m;j++){
				if(num[i][j]==0) break;
				int temp=num[i][j]*j;
				if(temp>Max) Max=temp;
			}
		}
		printf("%d\n",Max);
	}
}