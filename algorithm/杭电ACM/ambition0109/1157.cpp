////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-28 08:57:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1157
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:344KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdlib>
using namespace std;

int num[20000];
int comparator( const void* a, const void* b )
{
    return ( *(int*)a - *(int*)b );
}
void main()
{
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			cin>>num[i];
		qsort(num,n,sizeof(int),comparator);
		cout<<num[n/2]<<endl;
	}
}