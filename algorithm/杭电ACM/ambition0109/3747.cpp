////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-25 17:11:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3747
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;

int n;
char s[60],t[60];
int cmp(char s1[],char s2[]){
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s1[i]!=s2[i]){
            cnt++;
        }
    }
    return cnt;
}

int Getall(){
    char ans[60];
    for(int i=0;i<n;i++){
        ans[i]='1';
    }
    ans[n]='\0';
    return cmp(ans,t);
}

int Getnon(){
    char ans[60];
    for(int i=0;i<n;i++){
        ans[i]='0';
    }
    ans[n]='\0';
    return cmp(ans,t);
}

int Getre(){
    char ans[60];
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            ans[i]='0';
        }else{
            ans[i]='1';
        }
    }
    ans[n]='\0';
    return cmp(ans,t);
}

int main(){
    while(~scanf("%d",&n)){
        scanf("%s",s);
        scanf("%s",t);
        int Min=50;
        int tcnt;
        tcnt=cmp(s,t);
        if(tcnt<Min) Min=tcnt;
    //    printf("== %d\n",tcnt);
        tcnt=Getall()+1;
        if(tcnt<Min) Min=tcnt;
    //    printf("== %d\n",tcnt);
        tcnt=Getre()+1;
    //    printf("== %d\n",tcnt);
        if(tcnt<Min) Min=tcnt;
        tcnt=Getnon()+2;
    //    printf("== %d\n",tcnt);
        if(tcnt<Min) Min=tcnt;
        printf("%d\n",Min);
    }
}