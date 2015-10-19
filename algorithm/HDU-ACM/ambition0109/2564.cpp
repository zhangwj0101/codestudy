////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-28 12:24:27
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2564
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
    int n,i;
    char str[201];
    for(scanf("%d",&n),getchar();n>0;n--)
    {
        gets(str);
        for(i=0;str[i]!='\0';i++)
		{
			if(str[i]!=' ')
			{
				if(str[i]<='z'&&str[i]>='a')
					str[i]-=32;
				printf("%c",str[i]);
				break;
			}
		}
        for(;str[i]!='\0';i++)
        {
            if(str[i]==' '&&str[i+1]!=' '&&str[i+1]!='\0')
            {
                if(str[i+1]<='z'&&str[i+1]>='a')
                    str[i+1]-=32;
                printf("%c",str[i+1]);
            }
        }
        printf("\n");
    }
}