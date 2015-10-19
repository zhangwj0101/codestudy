////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-12 19:46:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3530
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:3032KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<list>
using namespace std;

int lMax,lMin;
int num[100001];
list<int> Max,Min;

int main()
{
	int n;
	while(scanf("%d%d%d",&n,&lMin,&lMax)!=EOF){
		Max.clear();
		Min.clear();
		int len=0;
		int s=0;
		for(int i=0;i<n;i++){
			scanf("%d",&num[i]);
			while(!Max.empty()&&num[i]>=num[Max.back()]){
				Max.pop_back();
			}
			while(!Min.empty()&&num[i]<=num[Min.back()]){
				Min.pop_back();
			}
			Max.push_back(i);
			Min.push_back(i);
			int dif=num[Max.front()]-num[Min.front()];
			while(dif>lMax){
				s++;
				if(Min.front()<s) Min.pop_front();
				if(Max.front()<s) Max.pop_front();
				dif=num[Max.front()]-num[Min.front()];
			}
			int ll=i-s+1;
			if(dif>=lMin&&ll>len) len=ll;
		}
		printf("%d\n",len);
	}
}