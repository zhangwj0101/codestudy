////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-02 08:26:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1200
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char s[201];
	char s2[100][20];//ע�ⷶΧ
	int c,l,i,j,k;
	while(cin>>c&&c)
	{
		cin>>s;
		l=strlen(s);
		i=k=0;
		while(k<l)
		{
			if((k/c)%2==0)
			for(j=0;j<c;j++)
				s2[i][j]=s[k++];
			else
			for(j=0;j<c;j++)
				s2[i][c-j-1]=s[k++];
			i++;
		}
		for(i=0;i<c;i++)
			for(j=0;j<l/c;j++)
				cout<<s2[j][i];
		cout<<endl;
	}
  return 0;
}