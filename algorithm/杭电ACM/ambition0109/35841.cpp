////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-31 17:07:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3584
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:4688KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
#define Lowbit(x) (x&(-x))

int Index[105][105][105],n;
void Modify(int x,int y,int z,int Num)
{
for(int i=x;i<=n;i+=Lowbit(i)){
for(int j=y;j<=n;j+=Lowbit(j)){
for(int k=z;k<=n;k+=Lowbit(k)){
Index[i][j][k]+=Num;
}
}
}
}
int Sum(int x,int y,int z)
{
int result=0;
for(int i=x;i>0;i-=Lowbit(i)){
for(int j=y;j>0;j-=Lowbit(j)){
for(int k=z;k>0;k-=Lowbit(k)){
result+=Index[i][j][k];
}
}
}
return result;
}

int main()
{
int q;
while(scanf("%d%d",&n,&q)!=EOF){
memset(Index,0,sizeof(Index));
while(q--){
int cmd;
scanf("%d",&cmd);
if(cmd){
int x1,x2,y1,y2,z1,z2;
scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
Modify(x2+1,y2+1,z2+1,1);
Modify(x2+1,y2+1,z1,1);
Modify(x2+1,y1,z2+1,1);
Modify(x1,y2+1,z2+1,1);
Modify(x2+1,y1,z1,1);
Modify(x1,y2+1,z1,1);
Modify(x1,y1,z2+1,1);
Modify(x1,y1,z1,1);
}else{
int x,y,z;
scanf("%d%d%d",&x,&y,&z);
if(Sum(x,y,z)&1){
puts("1");
}else{
puts("0");
}
}
}
}
}