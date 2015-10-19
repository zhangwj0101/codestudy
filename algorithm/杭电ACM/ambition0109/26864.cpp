////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-19 12:48:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2686
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<memory>
using namespace std;

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

int map[31][31];
int value[2][31][31];
void main()
{
    int n;int T,B;
    while(scan_ud(n))
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                scan_ud(map[i][j]);
                value[0][i][j]=value[1][i][j]=0;
            }
        value[0][1][2]=map[1][1]+map[2][1]+map[1][2];
        T=1;B=0;
        for(int i=2;i<n;i++){
            B=T;T^=1;
            for(int j=1;j<=i;j++){
                for(int k=j+1;k<=i;k++){
                    if(value[T][j][k]+map[j][i-j+2]+map[k][i-k+2]>value[B][j][k])
                        value[B][j][k]=value[T][j][k]+map[j][i-j+2]+map[k][i-k+2];
                    if(value[T][j][k]+map[j][i-j+2]+map[k+1][i-k+1]>value[B][j][k+1])
                        value[B][j][k+1]=value[T][j][k]+map[j][i-j+2]+map[k+1][i-k+1];
                    if(value[T][j][k]+map[j+1][i-j+1]+map[k+1][i-k+1]>value[B][j+1][k+1])
                        value[B][j+1][k+1]=value[T][j][k]+map[j+1][i-j+1]+map[k+1][i-k+1];
                    if(j!=k-1)
                        if(value[T][j][k]+map[j+1][i-j+1]+map[k][i-k+2]>value[B][j+1][k])
                            value[B][j+1][k]=value[T][j][k]+map[j+1][i-j+1]+map[k][i-k+2];
                }
            }
        }
        for(int i=n+1;i<=2*n-2;i++){
            B=T;T^=1;
            for(int j=i-n+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    int max=value[T][j][k];
                    if(value[T][j-1][k-1]>max) max=value[T][j-1][k-1];
                    if(value[T][j-1][k]>max) max=value[T][j-1][k];
                    if(j!=k-1) if(value[T][j][k-1]>max) max=value[T][j][k-1];
                    value[B][j][k]=max+map[j][i-j+1]+map[k][i-k+1];
                }
            }
        }
        printf("%d\n",value[B][n-1][n]+map[n][n]);
    }
}