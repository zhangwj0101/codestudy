////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-22 20:31:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2714
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:152KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

char str[15];
int main()
{
    while(scanf("%s",str)!=EOF){
        int len=strlen(str);
        int Sum=0,pos;
        for(int i=0;i<len;i++){
            if(str[i]=='?'){
                pos=i;
                continue;
            }else if(str[i]=='X'){
                Sum+=10*(10-i);
            }else{
                Sum+=(str[i]-'0')*(10-i);
            }
        }
        if(pos==9){
            if(((1*10+Sum)%11)==0){
                puts("X");
                continue;
            }
        }
        int i;
        for(i=0;i<10;i++){
            if(((10-pos)*i+Sum)%11==0){
                printf("%d\n",i);
                break;
            }
        }
        if(i==10){
            puts("-1");
            continue;
        }
    }
}