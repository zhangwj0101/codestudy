////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-10-13 23:20:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1335
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	char str[80];
	char c2i[128];
	int i2c[16],i,in,out,len,s;
	for(i=0;i<10;i++)
	{
		c2i['0'+i]=i;
		i2c[i]='0'+i;
	}
	for(i=0;i<6;i++)
	{
		c2i['A'+i]=i+10;
		i2c[i+10]='A'+i;
	}
	while(scanf("%s%d%d",str,&in,&out)==3)
	{
		len=strlen(str);
		for(s=i=0;i<len;i++)
			s=s*in+c2i[str[i]];
		if(s>=(int)pow(1.0*out,7))
			puts("  ERROR");
		else
		{
			str[7]=0;
			if(s!=0)
			{
			for(i=6;s!=0;i--)
			{
				str[i]=i2c[s%out];
				s/=out;
			}
			}
			else
			{
				str[6]='0';
				i=5;
			}
			for(;i>=0;i--)
				str[i]=' ';
				
			puts(str);
		}
	}
	return 0;
}