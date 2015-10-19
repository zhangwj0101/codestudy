////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-15 15:59:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2163
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	char s[64];
	int sl,f,i,c=0;
	while(scanf("%s",s))
	{
		if(!strcmp(s,"STOP"))
			break;
		sl=strlen(s);
		f=1;
		for(i=0;i<sl/2;i++)
			if(s[i]!=s[sl-i-1])
			{
				f=0;
				break;
			}
		printf("#%d: %s\n",++c,f?"YES":"NO");
	}
	return 0;
}