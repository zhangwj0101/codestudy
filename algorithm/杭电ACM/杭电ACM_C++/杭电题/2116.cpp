////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-06 13:36:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2116
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
    __int64 a,b,max,min;
    int n,f;
    while(scanf("%d",&n)==1)
    {
        max=(__int64)1<<(n-1);
		min=-max;
		max-=1;
        scanf("%I64d%I64d",&a,&b);
		f=1;
		if(n==64)
		{
			if(a<0&&b<0)
			{
				if(a+b>=0)
				f=0;
			}
			else if(a>=0&&b>=0)
			{
				if(a+b<=0)
					f=0;
			}
		}
		else
		{
			if(a+b>max||a+b<min)
				f=0;
		}
        puts(f?"WaHaHa":"Yes");
    }
    return 0;
}