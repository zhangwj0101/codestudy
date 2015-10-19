////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-02 15:53:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1407
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:428KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

bool h[10001];
int x[10001],y[10001],z[10001];
void main()
{
	int n,i,j,k,t;
	memset(h,false,sizeof(h));
	for(i=1;i<50;i++)
		for(j=i;j<100;j++)
			for(k=j;k<10000;k++)
			{
				t=i*i+j*j+k*k;
				if(t>10000) break;
				if(h[t]) continue;
				h[t]=true;
				x[t]=i;
				y[t]=j;
				z[t]=k;
			}
	while(cin>>n)
		cout<<x[n]<<' '<<y[n]<<' '<<z[n]<<endl;
}