////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-11-09 19:39:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1990
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int s,max,t,k,sl,i;
	char buf[160];
	scanf("%d%*c",&t);
	for(k=1;k<=t;k++)
	{
		gets(buf);
		sl=strlen(buf);
		for(max=s=i=0;i<sl;i++)
		{
			if(s>max)max=s;
			if(buf[i]=='[')s++;
			else s--;
		}
		printf("%d %d\n",k,1<<max);
	}
	return 0;
}