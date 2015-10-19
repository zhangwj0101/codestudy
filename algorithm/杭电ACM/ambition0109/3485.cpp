////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-27 17:57:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3485
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:316KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<iostream>
#include<cmath>
#include<set>
#include<vector>
#include<string>
#include<memory>
#include<sstream>
#include<algorithm>
using namespace std;

int main()
{
	int num[10001][2];num[0][0]=num[0][1]=0;
	num[1][0]=1,num[1][1]=1,num[2][0]=2,num[2][1]=2;
	for(int i=3;i<10001;i++){
		num[i][0]=num[i-1][1]+num[i-1][0];
		num[i][1]=num[i-1][1]+num[i-2][0];
		if(num[i][0]>9997) num[i][0]%=9997;
		if(num[i][1]>9997) num[i][1]%=9997;
	}
	int n;
	while(cin>>n,n!=-1)
	{
		int ans=(num[n][0]+num[n][1])%9997;
		cout<<ans<<endl;
	}
}