////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-08 21:01:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1202
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int main()
{
   int i,sub;
   float score,allgpa,credit,allcredit;
   while(scanf("%d",&sub)!=EOF){
   allgpa=0;
   allcredit=0;
   for(i=0;i<sub;i++){
     scanf("%f%f",&credit,&score);
     if(score!=-1){
         allcredit+=credit;
         if(score==100) allgpa+=credit*4;
         else if(score>59)allgpa+=credit*((int)score/10-5);
     }
   }
   if(allcredit==0)printf("-1\n");
   else printf("%.2f\n",allgpa/allcredit);
}
   return 0;
}