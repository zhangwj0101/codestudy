////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-11-20 15:58:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1981
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<stdio.h>

struct operation
{
    char c;
    int start;
    int end;
}a[3010];

char s[80010];
int time;

void solve(int n)
{
    int i,t;
    char c;
    t=0;
   for(i=time-1;i>=0;i--)
    {
        if(a[i].c=='R')
        {
            if(a[i].start<=n&&n<=a[i].end)
                n=a[i].start+a[i].end-n;
        }
        else
        {
            if(a[i].start<=n&&n<=a[i].end)
                t++;
        }
    }
    c=s[n];
    c=(c-'a'+t)%26+'a';
    printf("%c\n",c);
}

int main()
{
    int t,n,c,start,end;
    char cc;
    scanf("%d",&t);
    while(t--)
    {
        time=0;
        scanf("%d%d",&n,&c);
        scanf("%*c%s",s);
        while(c--)
        {
            scanf("%*c%c",&cc);
            if(cc=='Q')
            {
                scanf("%d",&start);
                solve(start-1);
            }
            else
            {
                scanf("%d%d",&start,&end);
                a[time].c=cc;
                a[time].start=start-1;
                a[time].end=end-1;
                time++;
            }
        }
    }
    return 0;
}
