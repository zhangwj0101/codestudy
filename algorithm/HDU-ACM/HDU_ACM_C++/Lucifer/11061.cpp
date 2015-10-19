////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-12-02 00:23:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1106
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	char buf[1010];
	int num[1001],t,sl,i,count;
	while(gets(buf))
	{
	sl=strlen(buf);
	buf[sl]='5';
	sl++;
	count=t=0;
	for(i=0;i<sl;i++)
	{
		if(buf[i]!='5')
		{
			t=t*10+(buf[i]-'0');
			
		}
		else
		{
			if(i>0)
			if(buf[i-1]!='5')
			{
			num[count++]=t;
			t=0;
			}
		}
	}
	sort(num,num+count);
	for(i=0;i<count;i++)
	{
		printf("%s%d",i?" ":"",num[i]);
	}
	puts("");
	}
    return 0;
}