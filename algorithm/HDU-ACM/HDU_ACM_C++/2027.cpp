////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-06 17:34:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2027
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
int main()
{
    char s[100],o[5]={'a','e','i','o','u'};
    int i,j,n[26],t;
	scanf("%d",&t);
    getchar();
    for(i=0;i<t;i++)
    {
        gets(s);                   // ����һ���ַ��������Խ��տո�������������#include<cstring>��;cin.getline ����һ���ַ��������Խ��տո����
        for(j=0;j<26;j++)          //�ַ������ʼ��
            n[j]=0;
        for(j=0;j<strlen(s);j++)
        {
            if(isupper(s[j]))      //�ж��Ƿ�Ϊ��дӢ����ĸ  ,��д��Сд 
                s[j]+=32; 
            if(islower(s[j]))      //ÿ����ĸ���ֵĴ���
                n[s[j]-'a']++;
        }
        for(j=0;j<5;j++)
            cout<<o[j]<<":"<<n[o[j]-'a']<<endl;
        if(i<t-1)
            cout<<endl;
    }
   return 0;
}