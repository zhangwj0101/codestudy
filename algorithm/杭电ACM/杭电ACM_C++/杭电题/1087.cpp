////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-06 11:40:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1087
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>

#define size 1001

using namespace std;

//求最大上升子序列  的值

//直接将最大上升子序列  和保存到sum[]中


__int64 opt[size],sum[size],a[size],max1;

 

int main()

{

 int n,i,j;

 while(cin>>n&&n)

 { 

     for(i=1;i<=n;i++)

         scanf("%I64d",&a[i]);

     for(i=0;i<=n;i++) sum[i]=0;

     opt[1]=1;

 

     sum[1]=a[1];

    for(i=2;i<=n;i++)

    {max1=0;//max必须赋值为0

        for(j=1;j<i;j++)

        {if(a[i]>a[j])

           if(max1<sum[j])

           {max1=sum[j];

           }
        }//for j
      sum[i]=max1+a[i];

    }
    max1=0;
    for(i=1;i<=n;i++) if(sum[i]>max1) max1=sum[i];
    printf("%I64d\n",max1);

 }//while cin n
 return 1;

}
