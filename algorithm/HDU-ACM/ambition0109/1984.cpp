////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-08 13:50:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1984
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int n,t,cas=0;char str[100];
	scanf("%d",&t);
	while(t--){
		scanf("%d %s",&n,str);
		int len=strlen(str);
		printf("%d ",++cas);
		for(int i=0;i<len;i++){
			if(i==n-1) continue;
			printf("%c",str[i]);
		}
		puts("");
	}
}