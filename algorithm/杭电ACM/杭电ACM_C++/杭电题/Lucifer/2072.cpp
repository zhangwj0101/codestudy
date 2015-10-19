////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-12 18:18:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2072
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#pragma warning (disable:4786)
#include<iostream>
#include<cctype>
#include<string>
#include<set>
using namespace std;
int main()
{
	set<string> sset;
	string ss;
    int i,sum;
    char s[200];
    while(cin.getline(s,200))
    {
		sset.clear();
        for(sum=i=0;(s[i]!=0)&&(s[i]!='#');)
        {
            while(islower(s[i]))
			{
				ss+=s[i];
				i++;
			}
            sset.insert(ss);
			ss="";
            while((s[i]==' ')&&(s[i]!='#'))i++;
        }
		if(s[i]!='#')
			cout<<sset.size()<<endl;
		else
			break;
   }
   return 0;
}