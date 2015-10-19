////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-26 10:55:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2099
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int s[101],a,b,k,i,j,k1;
	while(cin>>a>>b&&(a||b))
	{
		for(k=0,i=0;i<b;i++)
			if((a*100+i)%b==0)
				s[k++]=i;
		for(k1=k,i=0;i<k;i++)
		{
			for(j=1;s[i]+j*b<100;j++)
				s[k1++]=s[i]+j*b;
		}
		k=k1;
		printf("%02d",s[0]);
		for(i=1;i<k;i++)
			printf(" %02d",s[i]);
		puts("");
	}
    return 0;
}