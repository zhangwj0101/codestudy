////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-27 17:09:06
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 3351
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int main(void)
{
	int n=1,i,m,num;
	char str[2001];
	while(scanf("%s",&str),str[0]!='-')
	{
		num=0;
		for(i=0,m=0;str[i]!='\0';i++)
		{
			if(str[i]=='{')
				m+=1;
			else if(str[i]=='}')
				m-=1;
			if(m<0)
			{
				m+=2;
				str[i]='{';
				num+=1;
			}
		}
		for(i=i-1,m=0;i>=0;i--)
		{
			if(str[i]=='{')
				m-=1;
			else if(str[i]=='}')
				m+=1;
			if(m<0)
			{
				m+=2;
				str[i]='}';
				num+=1;
			}
		}
		printf("%d. %d\n",n,num);
		n++;
	}
	return 0;
}