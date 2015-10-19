////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-11-09 19:32:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1990
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main(){
    int m,i,k,n,a=0;
    char s[160];
    cin>>n;getchar();
    for(a=1;a<=n;a++)
    {
        gets(s);
        for(i=m=k=0;i<strlen(s);i++){
            if(k>m) m=k;
            if(s[i]=='[') k++;
            else k--;
        }
        cout<<a<<" "<<(1<<m)<<endl;
    }
    return 0;
}