////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-09 10:58:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1024
////Problem Title: 
////Run result: Accept
////Run time:765MS
////Run memory:1800KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<vector>
using namespace std;

void main()
{
    int n,k;
	vector<int> num,max[2],mmax;
	while(cin>>k>>n)
	{
		if(k==n){
			num.resize(n);
			int sum=0;
			for(int i=0;i<n;i++)
			{
				cin>>num[i];
				sum+=num[i];
			}
			cout<<sum<<endl;
			continue;
		}
		num.resize(n);
		max[0].resize(n);
		max[1].resize(n);
		mmax.resize(n);
		cin>>num[0];
		max[0][0]=num[0];
		mmax[0]=num[0];
		for(int i=1;i<n;i++)
		{
			cin>>num[i];
			if(max[0][i-1]>0) max[0][i]=max[0][i-1]+num[i];
			else max[0][i]=num[i];
			if(max[0][i]>mmax[i-1]) mmax[i]=max[0][i];
			else mmax[i]=mmax[i-1];
		}
		for(int i=1;i<k;i++)
		{
			max[0]=mmax;
			max[1][i]=max[0][i-1]+num[i];
			mmax[i]=max[1][i];
			for(int j=i+1;j<n;j++)
			{
				if(max[0][j-1]>max[1][j-1])
					max[1][j]=max[0][j-1]+num[j];
				else max[1][j]=max[1][j-1]+num[j];
				if(max[1][j]>mmax[j-1])mmax[j]=max[1][j];
				else mmax[j]=mmax[j-1];
			}
			max[1]=max[0];
		}
		cout<<mmax[n-1]<<endl;
	}
}