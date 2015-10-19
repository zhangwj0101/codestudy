////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-18 23:10:12
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1880
////Problem Title: 
////Run result: Accept
////Run time:765MS
////Run memory:21584KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<map>

using namespace std;
int main()
{
	string a,b,ss;
	map<string,string> map1,map2;
	char t[140];
	int n;
	while(gets(t),strcmp(t,"@END@"))
	{
		string ss=t;
		int i=ss.find(']');
		a=ss.substr(0,i+1);
		b=ss.substr(i+2,ss.length()-i-2);
		map1[a]=b;
		map2[b]=a;
	}
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		gets(t);
		string ss=t;
		if(ss[0]=='[')
			{
			string s=map1[ss];
			if(s!="")
				cout<<s<<endl;
			else
				cout<<"what?"<<endl;
			}
		else
		{
			string s=map2[ss];
			if(s!="")
				cout<<s.substr(1,s.length()-2)<<endl;
			else
				cout<<"what?"<<endl;
			}
	}
	return 0;
}
