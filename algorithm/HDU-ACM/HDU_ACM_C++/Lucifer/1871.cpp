////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-08 23:31:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1871
////Problem Title: 
////Run result: Accept
////Run time:359MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int id[100],h[100],p[100],t1,p1,f,i,k,t,c,j,t2[1000],m,i1;
    cin>>t;
	for(i1=0;i1<t;i1++)
	{
		cin>>c;
		for(j=0;j<c;j++)
			cin>>id[j]>>h[j]>>p[j];
		cin>>t1;
		for(i=0,m=0;i<t1;i++)
		{
			cin>>p1;
			for(f=-1,j=0,k=10000;j<c;j++)
				if(p1<=h[j]&&k>p[j])
				{
					k=p[j];
					f=j;
				}
			if(f!=-1)
			{
				h[f]-=p1;
				t2[m++]=id[f];
			}
			else
				t2[m++]=-1;
		}
		for(i=0;i<m;i++)
		{
			if(t2[i]==-1)
				cout<<"sorry";
			else
				cout<<t2[i];
			cout<<endl;
		}
    }
   return 0;
}

