////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-25 10:37:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3569
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

int main()
{
	int t,c=0;
	scanf("%d",&t);
	while(t--){
		int n,m,k,v,sum=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0;i<n;i++){
			scanf("%d",&v);
			sum+=v;
		}
		printf("Case %d: %.5lf\n",++c,(double)sum/(double)n*(double)m);
	}
}