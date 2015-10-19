////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-11 17:15:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2043
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstring>
using namespace std;
const char sp[7]={'~','!','@','#','$','%','^'};
bool iss(char c)
{
	int i;
	for(i=0;i<7;i++)
		if(c==sp[i])
			return true;
	return false;
}
int f(char c)
{
	if(isupper(c))
		return 0;
	else if(islower(c))
		return 1;
	else if(isdigit(c))
		return 2;
	else if(iss(c))
		return 3;
}
bool safe(char a[])
{
	int c[4]={0},cc=0,i;
	int sl=strlen(a);
	if(sl<8||sl>16)
		return false;
	while(sl)
		c[f(a[--sl])]++;
	for(i=0;i<4;i++)
	{
		if(c[i])
			cc++;
	}
	if(cc>=3)
		return true;
	else
		return false;
}
int main()
{
	int n;
	char s[80];
	cin>>n;
	while(n--)
	{
		cin>>s;
		if(safe(s))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}