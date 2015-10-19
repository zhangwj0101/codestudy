////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-09 18:27:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1907
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>  
int a[50];  
int main()  
{  
    int i,n,ans,l;  
    while (scanf("%d",&l)!=EOF)  
    {  
        while(l--)
        {
            scanf("%d",&n);
            ans=-1;  
            int temp = 0;  
            for (i=0;i<n;i++)  
            {  
                scanf("%d",&a[i]);  
                if (i == 0)  
                    ans = a[i];   
                else 
                    ans = ans^a[i];    //做异或运算  定理一（如下）
                if (a[i] > 1)        //标记a【i】是否全为1
                {  
                    temp = 1;  
                }  
            }  
            if (temp==0)           //全为1的情况
            {  
                if (n%2 == 1)  
                {  
                    printf("Brother\n");  
                }  
                else 
                {  
                    printf("John\n");  
                }  
                continue;  
            }  
            if (ans==0)        //不全为1的情况
                printf("Brother\n");   
            else 
                printf("John\n"); 
        }
    }  
    return 0;  
} 
