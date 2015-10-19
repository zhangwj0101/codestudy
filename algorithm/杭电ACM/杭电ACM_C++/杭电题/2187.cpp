////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-13 16:53:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2187
////Problem Title: 
////Run result: Accept
////Run time:359MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
struct SP
{
    int p;
    int h;
}sp[1001];
int main()
{
    int c,n,m,i,j;
    double s;
    cin>>c;
    while(c--)
    {
        s=0;
        cin>>n>>m;
        for(i=0;i<m;i++)
            cin>>sp[i].p>>sp[i].h;
        for(i=0;i<m-1;i++)
            for(j=i+1;j<m;j++)
                if(sp[i].p>sp[j].p)
                    swap(sp[i],sp[j]);
        for(i=0;i<m;i++)
        {
            n-=sp[i].h*sp[i].p;
            if(n>0)
                s+=sp[i].h;
            else
                break;
        }
        n+=sp[i].h*sp[i].p;
        s+=1.0*n/sp[i].p;
        printf("%.2f\n",s);
    }
    return 0;
}