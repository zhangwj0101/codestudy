////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-28 19:18:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1466
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<set>
using namespace std;

int Hash[21][200];
void main()
{
	Hash[0][0]=true;
	Hash[1][0]=true;
	for(int i=2;i<21;i++){
		for(int j=0;j<i;j++){
			for(int k=0;k<=j*(j-1)/2;k++){
				if(Hash[j][k])
					Hash[i][j*(i-j)+k]=true;
			}
		}
	}
	int n;
	while(cin>>n){
		printf("0");
		for(int i=1;i<=n*(n-1)/2;i++)
			if(Hash[n][i]) printf(" %d",i);
		printf("\n");
	}
}