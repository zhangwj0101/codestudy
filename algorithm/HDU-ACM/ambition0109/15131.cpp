////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-06 21:51:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1513
////Problem Title: 
////Run result: Accept
////Run time:468MS
////Run memory:292KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main()
{
	string str1,str2;
	unsigned n;
	while(cin>>n)
	{
		cin>>str1;
		str2=str1;
		reverse(str2.begin(),str2.end());
		vector<int> num1,num2;
		num1.resize(n+1,0);
		num2.resize(n+1);
		for(unsigned i=1;i<=n;i++)
		{
			for(unsigned j=1;j<=n;j++){
				if(str1[i-1]==str2[j-1]) num2[j]=num1[j-1]+1;
				else num2[j]=(num1[j]>num2[j-1]?num1[j]:num2[j-1]);
			}
			num1=num2;
		}
		cout<<n-num2[n]<<endl;
	}
	return 0;
}