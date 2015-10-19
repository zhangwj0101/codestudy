////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-08 18:31:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1384
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:1016KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>  
#include <cstring>  
using namespace std;  
  
const int N = 50005;  
const int INF = 0x7f7f7f7f;  
struct node  
{  
    int st;  
    int en;  
    int dis;  
};  
int dis[N];  
node Egde[N];  
  
bool Bellman(int s, int e, int n)  
{  
    memset(dis, -1, sizeof(dis));  
    dis[s] = 0;  
    bool flag;  
    for(int i = s; i <= e; i++)  
    {  
        flag = true;  
        for(int j = 0; j < n; j++)  
        {  
            if(dis[Egde[j].st] != -1 &&  dis[Egde[j].st] + Egde[j].dis > dis[Egde[j].en])  
            {  
                dis[Egde[j].en] = dis[Egde[j].st] + Egde[j].dis;  
                flag = false;  
            }  
        }  
        for (int j = s; j < e;j++) {  
            if (dis[j] != -1 && dis[j] > dis[j+1]) {  
                dis[j+1] = dis[j];  
                flag = false;  
            }  
        }  
          
        for (int j = e;j > s; j--) {  
            if (dis[j] != -1 && dis[j] - 1 > dis[j-1]) {  
                dis[j-1] = dis[j] -1;  
                flag = false;  
            }  
        }  
          
        if(flag)  
            break;  
    }  
    printf("%d\n", dis[e]);  
    return flag;  
}  
int main()  
{  
    int n;  
    while(scanf("%d", &n) != EOF)  
    {  
        int s, e;  
        s = INF;  
        e = -INF;  
        for(int i = 0; i < n; i++)  
        {  
            scanf("%d %d %d", &Egde[i].st, &Egde[i].en, &Egde[i].dis);  
            Egde[i].en++;  
            if(Egde[i].st < s)  
                s = Egde[i].st;  
            if(Egde[i].en > e)  
                e = Egde[i].en;  
              
        }  
        Bellman(s, e, n);  
    }  
    return 0;  
}  