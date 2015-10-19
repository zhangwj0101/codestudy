////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-04 16:46:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1256
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

void main()
{
    int n,wide,high,half,i,j;
    char ch;
    for(cin>>n;n>0;n--)
    {
		cin>>ch>>high;
        wide=(high+6)/6;
        half=(high-3)-(high-3)/2;
        for(i=wide;i>0;i--)
            printf(" ");
        for(i=half;i>0;i--)
            printf("%c",ch);
        printf("\n");
        for(i=high-3-half;i>0;i--)
        {
            for(j=wide;j>0;j--)
                printf("%c",ch);
            for(j=half;j>0;j--)
                printf(" ");
            for(j=wide;j>0;j--)
                printf("%c",ch);
            printf("\n");
        }
        for(i=wide;i>0;i--)
            printf(" ");
        for(i=half;i>0;i--)
            printf("%c",ch);
        printf("\n");
        for(i=half;i>0;i--)
        {
            for(j=wide;j>0;j--)
                printf("%c",ch);
            for(j=half;j>0;j--)
                printf(" ");
            for(j=wide;j>0;j--)
                printf("%c",ch);
            printf("\n");
        }
        for(i=wide;i>0;i--)
            printf(" ");
        for(i=half;i>0;i--)
            printf("%c",ch);
        printf("\n");
        if(n-1)
            printf("\n");
    }
}