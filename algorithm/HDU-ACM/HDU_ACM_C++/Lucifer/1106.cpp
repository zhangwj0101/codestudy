////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-12-02 00:15:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1106
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() 
{
    char str[1002];
    int k=0,m=0;
    __int64 array[1002],sum=0;
    fill(str,str+1002,'\0');

    while(cin>>str&&!cin.eof())
    {
        k=m=0;
        sum=0;
        str[strlen(str)]='5';
        str[strlen(str)+1]='\0';
        for(int i=0;i<=strlen(str);i++)
        {
            if(str[i]!='5')
            {
                sum=sum*10+str[i]-'0';
                m=1;
            }
            else
            {
                if(m==1)
                {
                    array[k]=sum;
                    sum=0;
                    m=0;
                    k++;
                }
            }
        }

        sort(array,array+k);
        for(i=0;i<k;i++)
        {
            printf("%I64d",array[i]);
            if(i<k-1) cout<<' ';
        }
        fill(str,str+1002,'\0');
        cout<<endl;
    }
    return 0;
}