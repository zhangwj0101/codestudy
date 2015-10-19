////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-21 19:58:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3402
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:640KB
//////////////////System Comment End//////////////////
/*
 * 3402.cpp
 *
 *  Created on: 2010-10-21
 *      Author: administrator
 */

#include<cstdio>
#include<algorithm>
using namespace std;

int num[100010];
int main()
{
	int t;
    scanf("%d",&t);
    while(t--){
    	int n,r;
        scanf("%d%d",&n,&r);
        for(int i=0;i<n;i++){
            scanf("%d",&num[i]);
        }
        sort(num,num+n);
        int max=0;
        for(int i=1;i<n;i++){
        	if(num[i]-num[i-1]>max){
        		max=num[i]-num[i-1];
        	}
        }
        if(max==0) puts("Inf");
        else{
        	double Ans=6.28318531*(double)r/(double)(n*max);
        	printf("%.3lf\n",Ans);
        }
    }
}
