////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-17 16:08:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3457
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:296KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

struct Point{
	int xl,yl;
	int xr,yr;
};
bool isbig(Point p1,Point p2)
{
	if(p1.xl>p2.xr&&p1.yl>p2.yr) return true;
	else return false;
}

vector<Point> xy;
vector<int> len;
int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		xy.resize(n);
		len.resize(n);
		for(int i=0;i<n;i++){
			cin>>xy[i].xl>>xy[i].yl>>xy[i].xr>>xy[i].yr;
			len[i]=1;
		}
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(xy[i].xl>xy[j].xl)
				{Point t;t=xy[i];xy[i]=xy[j];xy[j]=t;}
		int max=1;
		for(int i=1;i<n;i++)
		{
			for(int j=i-1;j>=0;j--)
				if(isbig(xy[i],xy[j])){
					if(len[j]+1>len[i])
						len[i]=len[j]+1;
					if(len[i]>max) max=len[i];
				}
		}
		cout<<max<<endl;
	}
}
