////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-02 20:44:03
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1228
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
void main()
{
	char trans[10][6]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	char temp[8];
	char str[80];
	char result[20];
	char *p;
	int i,k,a,b;
	while(1)
	{
		gets(str);
		p=str;
		k=0;
		while(sscanf(p,"%s",temp)==1)
		{
			if (temp[0]=='=')
			{
				break;
			}
			else if (temp[0]=='+')
			{
				result[k++]='+';
			}
			else
			{
				for (i=0;i<10;i++)
				{
					if (!strcmp(temp,trans[i]))
					{
						result[k++]='0'+i;
						break;
					}
				}
			}
			p+=strlen(temp)+1;
		}
		result[k]=0;
		sscanf(result,"%d+%d",&a,&b);
		if (a==0&&b==0)
		{
			break;
		}
		printf("%d\n",a+b);
		

	}
}

