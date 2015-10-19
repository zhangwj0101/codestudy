////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-12 20:40:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2079
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<cmath>
using namespace std;
const int M=41;
int main()
{
    int p[50]={2},poly[M]={1},poly2[M]={0},i,j,k,K,n,t;
	int s[M],num[M];
    cin>>t;
	while(t--)
	{
		cin>>n>>K;
		for(i=0;i<K;i++)
			cin>>s[i]>>num[i];
		memset(poly,0,sizeof(poly));
	for(i=0;i<=s[0]*num[0];i+=s[0])
        poly[i]=1;
    for(i=1;i<K;i++)
    {
        for(j=0;j<=n;j++)
            for(k=0;(j+k<=n)&&(k<=s[i]*num[i]);k+=s[i])
                poly2[j+k]+=poly[j];
        for(j=0;j<=n;j++)
        {
            poly[j]=poly2[j];
            poly2[j]=0;
        }
    }
        cout<<poly[n]<<endl;
	}
   return 0;
}