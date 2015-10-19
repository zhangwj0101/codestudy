////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-13 09:05:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1042
////Problem Title: 
////Run result: Accept
////Run time:578MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

int main()
{
	int n;
	__int64 a[5000];
	while(scanf("%d",&n)!=EOF){
		int m=1; a[0]=1;
		for(int x=2;x<=n;x++){
			for(int i=0;i<m;i++)
				a[i]=a[i]*x;
			for(int i=0;i<m;i++){
				if(a[i]>1000000000){
					if(i<m-1)
						a[i+1]+=a[i]/1000000000;
					else{
						m++;
						a[i+1]=a[i]/1000000000;
					}
					a[i]%=1000000000;
				}
			}
		}
		printf("%d",a[m-1]);
		for(int i=m-2;i>=0;i--)
			printf("%09I64d",a[i]);
		printf("\n");
	}
	return 0;
}
