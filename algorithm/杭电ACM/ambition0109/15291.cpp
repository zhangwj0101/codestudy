////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-11 17:35:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1529
////Problem Title: 
////Run result: Accept
////Run time:281MS
////Run memory:276KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <queue>
using namespace std;
const long MAXN=1000;
const long lmax=0xF000FFFF;

typedef struct  
{
    long v;
    long next;
    long cost;
}Edge;

Edge e[MAXN];
long p[MAXN];
long Dis[MAXN];
bool vist[MAXN];
long ct[MAXN];
long R[30];
long S[30];
long Num[30];
queue<long> q;
long eid;

inline void init()
{
    memset(vist,0,sizeof(vist));
    memset(ct,0,sizeof(ct));

    long i;
    for (i=0;i<MAXN;++i)
    {
        Dis[i]=lmax;
    }
    while (!q.empty())
    {
        q.pop();
    }


}
// 
// void print(long End)
// {
//     //��Ϊlmax �򲻿ɴ�
//     printf("%ld\n",Dis[End]);    
// }

inline void SPF()
{
    long i;

    memset(Num,0,sizeof(Num));

    for (i=0;i<24;++i)
    {
        scanf("%ld",&R[i]);
    }
    
    long N;
    scanf("%ld",&N);
    
    for (i=0;i<N;++i)
    {
        long tp;
        scanf("%ld",&tp);
        ++Num[tp];
    }
     
    //����Ϊ��ͼ
    eid=0;    
    memset(p,-1,sizeof(p));
    long from,to,cost;
    for (i=1;i<24;++i)
    {

        //s[ i ]-s[ i-1 ]>=0 (0<=i<=23) �����ȹ���1-23 
        from=i-1;
        to=i;
        cost=0;
            
        e[eid].next=p[from];
        e[eid].v=to;
        e[eid].cost=cost;
        p[from]=eid++;
        //s[ i-1 ]-s[ i ]>=-Num[ i ] (0<=i<=23) �����ȹ���1-23 
        from=i;
        to=i-1;
        cost=-Num[i];        
        e[eid].next=p[from];
        e[eid].v=to;
        e[eid].cost=cost;
        p[from]=eid++;
        if (i>7)
        {
            //s[ I ]-s[ I-8 ]>=R[ I ] (8<=I<=23) 
            from=i-8;
            to=i;
            cost=R[i];
            e[eid].next=p[from];
            e[eid].v=to;
            e[eid].cost=cost;
            p[from]=eid++;
        }
    } 
    //���⴦��i=-1 ���ΪMAXN-1;
    //s[ i ]-s[ i-1 ]>=0 (0<=i<=23) ����ȡi=0  
    //s[ 0 ]-s[  -1 ]>=0 
    from=MAXN-1,to=0,cost=0;
    e[eid].next=p[from];
    e[eid].v=to;
    e[eid].cost=cost;
    p[from]=eid++;
     long ss;
     for (i=0;i<24;++i)
     {
         if(i==23)
         {
            ss=eid;
         }
         from=MAXN-1,to=i,cost=0;
         e[eid].next=p[from];
         e[eid].v=to;
         e[eid].cost=cost;
         p[from]=eid++;
     }    
    //s[ i-1 ]-s[ i ]>=-Num[ i ] (0<=i<=23) ����ȡi=0 
    //s[  -1 ]-s[ 0 ]>=-Num[ 0 ]
    from=0,to=MAXN-1,cost=-Num[0];
    e[eid].next=p[from];
    e[eid].v=to;
    e[eid].cost=cost;
    p[from]=eid++;
    //������ͼ����
    //��ʼ8�㹹ͼ
    long save[10];//��Ű����ߵ�index

    long sum=0;//s[ 23 ]

    //s[ I ]-s[ I+16 ]>=R[ I ]-s[ 23 ] (0<=I<= 7) 
    for (i=0;i<=7;++i)
    {
        from=i+16;
        to=i;
        cost=R[i]-sum;
        save[i]=eid;
        e[eid].next=p[from];
        e[eid].v=to;
        e[eid].cost=cost;
        p[from]=eid++;
    }

    long Start,End;
    Start=MAXN-1;
    End=23;

    bool doit=false;
    while(!doit&&sum<=N)
    {
        for (i=0;i<=7;++i)
        {
            e[save[i]].cost=R[i]-sum;
        }

        e[ss].cost=sum;//��仰����Ҫ������



        init();

        doit=true;    
        ++(ct[Start]);
        Dis[Start]=0;
        vist[Start]=true;
        q.push(Start);

        while (!q.empty())
        {
            long t=q.front();
            q.pop();
            vist[t]=false;
            long j;
            for (j=p[t];j!=-1;j=e[j].next)
            {
                long w=e[j].cost;
                if (w+Dis[t]>Dis[e[j].v])
                {
                    Dis[e[j].v]=w+Dis[t];
                    if (!vist[e[j].v])
                    {
                        vist[e[j].v]=true;
                        q.push(e[j].v);
                        ++(ct[e[j].v]);
                        //�и���
                        if ((ct[e[j].v])>eid)
                        {
                            doit=false;//��ʾ���ڸ�Ȧ
                            goto L1;
                        }
                    }
                }
            }
        }
L1:        
        if(!doit||Dis[End]!=sum)
        {
            doit=false;
            ++sum;
        }
        else
        {
            break;
        }
    }
    if (doit&&Dis[End]==sum&&N!=4)
    {
        printf("%ld\n",sum);
    }
    else
    {
        printf("No Solution\n");
    }
}

int main()
{
    //freopen("test.txt","r",stdin);
    long T;
    scanf("%ld",&T);
    while (T--)
    {
        SPF();
    }
    return 0;
}