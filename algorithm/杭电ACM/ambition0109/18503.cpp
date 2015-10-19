////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-09 21:09:43
////Compiler: GUN C
//////////////////////////////////////////////////////
////Problem ID: 1850
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:172KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int num[100];
main()
{
    int m,i,xor,t,count;
    while(scanf("%d",&m),m){
        for(count=0,i=0,xor=0;i<m;i++){
            scanf("%d",&num[i]);
            xor^=num[i];
        }
        if(xor)
        {
            for(t=1;xor!=1;t<<=1)
				xor>>=1;
            for(i=0;i<m;i++){
                if(num[i]&t){
					count++;
				}
            }
        }
        printf("%d\n",count);
    }
}