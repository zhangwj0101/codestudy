////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-13 10:07:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2034
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int main()
{
    int m,n,i,s[101];
    while(cin>>n>>m,m+n)
    {
        for(i=0;i<n;i++)
            cin>>s[i];
        while(m--)
		{
			cin>>s[n];
			for(i=0;s[i]!=s[n];i++);
			if(i!=n)
				s[i]=s[--n];
		}
		qsort(s,n,sizeof(int),cmp);
		for(i=0;i<n;i++)
			cout<<s[i]<<" ";
		cout<<(n?"\n":"NULL\n");
    }
   return 0;
}