////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-13 11:25:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2095
////Problem Title: 
////Run result: Accept
////Run time:1078MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#pragma warning(disable:4786)
#include <set>
#include <map>
#include <cstdio>
using namespace std;

int main(void)
{
    int n, i, t;
    set <int> s;
    set <int>::iterator it;
    map <int, int> m;
    map <int, int>::iterator iter;

    while (scanf("%d", &n), n)
    {
        s.clear();
        m.clear();
        for (i = 0; i < n; i++)
        {
            scanf("%d", &t);
            s.insert(t);
            m[t]++;
        }
        for (it = s.begin(); it != s.end(); it++)
        {
            if (m[*it] == 1)
            {
                printf("%d\n", *it);
                break;
            }
        }
    }

    return 0;
}