////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-13 23:32:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2161
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
//#include <ctime>
#include<iostream>
using namespace std;
//clock_t timeRecord;
const int MAX_NUM=16000;
//std::bitset<MAX_NUM+1> notPrime;
//int notPrime[MAX_NUM+1];
//char notPrime[MAX_NUM+1];
bool notPrime[MAX_NUM+1];
void fGetPrime(){
    int i, j;
    for(i = 2; i*i <= MAX_NUM; i++)
    {
        if( notPrime[i] )
            continue;
        for(j = i + i; j <= MAX_NUM; j += i)
                notPrime[j] = 1;
    }
}
int main()
{
    int n,i=1;
//    printf("Generate all prime numbers not greater than %d\n", MAX_NUM);
//    printf("Start time record:\n");
//  timeRecord = clock();
    fGetPrime();
    notPrime[1]=1;
    notPrime[2]=1;
//    printf("Time Cost : %ld (ms)\n", clock() - timeRecord);
//    printf("Stop  time record:\n");
    cin>>n;
    while(n>0)
    {
        cout<<i++;
        if(notPrime[n])
            cout<<": no";
        else
            cout<<": yes";
        cout<<endl;
        cin>>n;
    }
    return 0;
}