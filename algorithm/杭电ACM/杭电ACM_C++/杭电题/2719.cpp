////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2009-03-28 11:25:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2719
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:172KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	char input[80],output[240];
	int sl,i,j;
	while(gets(input))
	{
		if(input[0]=='#')
			break;
		sl=strlen(input);
		for(j=i=0;i<sl;i++)
		{
			switch(input[i])
			{
			case ' ':
			case '!':
			case '$':
			case '%':
			case '(':
			case ')':
			case '*':
				sprintf(output+j,"%%%x",input[i]);
				j+=3;
				break;
			default:
				output[j++]=input[i];
			}	
		}
		output[j]=0;
		puts(output);
	}
	return 0;
}