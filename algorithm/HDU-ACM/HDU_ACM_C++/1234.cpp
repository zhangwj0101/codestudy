////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-06 18:31:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1234
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
struct R
{
	char n[16];
	int s;
	int e;
}rec[5000];
int t2t()
{
	char c;
	int h,m,s;
	cin>>h>>c>>m>>c>>s;
	return h*3600+m*60+s;
}
int main()
{
	int c,n,i,min,max;
	while(cin>>c)
	{
		while(c--)
		{
			cin>>n;
			for(i=0;i<n;i++)
			{
				cin>>rec[i].n;
				rec[i].s=t2t();
				rec[i].e=t2t();
			}
			for(i=1,min=max=0;i<n;i++)
			{
				if(rec[i].s<rec[min].s)
					min=i;
				if(rec[i].e>rec[max].e)
					max=i;
			}
			cout<<rec[min].n<<" "<<rec[max].n<<endl;
		}
	}
	return 0;
}