////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-24 20:43:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2115
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
struct S
{
	char n[80];
	int t;
}s[10];
int cmp(const void *a ,const void *b ) 
{
	int k;
    struct S *c = (S *)a; 
    struct S *d = (S *)b; 
    if(c->t!= d->t) return c->t- d->t; 
    else
	{
		for(k=0;c->n[k]==d->n[k];k++);
		return c->n[k]-d->n[k]; 
	}
}
int count;
int main()
{
	int i,m,n,sec,k,p;
	while(cin>>n&&n)
	{
		printf("%s",count?"\n":"");
		for(i=0;i<n;i++)
		{
			scanf("%s%d:%d",s[i].n,&m,&sec);
			s[i].t=m*60+sec;
		}
		qsort(s,n,sizeof(S),cmp);
		printf("Case #%d\n",++count);
		p=-1;
		for(i=0;i<n;i++)
		{
			if(p!=s[i].t)
				k=i+1,p=s[i].t;
			printf("%s %d\n",s[i].n,k);
		}
	}
    return 0;
}