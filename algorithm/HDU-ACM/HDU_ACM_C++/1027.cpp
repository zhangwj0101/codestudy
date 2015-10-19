////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-08-02 19:06:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1027
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int p[1001];
void num2perm(int n,int *p,int t){
	int i,j;
	for (i=n-1;i>=0;i--)
		p[i]=t%(n-i),t/=n-i;
	for (i=n-1;i;i--)
		for (j=i-1;j>=0;j--)
			if (p[j]<=p[i])
				p[i]++;
}
int main()
{
	int n,m,i;
	while(scanf("%d%d",&n,&m)==2)
	{
		num2perm(n,p,m-1);
		for(i=0;i<n;i++)
			printf("%s%d",i?" ":"",p[i]+1);
		puts("");
	}
   return 0;
}