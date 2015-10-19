////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-11 11:49:54
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2097
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<stdlib.h>

int T[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
main()
{
    int num,sum,temp,i,j;
    char str[10];
    while(scanf("%d",&num),num)
    {
        itoa(num,str,10);
        for(i=0,sum=0;str[i]!='\0';i++)
        {
            for(j=0;j<10;j++)
                if(str[i]==T[j])
                {sum+=j;break;}
        }
        itoa(num,str,12);
        for(i=0,temp=0;str[i]!='\0';i++)
        {
            for(j=0;j<12;j++)
                if(str[i]==T[j])
                {temp+=j;break;}
        }
        if(temp!=sum) {printf("%d is not a Sky Number.\n",num);continue;}
        itoa(num,str,16);
        for(i=0,temp=0;str[i]!='\0';i++)
        {
            for(j=0;j<16;j++)
                if(str[i]==T[j])
                {temp+=j;break;}
        }
        if(temp!=sum) {printf("%d is not a Sky Number.\n",num);continue;}
        printf("%d is a Sky Number.\n",num);
    }
}