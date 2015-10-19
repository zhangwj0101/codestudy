////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-09 18:59:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1212
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:152KB
//////////////////System Comment End//////////////////
/*
 * 1212.cpp
 *
 *  Created on: 2010-7-9
 *      Author: ambition
 */

#include<cstdio>
using namespace std;

int main()
{
    int  n,i;
    char num[1001];
    while(scanf("%s %d",num,&n) != EOF)
    {
        int mod=0;
        for(i=0;num[i]!='\0';i++)
            mod=(mod*10+num[i]-'0')%n;
        printf("%d\n",mod);
    }
}
