////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-06 16:29:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1062
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
int main()
{
    char t[1000],ct;
    int n,i,j,l,j1,j2;
    scanf("%d",&n);
	getchar();
    for(i=0;i<n;i++)
    {
       gets(t);
       l=strlen(t);
        for(j1=j=0;j<l;j++)
        {
            while(t[j]!=' '&&t[j]!=0)
				j++;
			j2=j-1;
			while(j1<j2)
			{
				ct=t[j1];
				t[j1]=t[j2];
				t[j2]=ct;
				j1++;
				j2--;
			}
			while(t[j]==' ')j++;
			j1=j;
        }
		puts(t);
    }
    return 0;
}