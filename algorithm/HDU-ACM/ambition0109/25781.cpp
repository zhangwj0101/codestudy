////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-22 22:15:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2578
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:292KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<algorithm>
using namespace std;

inline void scan_ud(int &num)
{
        char in;
        in=getchar();
        while(in<'0'||in>'9') in=getchar();
        num=in-'0';
        while(in=getchar(),in>='0'&&in<='9'){
                num*=10,num+=in-'0';
        }
}

int num[100010];
bool Find(int val,int n)
{
    int top=0,bot=n;
    int mid=(top+bot)>>1;
    int ans=mid;
    while(top<=bot){
        if(num[mid]>=val){
            bot=(ans=mid)-1;
        }else{
            top=mid+1;
        }
        mid=(top+bot)>>1;
    }
    return (num[ans]==val);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++){
            scan_ud(num[i]);
        }
        sort(num,num+n);
        int m=0;
        for(int i=1;i<n;i++){
            if(num[m]!=num[i]){
                num[++m]=num[i];
            }
        }
        int cnt=0;
        for(int i=0;i<=m;i++){
            if(k-num[i]<num[i]) break;
            else if(k-num[i]==num[i]) cnt++;
            else{
                if(Find(k-num[i],m)){
                    cnt+=2;
                }
            }
        }
        printf("%d\n",cnt);
    }
}