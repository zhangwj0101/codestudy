////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-06 00:22:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1860
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
    int i,j,cs[5],cl,sl;
	char s[200],c[5];
	while(cin.getline(c,200))
	{
		if(*c=='#')
			break;
		else
		{
			cl=strlen(c);
			cin.getline(s,200);
			sl=strlen(s);
			for(i=cl;i<5;i++)
				c[i]=0;
			for(i=0;i<5;i++)
				cs[i]=0;
			for(i=0;i<sl;i++)
			{
				for(j=0;j<cl;j++)
					if(s[i]==c[j])
					{
						cs[j]++;
						continue;
					}
			}
			for(i=0;i<cl;i++)
				cout<<c[i]<<" "<<cs[i]<<endl;
		}
   }
   return 0;
}