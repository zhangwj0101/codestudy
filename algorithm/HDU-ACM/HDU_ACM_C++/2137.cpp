////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-14 11:59:24
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2137
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include"stdio.h"
#include"string.h"
const int T[3]={1,10,100};
void main()
{
    char a[81],s[1000];
    int i,len1,l2,j,n,b;
    while(scanf("%s",a)!=EOF && scanf("%s",s)!=EOF)
    {
        getchar();
        len1=strlen(a);
		l2=strlen(s);
		for(n=0,i=l2-1;i>=0&&l2-i<=3;i--)
			n+=(s[i]-48)*T[l2-i-1];
        n%=8;
        switch(n)
        {
        case 0: puts(a);  break;
        case 1:
            for(j=len1-1;j>=0;j--)
            {
                for(i=1;i<=j;i++)
                    printf(" ");
                printf("%c\n",a[j]);
            }
            break;
        case 2:
            b=len1/2;
            for(j=len1-1;j>=0;j--)
            {
                for(i=0;i<b;i++)
                    printf(" ");
                printf("%c\n",a[j]);
            }
            break;
        case 3:
            for(j=len1-1;j>=0;j--)
            {
                for(i=1;i<=len1-1-j;i++)
                    printf(" ");
                printf("%c\n",a[j]);
            }
            break;
        case 4:
            for(j=len1-1;j>=0;j--)
                printf("%c",a[j]);
            printf("\n");
            break;
        case 5:
            for(j=0;j<len1;j++)
            {
                for(i=1;i<=len1-1-j;i++)
                    printf(" ");
                printf("%c\n",a[j]);
            }
            break;
        case 6:
            b=len1/2;
            for(j=0;j<len1;j++)
            {
                for(i=0;i<b;i++)
                    printf(" ");
                printf("%c\n",a[j]);
            }
            break;
        case 7:
            for(j=0;j<len1;j++)
            {
                for(i=1;i<=j;i++)
                    printf(" ");
                printf("%c\n",a[j]);
            }
            break;
        }
    }
}