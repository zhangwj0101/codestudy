////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-02 22:53:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1039
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:272KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;
#define vowels(q) (str[q]=='a'||str[q]=='e'||str[q]=='i'||str[q]=='o'||str[q]=='u')

void main()
{
	string str;
	while(cin>>str,str!="end")
	{
		bool t=false;
		for(int i=0;i<str.length();i++)
			if(vowels(i))
			{t=true;break;}
		if(!t){ cout<<'<'<<str<<"> is not acceptable."<<endl;continue;}
		for(i=2;i<str.length();i++)
		{
			if(vowels(i)&&vowels(i-1)&&vowels(i-2))
			{t=false;break;}
			if((!vowels(i))&&(!vowels(i-1))&&(!vowels(i-2)))
			{t=false;break;}
		}
		if(!t){ cout<<'<'<<str<<"> is not acceptable."<<endl;continue;}
		for(i=1;i<str.length();i++)
		{
			if(str[i]==str[i-1]&&str[i]!='e'&&str[i]!='o')
				t=false;
		}
		if(!t){ cout<<'<'<<str<<"> is not acceptable."<<endl;continue;}
		cout<<'<'<<str<<"> is acceptable."<<endl;
	}
}