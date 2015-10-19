////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-22 20:55:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1867
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:768KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
#define max 100002
char a[max],b[max];
int fail[max];

void getfail(char str[])
{
        int m=strlen(str);
        fail[0]=-1;
        for(int i=1,j=-1;i<m;i++)
        {
                while(j>0 && str[j+1]!=str[i])
                        j=fail[j];
                if(str[j+1]==str[i])        j++;
                fail[i]=j;
        }
}
int kmp(char A[], char B[])
{
        getfail(B);
        int n=strlen(A);
        int m=strlen(B);
        int i,j;
        for(i=0,j=0;i<n;i++)
        {
                while(j>0 && A[i]!= B[j])
                        j=fail[j-1]+1;
                if(A[i]==B[j])        j++;
                if(i!=n-1 && j==m)  j=fail[j-1]+1;
        }
        return j;
}

int main()
{
        while(scanf("%s%s",a,b) != EOF)
        {
                int n1=kmp(a,b),n2=kmp(b,a);
                if(n1>n2)
                        printf("%s%s\n",a,b+n1);
                else if(n1<n2)
                        printf("%s%s\n",b,a+n2);
                else
                {
                        if(strcmp(a,b) < 0)
                                printf("%s%s\n",a,b+n1);
                        else
                                printf("%s%s\n",b,a+n2);
                }
        }
        return 0;
}