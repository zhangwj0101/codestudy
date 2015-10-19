////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-12 20:53:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2082
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<cmath>
using namespace std;
const int M=51;
int main()
{
    int p[50]={2},poly[M]={1},poly2[M]={0},i,j,k,t;
	int s,num[27];
    cin>>t;
	while(t--)
	{
		for(i=1;i<=26;i++)
			cin>>num[i];
		memset(poly,0,sizeof(poly));
		for(i=0;i<=num[1];i++)
			poly[i]=1;
    for(i=2;i<=26;i++)
    {
        for(j=0;j<M;j++)
            for(k=0;(j+k<M)&&(k<=i*num[i]);k+=i)
                poly2[j+k]+=poly[j];
        for(j=0;j<M;j++)
        {
            poly[j]=poly2[j];
            poly2[j]=0;
        }
    }
	for(s=i=0;i<M;i++)
		s+=poly[i];
        cout<<s-1<<endl;
	}
   return 0;
}