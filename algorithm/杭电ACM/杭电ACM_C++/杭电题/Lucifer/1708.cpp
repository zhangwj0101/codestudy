////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-16 07:17:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1708
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
void count(char str[],int num[])
{
    int i,sl;
    sl=strlen(str);
    memset(num,0,104);
    for(i=0;i<sl;i++)
        num[str[i]-'a']++;
}
int main()
{
    char str1[31],str2[31];
    int num1[26]={0},num2[26]={0},n,k,i,j,a,b,c;
    cin>>n;
    while(n--)
    {
        cin>>str1>>str2>>k;
        count(str1,num1);
        count(str2,num2);
        for(i=0;i<26;i++)
        {
            a=num1[i];
            b=num2[i];
            for(j=1;j<k;j++)
            {
                c=a+b;
                a=b;
                b=c;
            }
			if(k==0)
				c=a;
			if(k==1)
				c=b;
            printf("%c:%d\n",'a'+i,c);
        }
		puts("");
    }
    return 0;
}