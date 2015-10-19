////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-29 09:08:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2642
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:5196KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
#define Lowbit(x) (x&(-x))

int Index[1010][1010],N=1001;
bool map[1010][1010];
inline bool scan_ud(int &num)
{
    char in;
    in=getchar();
    if(in==EOF) return false;
    while(in<'0'||in>'9') in=getchar();
    num=in-'0';
    while(in=getchar(),in>='0'&&in<='9'){
        num*=10,num+=in-'0';
    }
    return true;
}

void Modify(int x,int y,int Num)
{
    for(int i=x;i<=N;i+=Lowbit(i)){
        for(int j=y;j<=N;j+=Lowbit(j)){
            Index[i][j]+=Num;
        }
    }
}
int Sum(int x,int y)
{
    int result=0;
    for(int i=x;i>0;i-=Lowbit(i)){
        for(int j=y;j>0;j-=Lowbit(j)){
            result+=Index[i][j];
        }
    }
    return result;
}

int main()
{
    int m;
    scanf("%d",&m);
    while(m--){
        char cmd[2];
        scanf("%s",cmd);
        if(cmd[0]=='Q'){
            int x1,x2,y1,y2;
            scan_ud(x1);
            scan_ud(x2);
            scan_ud(y1);
            scan_ud(y2);
            if(x1>x2){x1^=x2^=x1^=x2;}
            if(y1>y2){y1^=y2^=y1^=y2;}
            int sum;
            sum=Sum(x2+1,y2+1)-Sum(x2+1,y1)-Sum(x1,y2+1)+Sum(x1,y1);
            printf("%d\n",sum);
        }else if(cmd[0]=='B'){
            int x,y;
            scan_ud(x);
            scan_ud(y);
            if(map[x+1][y+1]){
                continue;
            }
            map[x+1][y+1]=true;
            Modify(x+1,y+1,1);
        }else if(cmd[0]=='D'){
            int x,y;
            scan_ud(x);
            scan_ud(y);
            if(!map[x+1][y+1]){
                continue;
            }
            map[x+1][y+1]=false;
            Modify(x+1,y+1,-1);
        }
    }
}