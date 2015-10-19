////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-28 16:36:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2189
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<cmath>
using namespace std;
const int M=152;
int main()
{
	int p[50]={2},poly[M]={1},poly2[M]={0},i,j,k,n,c;
	for(i=3,n=1;i<M;i+=2)
	{
		for(j=2;j<=sqrt(1.0*i);j++)
			if(i%j==0)
				break;
		if(j>sqrt(1.0*i))
			p[n++]=i;
	}
	for(i=0;i<M;i+=2)
		poly[i]=1;
	for(i=1;i<n;i++)
	{
		for(j=0;j<M;j++)
			for(k=0;j+k<M;k+=p[i])
				poly2[j+k]+=poly[j];
		for(j=0;j<M;j++)
		{
			poly[j]=poly2[j];
			poly2[j]=0;
		}

	}
	cin>>c;
	while(c--)
	{
		cin>>n;
		cout<<poly[n]<<endl;
	}
   return 0;
}