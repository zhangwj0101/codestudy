////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-23 17:51:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1718
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int id,mark,jack,i,jm,n,k;
	short s[1001];
	while(cin>>jack)
	{
		for(n=0;cin>>id>>mark;n++)
		{
			if(!id||!mark)
				break;
			if(id==jack)
				jm=mark;
			s[n]=mark;
		}
		for(k=i=0;i<n;i++)
			if(s[i]>jm)
				k++;
		cout<<k+1<<endl;
    }
    return 0;
}