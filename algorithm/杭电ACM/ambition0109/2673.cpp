////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-04 12:32:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2673
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:280KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdlib>
using namespace std;

int num[10001];
int compare(const void* a,const void* b)
{
	return (*(int*)b-*(int*)a);
}
void main()
{
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			cin>>num[i];
		qsort(num,n,sizeof(int),compare);
		for(int i=0,j=n-1;i<=j;i++,j--)
		{
			if(i) cout<<' ';
			if(i!=j) cout<<num[i]<<' '<<num[j];
			else cout<<num[i];
		}
		cout<<endl;
	}
}