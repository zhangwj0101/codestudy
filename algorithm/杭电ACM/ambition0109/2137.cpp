////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-13 20:18:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2137
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
int times(int n)
{
    n%=8;
    if(n<0)
        n+=8;
    return n;//返回真正需要旋转的次数，把所有情况归结到0-7
}//没有大数的陷阱，题目没说清楚，要多考虑负数（也就是clockwise）
void Circumgyrate(char *a,int n)
{
    int len=strlen(a),i;
    switch(n)
    {
    case 0:
        {
            puts(a);
            break;
        }
    case 1:
        {
            for(i=len-1;i>=0;i--)
                printf("%*c\n",i+1,a[i]);
            break;
        }
    case 2:
        {
            for(i=len-1;i>=0;i--)
                printf("%*c\n",(len>>1)+1,a[i]);
            break;
        }
    case 3:
        {
            for(i=len-1;i>=0;i--)
                printf("%*c\n",len-i,a[i]);
            break;
        }
    case 4:
        {
            for(i=len-1;i>=0;i--)
                printf("%c",a[i]);
            printf("\n");
            break;
        }
    case 5:
        {
            for(i=0;i<len;i++)
                printf("%*c\n",len-i,a[i]);
            break;
        }
    case 6:
        {
            for(i=0;i<len;i++)
                printf("%*c\n",(len>>1)+1,a[i]);
            break;
        }
    case 7:
        {
            for(i=0;i<len;i++)
                printf("%*c\n",i+1,a[i]);
            break;
        }
    }
}//分情况打印，没什么，主要是那个带*号的，可以使得域宽随i变化，就是多加个变量作为参数
int main()
{
    char a[90];
    int n;
    while(scanf("%s",a)==1)
    {
        scanf("%d",&n);
        Circumgyrate(a,times(n));
    }
    return 0;
}
//Accepted 2137 31MS 0K 1025 B C++