////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-10-04 13:14:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2390
////Problem Title: 
////Run result: Accept
////Run time:2656MS
////Run memory:468KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
using namespace std;
struct data{
    int da;
    int ss;
    int ee;
}a[50001];
inline bool cmp(data a,data b)
{
	if(a.da!=b.da) return a.da<b.da;
	else  return a.ee<=b.ee;
}
int main(){
    int n,i,j,k,m,sum;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("Scenario #%d:\n",i);
        scanf("%d",&m);
        for(j=0;j<m;j++){
            scanf("%d %d %d",&a[j].da,&a[j].ss,&a[j].ee);
        }
        sort(a,a+m,cmp);
        sum=0;
        k=0;
        for(j=0;j<m;j++){
            if(j==0 || a[j].da!=a[j-1].da){
                sum++;
                k=j;
                continue;
            }
            if(a[j].ss>=a[k].ee){
                sum++;
                k=j;
            }
        }
        printf("%d\n\n",sum);
    }
    return 0;
}