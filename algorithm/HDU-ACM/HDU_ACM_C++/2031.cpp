////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-02 15:48:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2031
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
const char d[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};  //ÔËÓÃÇÉÃî
int main()
{
	int n,r,k;
	char s[100];
    while(cin>>n>>r)
    {
		if(n<0)
		{
			n*=-1;
			cout<<'-';
		}
		for(k=0;n>0;n/=r)
			s[k++]=d[n%r];    //ºÜÇÉÃî
		while(--k>=0)
			cout<<s[k];
		cout<<endl;
    }
   return 0;
}