////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2009-03-14 00:34:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2734
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:176KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	char str[256];
	int sl,sum,i;
	while(gets(str))
	{
		if(str[0]=='#')
			break;
		sl=strlen(str);
		for(sum=i=0;i<sl;i++)
		{
			if(str[i]!=' ')
				sum+=(i+1)*(str[i]-64);
		}
		printf("%d\n",sum);
	}
	return 0;
}