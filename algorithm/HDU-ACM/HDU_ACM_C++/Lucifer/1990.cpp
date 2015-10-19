////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-11-09 19:29:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1990
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int m,i,k,n,a=0;
    char s[160];
    cin>>n;getchar();
    while(n--){
        gets(s);
        for(i=m=k=0;i<strlen(s);i++){
            if(k>m) m=k;
            if(s[i]=='[') k++;
            else k--;
        }
        a++;
        cout<<a<<" "<<(int)pow(2,m)<<endl;
    }
    return 0;
}