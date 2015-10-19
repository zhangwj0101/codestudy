////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-13 09:15:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1042
////Problem Title: 
////Run result: Accept
////Run time:406MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

int a[100000];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		int m=1; a[0]=1;
		for(int i=2;i<=n;i++){
			for(int j=0;j<m;j++)
				a[j]=a[j]*i;
			for(int j=0;j<m;j++){
				if(a[j]>100000){
					if(j<m-1)
						a[j+1]+=a[j]/100000;
					else{
						m++;
						a[j+1]=a[j]/100000;
					}
					a[j]%=100000;
				}
			}
		}
		printf("%d",a[m-1]);
		for(int i=m-2;i>=0;i--)
			printf("%05d",a[i]);
		printf("\n");
	}
	return 0;
}
