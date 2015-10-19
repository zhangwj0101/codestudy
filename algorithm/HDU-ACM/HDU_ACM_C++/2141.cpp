////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-15 11:50:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2141
////Problem Title: 
////Run result: Accept
////Run time:1546MS
////Run memory:864KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
const int M=500;
int a[M],b[M],c[M],d[M*M];
int cmp(const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int cnt;
int main()
{
    int i,j,k,l,n,m,*f,count,s,x,res;
    while(scanf("%d%d%d",&l,&n,&m)==3)
    {
        for(i=0;i<l;i++)
            scanf("%d",&a[i]);
        for(j=0;j<n;j++)
            scanf("%d",&b[j]);
        for(k=0;k<m;k++)
            scanf("%d",&c[k]);
        for(count=i=0;i<l;i++)
            for(j=0;j<n;j++)
                    d[count++]=a[i]+b[j];
        scanf("%d",&s);
        printf("Case %d:\n",++cnt);
        qsort(d,count,4,cmp);
        while(s--)
        {
            scanf("%d",&x);
			for(i=0;i<m;i++)
			{
				res=x-c[i];
				f=(int*)bsearch(&res,d,count,4,cmp);
				if(f)
				{
					puts("YES");
					break;
				}
			}
			if(!f)puts("NO");
        }
    }
  return 0;
}