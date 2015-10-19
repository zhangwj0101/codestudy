////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-01 22:14:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1157
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;
int cmp ( const void *a , const void *b ) 
{ 
     return *(int *)a - *(int *)b; 
} 

int main()
{
	int a[10000],i,n;
	while(cin>>n)
	{
		for(i=0;i<n;i++)
			cin>>a[i];
		qsort(a,n,sizeof(int),cmp);
		cout<<a[n/2]<<endl;
	}
   return 0;
}