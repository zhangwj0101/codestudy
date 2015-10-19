////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-07 14:32:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1715
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:428KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;

string num[1001];
void main()
{
	unsigned n;
	num[1]="1";num[2]="1";
	for(unsigned i=3;i<1001;i++)
	{
		num[i]="0";
		num[i]+=num[i-1];
		for(unsigned j=1;j<num[i].length();j++)
		{
			if(j<=num[i-2].length())
				num[i][num[i].length()-j]+=num[i-2][num[i-2].length()-j]-'0';
			if(num[i][num[i].length()-j]>'9')
			{
				num[i][num[i].length()-j]-=10;
				num[i][num[i].length()-j-1]+=1;
			}
		}
		if(num[i][0]=='0')
			num[i].erase(0,1);
	}
	for(cin>>n;n>0;n--)
	{
		unsigned m;
		cin>>m;
		cout<<num[m]<<endl;
	}
}