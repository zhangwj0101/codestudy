////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-14 13:55:49
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2089
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:4124KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<stdlib.h>
int count[1000000];
main()
{
    int n,m,i,num,t;
    char str[7];count[0]=0;
	for(num=1;num<1000000;num++)
        {
            itoa(num,str,10);
            for(i=0,t=0;str[i]!='\0';i++)
                if(str[i]=='4'||(str[i]=='6'&&str[i+1]=='2'))
				{t=1;break;}
				if(t) count[num]=count[num-1];
				else count[num]=count[num-1]+1;
        }
    while(scanf("%d%d",&n,&m),m||n)
    {
        printf("%d\n",count[m]-count[n-1]);
    }
}