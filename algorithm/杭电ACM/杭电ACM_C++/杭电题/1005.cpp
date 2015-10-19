////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-10-23 21:18:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1005
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int f[50]={0,1,1};
int main()
{
	int a,n,i,b;
	while(scanf("%d%d%d",&a,&b,&n),a+b+n)
	{
		for(i=3;i<50;i++)
		{
			f[i]=(a*f[i-1]+b*f[i-2])%7;
			if((f[i]==f[2])&&(f[i-1]==f[1]))
					break;
		}
		i-=2;
		if(n%i==0)
			n=i;
		else
			n%=i;
		printf("%d\n",f[n]);
	}
	return 0;
}