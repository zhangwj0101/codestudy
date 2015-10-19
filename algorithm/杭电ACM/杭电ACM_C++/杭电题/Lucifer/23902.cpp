////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-10-04 13:29:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2390
////Problem Title: 
////Run result: Accept
////Run time:1796MS
////Run memory:272KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
using namespace std;
struct data{
	int ss;
	int ee;
}a[50001];
inline bool cmp(data a,data b)
{
	return a.ee<=b.ee;
}
int main(){
	int n,i,j,k,m,sum,d,s,e;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&m);
		for(j=0;j<m;j++)
		{
			scanf("%d %d %d",&d,&s,&e);
			d*=10000;
			a[j].ss=s+d;
			a[j].ee=e+d;
		}
		sort(a,a+m,cmp);
		sum=1;
		k=0;
		for(j=1;j<m;j++)
			if(a[j].ss>=a[k].ee)
				sum++,k=j;
		printf("Scenario #%d:\n%d\n\n",i,sum);
    }
	return 0;
}