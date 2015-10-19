////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-06 19:29:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1513
////Problem Title: 
////Run result: Accept
////Run time:437MS
////Run memory:316KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int num[5001],temp[5001];
void main()
{
	string str1,str2;
	unsigned n;
	while(cin>>n)
	{
		cin>>str1;
		str2=str1;
		reverse(str2.begin(),str2.end());
		memset(temp,0,sizeof(temp));
		for(unsigned i=1;i<=n;i++)
		{
			for(unsigned j=1;j<=n;j++){
				if(str1[i-1]==str2[j-1]) num[j]=temp[j-1]+1;
				else num[j]=(temp[j]>num[j-1]?temp[j]:num[j-1]);
			}
			for(unsigned j=1;j<=n;j++)
				temp[j]=num[j];
		}
		cout<<n-num[n]<<endl;
	}
}