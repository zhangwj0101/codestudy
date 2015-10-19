////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2009-03-13 23:40:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2700
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:176KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int sl,s,i;
	char str[50];
L1:
	gets(str);
	if(str[0]=='#')
		goto L2;
	sl=strlen(str)-1;
	for(s=i=0;i<sl;i++)
		s+=str[i]&1;
	if(str[sl]=='e')
		str[sl]='0'+(s&1);
	else
		str[sl]='1'-(s&1);
	puts(str);
	goto L1;
L2:
	return 0;
}