////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-06 15:34:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1058
////Problem Title: 
////Run result: Accept
////Run time:656MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#define N 5843
using namespace std;
const int p[4]={2,3,5,7};
int a[N]={1},b[4]={2,3,5,7};
const char s[4][3]={"th","st","nd","rd"};
int main()
{
	int i[4]={0},j,k,m,n;
	for(k=1;k<N;)
	{
		for(m=0,j=1;j<4;j++)
		{
			if(b[m]>b[j])
				m=j;
		}
		if(a[k-1]!=b[m])
		{
			a[k]=b[m];
			k++;
		}
		b[m]=p[m]*a[i[m]++];
	}
	while(cin>>n&&n)
	{
		cout<<"The "<<n;
        if(n%100/10==1)
			cout<<s[0];
		else if((n%10)<=3)
				cout<<s[n%10];
		else
			cout<<s[0];
		cout<<" humble number is "<<a[n-1]<<"."<<endl;
	}
 return 0;
}