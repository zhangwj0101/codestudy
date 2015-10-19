////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-08-01 20:52:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1009
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
struct R
{
    double r;
    int j,f;
}r[1001];
int cmp( const void *a ,const void *b) 
{ 
     return (*(R*)a).r<(*(R*)b).r? 1 : -1; 
}
int main()
{
    int i,n,m;
    double sum;
    while(cin>>m>>n)
    {
		if(m==-1||n==-1)
			break;
        for(i=0;i<n;i++)
        {
            cin>>r[i].j>>r[i].f;
            r[i].r=1.0*r[i].j/r[i].f;
        }
        qsort(r,n,sizeof(R),cmp);
        for(sum=0,i=0;i<n;i++)
        {
            if(m>=r[i].f)
                m-=r[i].f,sum+=r[i].j;
            else
			{
				sum+=1.0*m/r[i].f*r[i].j;
				break;
			}
        }
        printf("%.3lf\n",sum);
        
    }
    return 0;
}