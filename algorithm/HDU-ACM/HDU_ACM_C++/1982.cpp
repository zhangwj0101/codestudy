////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-24 23:15:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1982
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
    char s[10001];
    int t,sl,i,d;
    while(cin>>t)
    {
        while(t--)
        {
            cin>>s;
            sl=strlen(s);
            for(i=0;i<sl;)
            {
				if(!isdigit(s[i]))
				{
					if(s[i++]=='#')cout<<" ";
					continue;
				}
                for(d=0;isdigit(s[i])&&i<sl;i++)
                    d=d*10+s[i]-'0';
                cout<<(char)('A'+d-1);
            }
            cout<<endl;
        }
    }
  return 0;
}