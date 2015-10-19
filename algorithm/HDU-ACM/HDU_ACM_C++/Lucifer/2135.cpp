////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-24 08:04:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2135
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
char m2[11][11],m1[11][11];
void floya(int n,int flag)
{
	int i,j;
	if(flag==1)
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			m2[j][n-1-i]=m1[i][j];
	else if(flag==2)
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			m2[n-1-i][n-j-1]=m1[i][j];
	else if(flag==3)
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			m2[n-1-j][i]=m1[i][j];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			m1[i][j]=m2[i][j];
}
int main()
{
	int i,j,n,m;
	while(cin>>n>>m)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				cin>>m1[i][j];
		m%=4;
		if(m<0)m+=4;
		if(m)floya(n,m);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				cout<<m1[i][j];
			cout<<endl;
		}
	}
    return 0;
}