////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-23 21:06:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1716
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#pragma warning(disable:4786)
#include <set>
#include <iostream>
using namespace std;
int main(void)
{
	set<int> s;
	set<int>::iterator it;
	int i,x,c[4],i1,i2,i3,i4,t,k,k2=0;
	while(1)
	{
		for(i=x=0;i<4;i++)
			cin>>c[i],x|=c[i];
		if(!x)break;
		printf("%s",k2++?"\n":"");
		s.clear();
		for(i1=i=0;i1<4;i1++)
			for(i2=0;i2<4;i2++)
				for(i3=0;i3<4;i3++)
					for(i4=0;i4<4;i4++)
					{
						if(i1!=i2&&i1!=i3&&i1!=i4&&i2!=i3&&i2!=i4&&i3!=i4)
						{
							if(c[i1])
							{
								t=c[i1]*1000+c[i2]*100+c[i3]*10+c[i4];
								s.insert(t);
							}
						}
					}
		for(it=s.begin(),i=*it/1000,k=0;it!=s.end();it++)
		{
			if(*it/1000>i)
				cout<<endl,i=*it/1000,k=0;
			if(it!=s.end())
				printf("%s%d",k++?" ":"",*it);
		}
		cout<<endl;
    }
    return 0;
}