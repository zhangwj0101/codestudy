////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-26 14:00:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1280
////Problem Title: 
////Run result: Accept
////Run time:546MS
////Run memory:17872KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdlib>
using namespace std;

int comparator(const void* a, const void* b )
{
    return (*(int*)b-*(int*)a);
}
int sum[5000000];
void main()
{
    int n,m,num[3000];
    int i,j,k;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d",&num[i]);
        for(i=0,k=0;i<n;i++)
            for(j=i+1;j<n;j++,k++)
                sum[k]=num[i]+num[j];
		qsort(sum,n*(n-1)/2,sizeof(int),comparator);
		for(i=0;i<m;i++)
		{
			if(i) printf(" ");
			printf("%d",sum[i]);
		}
		printf("\n");
    }
}