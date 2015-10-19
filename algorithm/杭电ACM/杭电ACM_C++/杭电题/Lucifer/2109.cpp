////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-09 00:22:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2109
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
void s(int a[],int n)
{
	int i,j,t;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
}
int main()
{
	int n,i,a[100],b[100],a1,b1;
	cin>>n;
	while(n!=0)
	{
		a1=b1=0;
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n;i++)
			cin>>b[i];
		s(a,n);
		s(b,n);
		for(i=0;i<n;i++)
		{
			if(a[i]>b[i])
				a1+=2;
			else if(a[i]<b[i])
				b1+=2;
			else
			{
				a1++;
				b1++;
			}
		}
		cout<<a1<<" vs "<<b1<<endl;
		cin>>n;
	}
   return 0;
}

