////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-25 17:18:41
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2919
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<stdlib.h>
main()
{
	int num[2],i,j,t;
	char str[100],sum[10];
	char temp[10][4]={"063","010","093","079","106","103","119","011","127","107"};
	while(gets(str))
	{
		if(str[0]=='B')if(str[1]=='Y')if(str[2]=='E')if(str[3]=='\0') break;
		num[0]=0;num[1]=0;
		for(i=0,t=0;;i++)
		{
			if(str[i]<='9'&&str[i]>='0')
			{
				for(j=0;j<10;j++)
					if(str[i]==temp[j][0])
						if(str[i+1]==temp[j][1])
							if(str[i+2]==temp[j][2])
							{num[t]*=10;num[t]+=j;i+=2;break;}
			}
			else if(str[i]=='+')
				t=1;
			else if(str[i]=='=')
				break;
		}
		itoa(num[0]+num[1],sum,10);
		printf("%s",str);
		for(i=0;sum[i]!='\0';i++)
			printf("%s",temp[sum[i]-'0']);
		printf("\n");
	}
}