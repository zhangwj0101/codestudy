////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-30 19:42:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2957
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
 
int main(){
        int n, t1, t2, t3;
        double sum, temp1, temp2;
        while(cin>>n>>t1>>t2>>t3 && (n||t1||t2||t3))
        {
                sum = 3 * n * n;
                sum += n * (n - 1) / 2;
                temp1 = t2 > t1 ? t2 - t1 : n - (t1 - t2);
                temp2 = t3 < t2 ? t2 - t3 : n - (t3 - t2);
                sum += n * (temp1+temp2);
                sum /= n;
                printf("%.3lf\n",sum);
        }
        return 0;
}