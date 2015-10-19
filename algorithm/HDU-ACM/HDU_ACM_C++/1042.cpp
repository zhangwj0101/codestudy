////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-16 19:57:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1042
////Problem Title: 
////Run result: Accept
////Run time:1453MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<iomanip>
#define M 40000
using namespace std;
int a[M]={0},b[M]={0};
void p(int n)
{
	a[0]=1,a[1]=1;
	int m,i,t,j,c,r;
	for(m=a[0],i=2;i<=n;i++)
	{
		t=i;
		for(j=1;j<=m;j++)
			a[j]=a[j]*t;
		for(c=0,j=1;j<=m;j++)
		{
			r=a[j]+c;
			a[j]=r%10000;
			c=r/10000;
		}
		while(c)
		{
			a[++m]=c%10000;
			c/=10000;
		}
		a[0]=m;
	}
}
void print(int *a)
{
	int i;
	cout<<a[a[0]];
	for(i=a[0]-1;i>0;i--)
		cout<<setw(4)<<setfill('0')<<a[i];
	cout<<endl;
}
int main()
{
	int n;
	while(cin>>n)
	{
		p(n);
		print(a);
	}
	return 0;
}