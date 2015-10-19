////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-05 17:25:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2030
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int i,j,l,sum;
	char s[200],n[2];
	cin.getline(n,80);
	for(i=0;i<*n-'0';i++)
	{
		cin.getline(s,200);
		l=strlen(s);
		for(sum=0,j=0;j<l;j++)
			if(s[j]<0)
				sum++;
		cout<<sum/2<<endl;
	}
   return 0;
}