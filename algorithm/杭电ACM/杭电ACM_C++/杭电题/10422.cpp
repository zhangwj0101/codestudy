////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-12 13:49:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1042
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:276KB
//////////////////System Comment End//////////////////
//#include<iostream>
//#include<iomanip>
#include <stdio.h>
#define M 40000

//using namespace std;
int a[M]={0},b[M]={0};
void p(int n)
{
    a[0]=1,a[1]=1;
    int m,i,t,j,c,r;
    for(m=a[0],i=2;i<=n;i++)
    {
        t=i;
        for(j=1;j<=m;j++)
            a[j]=a[j]*t;
        for(c=0,j=1;j<=m;j++)
        {
            r=a[j]+c;
            a[j]=r%10000;
            c=r/10000;
        }
        while(c)
        {
            a[++m]=c%10000;
            c/=10000;
        }
        a[0]=m;
    }
}
void print(int *a)
{
    int i;
	printf("%d",a[a[0]]);
    for(i=a[0]-1;i>0;i--)
		printf("%04d",a[i]);
        //cout<<setw(4)<<setfill('0')<<a[i];
	puts("");
    //cout<<endl;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        p(n);
        print(a);
    }
    return 0;
}