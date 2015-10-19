////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-15 16:14:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2164
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int t,p1,p2,n;
	char a,b;
	cin>>t;
	while(t--)
	{
		p1=p2=0;
		scanf("%d",&n);
		while(n--)
		{
			getchar();
			scanf("%c %c",&a,&b);
			if(a!=b)
			switch(a)
			{
			case 'R':
				if(b=='P')
					p2++;
				else
					p1++;
				break;
			case 'P':
				if(b=='S')
					p2++;
				else
					p1++;
				break;
			case 'S':
				if(b=='R')
					p2++;
				else
					p1++;
				break;
			}
		}
		if(p2==p1)puts("TIE");
		else printf("Player %d\n",(p2>p1)+1);
	}
	return 0;
}