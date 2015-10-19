////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-18 20:47:12
////Compiler: GUN C
//////////////////////////////////////////////////////
////Problem ID: 1861
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
void main()
{
    int rent[101];
    int id,hour,minute;
    double sum;
    char c;
    int k;
    while (1)
    {
        memset(rent,-1,sizeof(rent));
        sum=0;
        k=0;
        while (scanf("%d",&id),(id+1))
        {
            scanf(" %c %d:%d",&c,&hour,&minute);
            if (!id)break;
            if (c=='S')
                rent[id]=hour*60+minute;
            else if (rent[id]>=0)
            {
                sum+=(hour*60+minute-rent[id]);
                k++;
            }
        }
        if (id==-1)
            break;
        printf("%d %.lf\n",k,k?sum/k:0);
    }
}