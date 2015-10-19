////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-29 19:32:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2690
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:188KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

int num[10000];
void main()
{
	int t,n,max;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);max=0;
		for(int i=0;i<n;i++){
			scanf("%d",&num[i]);
			if(max<num[i]) max=num[i];
		}
		if(n==1&&num[0]==0) printf("Impossible!\n");
		else {
			int cm=0;
			for(int i=0;i<n;i++)
				if(num[i]==max) cm++;
			if(cm==n&&cm==max+1) printf("%d\n",n);
			else if(max==n-cm){
				printf("%d\n",max);
			}else printf("Impossible!\n");
		}
	}
}