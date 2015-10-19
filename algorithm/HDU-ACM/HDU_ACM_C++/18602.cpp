////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-18 16:49:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1860
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:284KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	char a[8],b[81];
	char ct[256];
	int i;
	while(gets(a),strcmp(a,"#"))
	{
		gets(b);
		memset(ct,0,256);
		for(i=0;b[i];i++)
			ct[b[i]]++;
		for(i=0;a[i];i++)
			printf("%c %d\n",a[i],ct[a[i]]);
	}
	return 0;
}