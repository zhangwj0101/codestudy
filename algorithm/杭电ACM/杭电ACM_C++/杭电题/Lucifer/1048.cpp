////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-17 18:28:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1048
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<cstring>
using namespace std;
const char c[3][16]={"START","END","ENDOFINPUT"};
int f(char a[])
{
	int i;
	for(i=0;i<3;i++)
			if(!strcmp(a,c[i]))
				return i;
	return -1;
}
int main()
{
	int f1=1,i;
	char a[201];
	while(gets(a))
	{
		if(f(a)==2)
			break;
		while(gets(a)&&(f(a)!=1))
		{
			for(i=0;i<strlen(a);i++)
			{
				if(isupper(a[i]))
					a[i]='A'+(a[i]-'A'+21)%26;
				if(islower(a[i]))
					a[i]='a'+(a[i]-'a'+21)%26;
			}
			cout<<a<<endl;
		}
	}
   return 0;
}