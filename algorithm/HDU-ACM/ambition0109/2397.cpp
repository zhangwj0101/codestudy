////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-08 19:46:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2397
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

struct Word{
    char str[100];
    void set(char ns[]){
        int i;
        for(i=0;ns[i];i++){
            str[i]=ns[i];
        }
        str[i]='\0';
    }
    void Format(){
        int len=strlen(str);
        for(int i=0;i<len;i++){
            if(str[i]<='z'&&str[i]>='a'){
                str[i]-=32;
            }else if(str[i]=='\''){
                char tmp[100];
                strcpy(tmp,str+i+1);
                strcpy(str+i,tmp);
                len--; i--;
            }
        }
    }
}words[110];
map<string,bool> Hash;


bool cmp(const Word& a,const Word& b){
    if(strcmp(a.str,b.str)<0) return true;
    else return false;
}

int main(){
    char tmp[100],stmp[10000];
    int t=0,cas=0;
    Hash.clear();
    scanf("%[^a-zA-Z]",stmp);
    bool flag1=true,flag2;
    while(true){
    	scanf("%[a-zA-Z\']",tmp);
    	scanf("%[^a-zA-Z]",stmp);
    	if(flag1&&strstr(stmp,"\n")) flag2=true;
    	else flag2=false;
    	if(stmp[strlen(stmp)-1]=='\n') flag1=true;
    	else flag1=false;
        if(flag2&&(strcmp(tmp,"EOT")==0||strcmp(tmp,"EOD")==0)){
            Hash.clear();
            sort(words,words+t,cmp);
            printf("WORDS IN DOCUMENT #%d\n",++cas);
            for(int i=0;i<t;i++){
                printf("%s\n",words[i].str);
            }
            t=0;
            if(strcmp(tmp,"EOT")==0){
                break;
            }
        }else{
            words[t].set(tmp);
            words[t].Format();
            if(!Hash[words[t].str]){
                Hash[words[t].str]=true;
                t++;
            }
        }
    }
}
