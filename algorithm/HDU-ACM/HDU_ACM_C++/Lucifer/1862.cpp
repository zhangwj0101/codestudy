////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-12-01 23:15:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1862
////Problem Title: 
////Run result: Accept
////Run time:1062MS
////Run memory:1812KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
struct SCO
{
    int id;
    char n[9];
    int s;
}s[100001];
int (*cmp)(const void *a,const void *b);
int cmp1(const void *a,const void *b)
{
    return ((SCO*)a)->id-((SCO*)b)->id;
}
int cmp2(const void *a,const void *b)
{
    if(strcmp(((SCO*)a)->n,((SCO*)b)->n))
        return strcmp(((SCO*)a)->n,((SCO*)b)->n);
    else
        return ((SCO*)a)->id-((SCO*)b)->id;
}
int cmp3(const void *a,const void *b)
{
    if(((SCO*)a)->s!=((SCO*)b)->s)
        return ((SCO*)a)->s-((SCO*)b)->s;
    else
        return ((SCO*)a)->id-((SCO*)b)->id;
}
int main()
{
    int n,c,i,j=0;
    while(scanf("%d%d",&n,&c),n)
    {
        for(i=0;i<n;i++)
            scanf("%d%s%d",&s[i].id,s[i].n,&s[i].s);
        switch(c)
        {
        case 1:
            cmp=cmp1;
            break;
        case 2:
            cmp=cmp2;
            break;
        case 3:
            cmp=cmp3;
            break;
        }
        qsort(s,n,sizeof(SCO),cmp);
        printf("Case %d:\n",++j);
        for(i=0;i<n;i++)
            printf("%06d %s %d\n",s[i].id,s[i].n,s[i].s);
    }
    return 0;
}