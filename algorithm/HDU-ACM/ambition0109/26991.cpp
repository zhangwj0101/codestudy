////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-22 16:53:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2699
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:152KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

int wnum,bnum;
char map[18][18];
bool Check(bool wb){
    int wn,bn;
    for(int i=0;i<10;i++){
        for(int j=0;j<15;j++){
            wn=0;bn=0;
            for(int k=0;k<5;k++){
                if(map[i+k][j]=='W') wn++;
                if(map[i+k][j]=='B') bn++;
            }
            if(wb&&bn==4&&wn==0) return true;
            if((!wb)&&bn==0&&wn==4) return true;
            wn=0;bn=0;
            for(int k=0;k<5;k++){
                if(map[j][i+k]=='W') wn++;
                if(map[j][i+k]=='B') bn++;
            }
            if(wb&&bn==4&&wn==0) return true;
            if((!wb)&&bn==0&&wn==4) return true;
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            wn=0;bn=0;
            for(int k=0;k<5;k++){
                if(map[i+k][j+k]=='W') wn++;
                if(map[i+k][j+k]=='B') bn++;
            }
            if(wb&&bn==4&&wn==0) return true;
            if((!wb)&&bn==0&&wn==4) return true;
            wn=0;bn=0;
            for(int k=0;k<5;k++){
                if(map[i+k][j+5-k]=='W') wn++;
                if(map[i+k][j+5-k]=='B') bn++;
            }
            if(wb&&bn==4&&wn==0) return true;
            if((!wb)&&bn==0&&wn==4) return true;
        }
    }
    return false;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        wnum=0;bnum=0;
        for(int i=0;i<15;i++){
            scanf("%s",map[i]);
            for(int j=0;j<15;j++){
                if(map[i][j]=='W') wnum++;
                if(map[i][j]=='B') bnum++;
            }
        }
        puts(Check(wnum==bnum)?"YES":"NO");
    }
}