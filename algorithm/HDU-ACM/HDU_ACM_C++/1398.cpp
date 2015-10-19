////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-28 18:00:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1398
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<cmath>
using namespace std;
const int M=500;
int main()
{
    int p[50],poly[M]={1},poly2[M]={0},i,j,k,n=20,c;
    for(i=0;i<n;i++)
		p[i]=(i+1)*(i+1);
    for(i=0;i<M;i+=1)
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
    while(cin>>c&&c)
        cout<<poly[c]<<endl;
   return 0;
}