////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-29 18:54:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2689
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int num[1001];
int main()
{
	int n;
	while(cin>>n){
		int count=0;
		for(int i=0;i<n;i++)
			cin>>num[i];
		for(int i=0;i<n-1;i++){
			for(int j=n-1;j>i;j--){
				if(num[j]<num[j-1]){
					num[j-1]^=num[j];num[j]^=num[j-1];num[j-1]^=num[j];
					count++;
				}
			}
		}
		printf("%d\n",count);
	}
}