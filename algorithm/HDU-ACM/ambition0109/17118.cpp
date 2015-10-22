////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-22 18:56:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1711
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:4164KB
//////////////////System Comment End//////////////////
#include<cstdio>
#define MAXN 1000000
#define MAXM 10000
using namespace std;

inline void scan_d(int &num)
{
    char in;bool IsN=false;
    in=getchar();
    while(in!='-'&&(in<'0'||in>'9')) in=getchar();
    if(in=='-'){ IsN=true;num=0;}
    else num=in-'0';
    while(in=getchar(),in>='0'&&in<='9'){
        num*=10,num+=in-'0';
    }
    if(IsN) num=-num;
}

int Fail[MAXM+1];
int KMP(int numA[],int numB[],int n,int m){
    Fail[0]=-1;
    for(int i=1,j=-1;i<m;i++){
        while(j>=0&&numB[j+1]!=numB[i]){
            j=Fail[j];
        }
        if(numB[j+1]==numB[i])j ++;
        Fail[i]=j;
    }
    for (int i=0,j=0;i<n;i++){
        if(m-j>n-i) return -2;
        while(j&&numB[j]!=numA[i]){
            j=Fail[j-1]+1;
        }
        if(numB[j]==numA[i]) j++;
        if(j == m) return i-m+1;
    }
    return -2;
}

int nn[MAXN+1],mm[MAXM+1];
int main()
{
    int n,m,t;scan_d(t);
    while(t--){
        scan_d(n);scan_d(m);
        for(int i=0;i<n;i++){
            scan_d(nn[i]);
        }
        for(int i=0;i<m;i++){
            scan_d(mm[i]);
        }
        int ans=KMP(nn,mm,n,m);
        printf("%d\n",ans+1);
    }
}