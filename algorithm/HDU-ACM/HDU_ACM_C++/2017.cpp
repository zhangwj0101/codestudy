////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-04-26 20:00:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2017
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<cstring>
#include<cctype>
using namespace std;
int main()
{
	char str[100];
	int i,j,k,n;
   cin>>n;
   for(i=0;i<n;i++)
   {
	   k=0;
	   cin>>str;
	   for(j=0;j<strlen(str);j++)
		   if(isdigit(str[j]))   //isdigitÅÐ¶Ï×Ö·ûÊÇ·ñÎªÊý×Ö
			   k++;
		cout<<k<<endl;
   }
      
   return 0;
}

