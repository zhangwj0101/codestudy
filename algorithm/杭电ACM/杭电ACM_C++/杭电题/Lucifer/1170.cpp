////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-06 16:43:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1170
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char o;
	int i,a,b,s,t,f;
	double s1;
	cin>>t;
	for(i=0;i<t;i++)
	{
		f=0;
		cin>>o>>a>>b;
		switch(o)
		{
		case '+':
			s=a+b;break;
		case '-':
			s=a-b;break;
		case '*':
			s=a*b;break;
		case '/':
			if(a%b==0)
				s=a/b;
			else
			{
				s1=1.0*a/b;
				f=1;
			}
		}
		if(f)
			printf("%.2f\n",s1);
		else
			printf("%d\n",s);
	}
	return 0;
}