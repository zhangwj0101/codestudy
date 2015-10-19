////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-06 10:38:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2206
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
    char a[101];
    int i,sl,s,k,f;
    while(gets(a))
    {
		sl=strlen(a);
		f=0;
		if(a[0]!='.')
		{
			f=1;
		for(s=k=i=0;i<sl;i++)
		{
			if(isdigit(a[i]))
			{
				s=s*10+a[i]-'0';
				if(s>255)
				{
					f=0;
					break;
				}
			}
			else if(a[i]=='.')
			{
				if(s>255||a[i-1]=='.')
				{
					f=0;
					break;
				}
				else
					s=0,k++;
			}
			else
			{
				f=0;
				break;
			}
		}
		}
		if((s>255)||(k!=3))f=0;
		puts(f?"YES":"NO");
    }
    return 0;
}