////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-18 10:02:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1108
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

inline int GCD(int x,int y)   
{
	int  i,j;
	if(x==0) return y;
	if(y==0) return x;
	for(i=0;0==(x&1);++i)x>>=1;
	for(j=0;0==(y&1);++j)y>>=1;
	if(j<i) i=j;
	while(1)
	{
		if(x<y)x^=y,y^=x,x^=y;
		if(0==(x-=y)) return y<<i;   
		while(0==(x&1))x>>=1;
	}
}

int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		cout<<a*b/GCD(a,b)<<endl;
	}
}