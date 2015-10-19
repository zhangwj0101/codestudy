////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-27 10:25:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1702
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int main()
{
	char cmd[5],cmd2[4];
	int n,f,op,c;
	cin>>c;
	while(c--)
	{
		cin>>n;
		cin>>cmd;
		f=(cmd[2]=='F')?1:0;
		if(f)
		{
			queue<int> q1;
			while(n--)
			{
				cin>>cmd2;
				if(*cmd2=='I')
				{
					cin>>op;
					q1.push(op);
				}
				else
				{
					if(q1.empty())
						puts("None");
					else
					{
						cout<<q1.front()<<endl;
						q1.pop();
					}
				}
			}
		}
		else
		{
			stack<int> s1;
			while(n--)
			{
				cin>>cmd2;
				if(*cmd2=='I')
				{
					cin>>op;
					s1.push(op);
				}
				else
				{
					if(s1.empty())
						puts("None");
					else
					{
						cout<<s1.top()<<endl;
						s1.pop();
					}
				}
			}
		}
	}
	return 0;
}