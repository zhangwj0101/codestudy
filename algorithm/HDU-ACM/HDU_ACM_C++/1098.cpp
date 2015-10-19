////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-19 11:20:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1098
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<cstdio>
int main()
{int a,k,f;while(scanf("%d",&k)==1){for(f=0,a=1;a<65;a++)if((k*a+18)%65==0){f=1;break;}if(f)printf("%d\n",a);else printf("no\n");}return 0;}