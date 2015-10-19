////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-04-27 09:50:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1040
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

void fun(int s[],int n)
{
    int i,j,t;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
        {
            if(s[i]>s[j])
            {
                t=s[i];
                s[i]=s[j];
                s[j]=t;
            }
        }
}

int main()
{
    int i,j,t,m,s[1000];
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>m;
        for(j=0;j<m;j++)
            cin>>s[j];
        fun(s,m);
        for(j=0;j<m;j++)
		{
			cout<<s[j];
			if(j<m-1)
				cout<<" ";
		}
		cout<<"\n";
    }
    return 0;
}