////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2009-01-08 14:44:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2549
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int t,n,i;
	char f[100],ct;
	cin>>t;
	while(t--)
	{
		memset(f,0,sizeof(f));
		scanf("%s%d",f,&n);
		for(i=0;f[i]!='.';i++);
		ct=f[i+n];
		if(!ct)ct='0';
		printf("%c\n",ct);
	}
	return 0;
}