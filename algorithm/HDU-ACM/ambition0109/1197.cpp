////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-10 19:55:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1197
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:180KB
//////////////////System Comment End//////////////////
/*
 * 1197.cpp
 *
 *  Created on: 2010-7-10
 *      Author: ambition
 */

#include<cstdio>
#include<cstdlib>
using namespace std;

char T[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
int main()
{
    int num,sum,temp,i,j;
    char str[10];
    for(num=2992;num<10000;num++)
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
        if(temp!=sum) continue;
        itoa(num,str,16);
        for(i=0,temp=0;str[i]!='\0';i++)
        {
            for(j=0;j<16;j++)
                if(str[i]==T[j])
                {temp+=j;break;}
        }
        if(temp!=sum) continue;
        printf("%d\n",num);
    }
}
