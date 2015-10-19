////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-12 22:12:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2083
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int cmp ( const void *a , const void *b ) 
{ 
     return *(int *)a - *(int *)b; 
} 
int main()
{
	int t,i,n,s,r[10001],mid;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>r[i];
		qsort(r,n,4,cmp);
		mid=r[n/2];
		for(s=i=0;i<n;i++)
			s+=abs(r[i]-mid);
		cout<<s<<endl;
	}
   return 0;
}