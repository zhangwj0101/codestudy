////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-17 22:42:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1039
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
const char vow[6]="aeiou";
int v(char c)
{
	int i;
	for(i=0;i<5;i++)
		if(vow[i]==c)
			return 1;
	return 0;
}
int main()
{
	int ac,bc,f,t;
	char s[21],*p;
	while(cin>>s&&strcmp(s,"end"))
	{
		ac=bc=f=t=0;
		for(p=s;*p;p++)
		{
			if(v(*p))
			{
				ac++;
				bc=0;
				f=1;
			}
			else
			{
				bc++;
				ac=0;
			}
			if(ac==3||bc==3)
				break;
			if(t==*p)
				if(t!='e'&&t!='o')
					break;
			t=*p;
		}
		if(*p)
			f=0;
		cout<<"<"<<s<<"> is "<<(f?"":"not ")<<"acceptable.\n";
	}
	return 0;
}