////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2009-05-10 16:49:02
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2816
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:176KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
char trans[10][6]={"",""," ABC"," DEF"," GHI"," JKL"," MNO"," PQRS"," TUV"," WXYZ"};
char trans2[]="KXVMCNOPHQRSZYIJADLEGWBUFT";
void main()
{
	int sl,i,sl2;
	char str[1000],str2[1000],tc;
	while (scanf("%s",str)==1)
	{
		sl=strlen(str)/2;
		for(i=0;i<sl;i++)
		{
			str[i]=trans[str[2*i]-'0'][str[2*i+1]-'0'];
		}
		str[i]=0;

		sl=strlen(str);
		for (i=0;i<sl;i++)
		{
			str[i]=trans2[str[i]-'A'];
		}

		sl2=(sl+1)/2;
		for (i=0;i<sl2;i++)
		{
			str2[2*i]=str[i];
			str2[2*i+1]=str[i+sl2];
		}

		str2[sl]=0;

		for (i=0;i<sl/2;i++)
		{
			tc=str2[i];
			str2[i]=str2[sl-i-1];
			str2[sl-i-1]=tc;
		}

		puts(str2);
	}
}