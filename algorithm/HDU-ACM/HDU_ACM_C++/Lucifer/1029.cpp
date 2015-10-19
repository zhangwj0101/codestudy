////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-18 16:54:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1029
////Problem Title: 
////Run result: Accept
////Run time:250MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int n,times,now,ca;
    int num[10000]={0};
    while(cin>>n)
    {
        times=(n+1)/2;
        for(ca=0;ca<n;ca++)
        {
            scanf("%d",&now);
            num[now]++;
            if(num[now]>=times)
            {
                printf("%d\n",now);
				ca++;
                break;
            }
        }
		for(;ca<n;ca++)
		{
			scanf("%*d");
		}
        memset(num, 0, sizeof(num));
    }
    return 0;
}


