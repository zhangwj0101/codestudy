////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-29 17:12:33
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3661
////Problem Title: 
////Run result: Accept
////Run time:328MS
////Run memory:172KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<algorithm>
using namespace std;

int A[1005],B[1005];
int main()
{
	int n,t;
	while(scanf("%d%d",&n,&t)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&A[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%d",&B[i]);
		}
		sort(A,A+n);
		sort(B,B+n);
		int Sum=0;
		for(int i=0;i<n;i++){
			if(A[i]+B[n-i-1]>t){
				Sum+=A[i]+B[n-i-1]-t;
			}
		}
		printf("%d\n",Sum);
	}
}