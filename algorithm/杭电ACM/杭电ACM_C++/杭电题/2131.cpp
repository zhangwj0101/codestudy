////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-14 11:15:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2131
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
    char str[201],t;
	int i,k,l;
    while(cin>>t>>str)
    {
        l=strlen(str);
		t=tolower(t);
        for(k=0,i=0;i<l;i++)
            if(tolower(str[i])==t)
                k++;
        printf("%.5lf\n",1.0*k/l);
    }
    return 0;
}