////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-29 10:17:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1047
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n,i;
	cin >> n;
	while(n)
	{
		int A[110];
		for(i = 0; i < 110;i++)
			A[i] = 0;
		char B[110];
		while(cin >> B)
		{
			int in = 109;
			for(int j = strlen(B) - 1; j >= 0;j--)
			{
				A[in] += B[j] - '0';
				if(A[in] > 9)
				{
					A[in] = A[in] - 10;
					A[in - 1] ++;
				}
				in--;
			}
			if(strlen(B) == 1&&B[0] == '0')
				break;

		}
		int k = 0;
		for(i = 0; i < 110;i++)
		if(A[i] != 0)
		{
			break;
		}
		if(i==110)
			cout<<0;
		else
		for(;i < 110 ; i++)
			cout << A[i];
		cout<<endl;
		if(--n > 0)
		cout << endl;
	}
	return 0;
}