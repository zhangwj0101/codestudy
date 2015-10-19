////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-25 17:06:27
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3746
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:688KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

int Fail[100005];
void GetFail(char str[]){
    Fail[0]=-1;
    int len=strlen(str);
    for(int i=1,j=-1;i<len;i++){
        while(j>=0&&str[j+1]!=str[i]){
            j=Fail[j];
        }
        if(str[j+1]==str[i]) j++;
        Fail[i]=j;
    }
}

int KMP(char strA[],char strB[]){
    int lenA=strlen(strA);
    int lenB=strlen(strB);
    int j=0;
    for(int i=0;i<lenA;i++){
        while(j&&strA[i]!=strB[j]){
            j=Fail[j-1]+1;
        }
        if(strA[i]==strB[j]) j++;
        if((i!=lenA-1)&&j==lenB) j=Fail[j-1]+1;
    }
    return j;
}

char str[100005];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        int len=strlen(str);
        GetFail(str+1);
        int v=KMP(str+1,str);
        int Ans=len-2*v;
        if(Ans>=0) printf("%d\n",Ans);
        else{
            int vv;
            vv=len-2-Fail[len-2];
            while(vv+Ans<0){
                Ans+=vv;
            } 
            printf("%d\n",vv+Ans);
        }
    }
}