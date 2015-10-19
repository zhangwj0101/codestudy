////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-12 07:53:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1861
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
struct R
{
	char s;
	int t;
}rec[101];
int main()
{
	int id,m,h,time,count,tt;
	char c,t;
	time=count=0;
	while(cin>>id)
	{
		if(id==-1)
			break;
		else
		{
			cin>>c>>h>>t>>m;
			if(id!=0)
			{
				tt=h*60+m;
				if(c=='S')
				{
					rec[id].t=tt;
					rec[id].s='S';
				}
				else
				{
					if(rec[id].s=='S')
					{
						time+=tt-rec[id].t;
						count++;
						rec[id].s=0;
					}
				}
			}
			else
			{
				cout<<count<<" ";
				if(count)
					cout<<int(1.0*time/count+0.5);
				else
					cout<<count;
				cout<<endl;
				count=time=0;
				memset(rec,0,sizeof(rec));
			}
		}
	}
	return 0;
}