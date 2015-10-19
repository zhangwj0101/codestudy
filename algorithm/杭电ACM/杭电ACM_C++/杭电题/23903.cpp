////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-10-04 13:36:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2390
////Problem Title: 
////Run result: Accept
////Run time:1765MS
////Run memory:272KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
using namespace std;
struct data{
	int ss;
	int ee;
}a[50000];
inline bool cmp(data a,data b)
{
	return a.ee<=b.ee;
}
int main(){
	int n,i,j,k,m,sum,d;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&m);
		for(j=0;j<m;j++)
		{
			scanf("%d %d %d",&d,&a[j].ss,&a[j].ee);
			d<<=12;
			a[j].ss+=d;
			a[j].ee+=d;
		}
		sort(a,a+m,cmp);
		sum=1;
		k=a[0].ee;
		for(j=1;j<m;j++)
			if(a[j].ss>=k)
				sum++,k=a[j].ee;
		printf("Scenario #%d:\n%d\n\n",i,sum);
    }
	return 0;
}