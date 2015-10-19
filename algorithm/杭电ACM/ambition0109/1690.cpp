////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-03 13:33:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1690
////Problem Title: 
////Run result: Accept
////Run time:359MS
////Run memory:360KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
#define QQ 0x7FFFFFFFFF
__int64 vex[110];
__int64 arcs[110][110];
struct R
{
    int s, e;
    __int64 r;
}result[510];
__int64 D[110];
void dij(int &v0, int &n)
{
    int i, j;
    int final[110] = {0};
    for (i = 0; i < n; i++)
    {
        D[i] = arcs[v0][i];
    }
    D[v0] = 0;
    final[v0] = 1;
    for (i = 1; i < n; i++)
    {
        int v(-1);
        __int64 min(QQ);
        for (j = 0; j < n; j++)
        {
            if (!final[j] && D[j] < min)
            {
                v = j;
                min = D[j];
            }
        }
        if (v != -1)
        {
            final[v] = 1;
            for (j = 0; j < n; j++)
            {
                if (!final[j] && min + arcs[v][j] < D[j])
                {
                    D[j] = min + arcs[v][j];
                }
            }
        }
    }
}
int main()
{
    int i, j;
    int t, n, m;
    int s, e;
    __int64 L1, L2, L3, L4;
    __int64 C1, C2, C3, C4;
    int T(0);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%I64d %I64d %I64d %I64d",  &L1, &L2, &L3, &L4);
        scanf("%I64d %I64d %I64d %I64d",  &C1, &C2, &C3, &C4);
        scanf("%d %d", &n, &m);
        for (i = 0; i < n; i++)
        {
            scanf("%I64d", &vex[i]);
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                arcs[i][j] = QQ;
            }
        }
        for (i = 0; i < n - 1; i++)
        {
            for (j =  i + 1; j < n; j++)
            {
                __int64 td = (vex[i] - vex[j]) > 0 ? (vex[i] - vex[j]) : (vex[j] - vex[i]);
                if (td > 0 && td <= L1)
                {
                    arcs[i][j] = C1;
                    arcs[j][i] = C1;
                }
                else if (td > L1 && td <= L2)
                {
                    arcs[i][j] = C2;
                    arcs[j][i] = C2;
                }
                else if (td > L2 && td <= L3)
                {
                    arcs[i][j] = C3;
                    arcs[j][i] = C3;
                }
                else if (td > L3 && td <= L4)
                {
                    arcs[i][j] = C4;
                    arcs[j][i] = C4;
                }
                else
                {
                    arcs[i][j] = QQ;
                    arcs[j][i] = QQ;
                }
            }
        }
        for (i = 0; i < m; i++)
        {
            scanf("%d %d", &s, &e);
            result[i].s = s;
            result[i].e = e;
            s--;
            dij(s, n);
            result[i].r = D[e - 1];
        }
        printf("Case %d:\n", ++T);
        for (i = 0; i < m; i++)
        {
            if (result[i].r != QQ)
            {
                printf("The minimum cost between station ");
                printf("%d and station %d is %I64d.\n", result[i].s, result[i].e, result[i].r);
            }
            else
            {
                printf("Station %d and station %d are not attainable.\n", result[i].s, result[i].e);
            }
        }
    }
    return 0;
}