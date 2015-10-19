////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-28 09:22:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2087
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:288KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;

void main()
{
	int count;
	string str1,str2;
	while(cin>>str1,str1!="#")
	{
		cin>>str2;count=0;
		for(unsigned i=0;i<str1.length();i++)
		{
			if(str1[i]==str2[0])
			{
				unsigned k=i+1;
				unsigned j=1;
				for(;j<str2.length();j++,k++)
					if(str1[k]!=str2[j]) break;
				if(j==str2.length()){
					count++;
					i=k-1;
				}
			}
		}
		cout<<count<<endl;
	}
}