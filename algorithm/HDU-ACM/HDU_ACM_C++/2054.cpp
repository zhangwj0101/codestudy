////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-13 00:20:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2054
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:40KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

void A(char *s)
{
    int len = strlen(s);
    char *p = s + len - 1;
    if (strchr(s, '.'))
    while (*p == '0') *p-- = 0;
    if (*p == '.') *p = 0;
}
int main(void)
{
    char *pa, *pb;
    char a[100024], b[100024];

    while (scanf("%s%s", &a, &b) != EOF)
    {
        pa = a; pb = b;
        while (*pa == '0') pa++;
        while (*pb == '0') pb++;
        A(pa); A(pb);
        puts(strcmp(pa, pb) ? "NO" : "YES");
    }

    return 0;
}