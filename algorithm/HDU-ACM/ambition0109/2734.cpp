////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-22 19:05:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2734
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:140KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char str[260];
    while(gets(str),str[0]!='#'){
        int len=strlen(str);
        int Sum=0;
        for(int i=1;i<=len;i++){
            if(str[i-1]==' ') continue;
            Sum+=(str[i-1]-'A'+1)*i;
        }
        printf("%d\n",Sum);
    }
}