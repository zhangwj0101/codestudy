////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-09 21:12:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1850
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

int num[100];
int main()
{
	int m,xor,t,count;
	while(scanf("%d",&m),m){
		xor=0;
		for(int i=0;i<m;i++){
			scanf("%d",&num[i]);
			xor^=num[i];
		}
		count=0;
		if(xor){
			for(t=1;xor!=1;t<<=1)
				xor>>=1;
			for(int i=0;i<m;i++)
				if(num[i]&t)
					count++;
		}
		printf("%d\n",count);
	}
}