////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-15 12:07:56
////Compiler: GUN C
//////////////////////////////////////////////////////
////Problem ID: 1228
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>
const char trans[][6]={"zero","one","two","three","four","five",
	"six","seven","eight","nine","+","="};
int main(int argc, char *argv[])
{
	char str[80];
	char *p;
	int num[2];
	int i,j;
	while(gets(str))
	{
		p=strtok(str," ");
		j=0;
		num[0]=num[1]=0;
		do
		{
			for(i=0;i<12;i++)
			{
				if(!strcmp(p,trans[i]))
				{
					if(i<10)
					{
						num[j]=num[j]*10+i;
					}
					else if(i==10)
						j++;
					
					break;
				}
			}
		}while(p=strtok(NULL," "));
		if((num[0]==0)&&(num[1]==0))
			break;
		else
			printf("%d\n",num[0]+num[1]);
	}
  	return 0;
}
