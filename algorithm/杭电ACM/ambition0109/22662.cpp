////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-22 21:05:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2266
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
int cnt;
char str[15],len;
__int64 Ans;
void Dfs(__int64 Sum,__int64 num,int t)
{
    if(t==len){
        Sum+=num;
        if(Sum==Ans) cnt++;
        return;
    }
    if(num>=0){
        Dfs(Sum,num*10+str[t]-'0',t+1);
    }else{
        Dfs(Sum,num*10-str[t]+'0',t+1);
    }
    Dfs(Sum+num,str[t]-'0',t+1);
    Dfs(Sum+num,-(str[t]-'0'),t+1);
}

int main()
{
    
    while(scanf("%s %I64d",str,&Ans)!=EOF){
        cnt=0;
        len=strlen(str);
        Dfs(0,str[0]-'0',1);
        printf("%d\n",cnt);
    }
}