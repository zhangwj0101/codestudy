////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-25 09:36:37
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2523
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
#include<memory.h>
int num[1000],hash[2001];
void main()
{
    int n,m,t,i,j,k;
    for(scanf("%d",&n);n>0;n--)
    {
		memset(hash,0,sizeof(hash));
        for(scanf("%d%d",&m,&k),i=0;i<m;i++){
            scanf("%d",&num[i]);
            for(j=0;j<i;j++){
                t=abs(num[i]-num[j]);
                hash[t]=1;
            }
        }
        for(i=0,t=0;i<2001;i++){
            if(hash[i])    t++;
            if(t==k)    {printf("%d\n",i);break;}
        }
    }
}