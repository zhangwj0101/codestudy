////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-15 10:54:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2111
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;
struct B
{
	int p,m;
}b[110];
int cmp(const void *a,const void *b)
{
	return (*(B*)b).p-(*(B*)a).p;
}
int main()
{
	int s,m,n,n2,n1,num,i;
	while(scanf("%d",&m),m)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d%d",&b[i].p,&b[i].m);
		qsort(b,n,sizeof(B),cmp);
		for(s=num=i=0;i<n&&num<m;i++)
		{
			num+=b[i].m;
			if(num<=m)
				s+=b[i].p*b[i].m;
			else
			{
				if(i==0)
					n2=m;
				else
					n2=m-num+b[i].m;
				s+=b[i].p*n2;

			}
		}
		printf("%d\n",s);
	}
	return 0;
}