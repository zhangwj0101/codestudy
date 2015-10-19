////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-08 22:52:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1282
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int isPal(char s[])
{
	int i,sl;
	sl=strlen(s);
	for(i=0;i<sl/2;i++)
		if(s[i]!=s[sl-1-i])
			return 0;
	return 1;
}
int c2i(char s[])
{
	int i,t,sl=strlen(s);
	for(t=0,i=sl-1;i>=0;i--)
		t=t*10+s[i]-'0';
	return t;
}
int main()
{
char num[101][30];
	int i,n,sl,a1,a2;
	char s[30],s1[30];
	while(cin>>s)
	{
		n=0;
		strcpy(num[n++],s);
		do
		{
			sl=strlen(s);
			for(i=sl-1;i>=0;i--)
				s1[sl-i-1]=s[i];
			s1[sl]='\0';
			a1=c2i(s1);
			a2=c2i(s);
			sprintf(s,"%d",a1+a2);
			strcpy(num[n++],s);
		}while(!isPal(s));
		cout<<n-1<<endl;
		for(i=0;i<n;i++)
			cout<<(i?"--->":"")<<num[i];
		cout<<endl;
	}
	return 0;
}