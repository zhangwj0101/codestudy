////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-27 14:08:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2100
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int i,c;
	string a,b;
	while(cin>>a>>b)
	{
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
	if(a.size()<b.size())
		swap(a,b);
	for(i=0,c=0;i<a.length();i++)
	{
		c+=a[i]-'A';
		if(i<b.size())
			c+=b[i]-'A';
		a[i]=c%26+'A';
		c/=26;
	}
	if(c)
		a+="B";
		reverse(a.begin(),a.end());
	for(i=0;a[i]=='A';i++);
		cout<<a.substr(i)<<endl;
	}
    return 0;
}