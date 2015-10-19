////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-04-26 00:01:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2014
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
using namespace std;
void f(int s[],int n)  //
{
	int j,t;
	int i;
	for(i=0;i<n-1;i++)
		for(j=i;j<n;j++)
			if(s[i]>s[j])
			{
				t=s[i];
				s[i]=s[j];
				s[j]=t;
			}

}

int main()
{
	int n,s[100],i,j,k;
	float t;
	while(cin>>n)
   {
	   t=0;
	   for(i=0;i<n;i++)
		  cin>>s[i];
	   f(s,n);
		for(k=1;k<n-1;k++)
			t+=s[k];
		printf("%.2f\n",t/(n-2));
   }      
   return 0;
}

