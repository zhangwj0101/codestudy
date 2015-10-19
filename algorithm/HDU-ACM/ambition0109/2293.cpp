////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-22 21:37:19
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2293
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:152KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

int GetHP(char str[]){
    int HP,len=strlen(str),tmp=0;
    for(int i=0;i<len;i++){
        tmp+=(83-str[i])*(83-str[i]);
        if(tmp>=97) tmp%=97;
    }
    HP=300-tmp;
    return HP;
}
int GetSTR(char str[])
{
    int STR,len=strlen(str),tmp=1;
    for(int i=0;i<len;i++){
        tmp*=str[i];
        if(tmp>=79) tmp%=79;
    }
    STR=22+tmp;
    return STR;
}
int GetSPD(char str[])
{
    int SPD,len=strlen(str),tmp=0;
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            tmp+=str[i]*str[j];
            if(tmp>=11) tmp%=11;
        }
    }
    SPD=tmp;
    return SPD;
}

int VS(char play1[],char play2[]){
    int hp1=GetHP(play1);
    int hp2=GetHP(play2);
    int str1=GetSTR(play1);
    int str2=GetSTR(play2);
    int spd1=20-GetSPD(play1);
    int spd2=20-GetSPD(play2);
    int t1=1,t2=1;
    while(true){
        if(t1*spd1<t2*spd2){
            hp2-=str1; t1++;
        }else if(t1*spd1>t2*spd2){
            hp1-=str2; t2++;
        }else{
            hp1-=str2; t2++;
            hp2-=str1; t1++;
        }
        if(hp1<=0&&hp2<=0) return 0;
        else if(hp1<=0) return -1;
        else if(hp2<=0) return 1;
    }
}

char P1[25],P2[25];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s %s",P1,P2);
        int ans=VS(P1,P2);
        if(ans==1) puts("win");
        else if(ans==-1) puts("lose");
        else puts("tie");
    }
}