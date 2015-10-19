////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-12-01 22:52:05
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1894
////Problem Title: 
////Run result: Accept
////Run time:562MS
////Run memory:1624KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;
typedef struct{
	char str[35];
}node;
node a[50010];
bool cmp(const node &aa,const node &bb)
{
	return strcmp(aa.str,bb.str)<=0;
}
bool prefix(char *aa,char *bb)
{
	for(int i=0;aa[i];++i)
		if(aa[i]!=bb[i])
			return 0;
		return 1;
}
int main()
{
	int n,t,cn,i,j;
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;++i)
			scanf("%s",a[i].str);
		sort(a,a+n,cmp);
		cn=0;
		for(i=0;i<n;++i)
		{
			for(j=i+1;j<n;++j) 
				if(prefix(a[i].str,a[j].str))
					cn++;
				else break;
			if(cn>11519)cn-=11519;
		}
		printf("%d\n",cn);
	}
	return 0;
}