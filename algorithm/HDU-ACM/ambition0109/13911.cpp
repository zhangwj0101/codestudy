////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-29 19:40:46
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1391
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int main()
{
	int t;scanf("%d",&t);
	while(t--){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==b||a-2==b){
			if(a&1) printf("%d\n",a+b-1);
			else printf("%d\n",a+b);
		}else printf("No Number\n");
	}
}