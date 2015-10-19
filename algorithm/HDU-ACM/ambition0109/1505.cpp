////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-16 18:28:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1505
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:4140KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int num[1001][1001],Left[1001],Right[1001];
void main()
{
	int t,n,m;scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				char T;
				cin>>T;
				if(T=='F') num[i][j]=num[i-1][j]+1;
				else num[i][j]=0;
			}
		int max=0;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=m;j++){
				Left[j]=Right[j]=j;
				while(Left[j]>0&&num[i][Left[j]-1]>=num[i][j])
					Left[j]=Left[Left[j]-1];
			}
			for(int j=m;j>0;j--){
				while(Right[j]<n&&num[i][Right[j]+1]>=num[i][j])
					Right[j]=Right[Right[j]+1];
				int temp=num[i][j]*(Right[j]-Left[j]+1);
				if(temp>max)
					max=temp;
			}
		}
		printf("%d\n",max*3);
	}
}