////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-06 18:27:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1034
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

__int64 num[100000];
__int64 half[100000];
int main()
{
	int n;
	while(scanf("%d",&n),n){
		for(int i=0;i<n;i++){
			scanf("%I64d",&num[i]);
		}
		__int64 cnt=0,ans=num[0];
		int t;
		for(t=1;t<n;t++){
			if(num[t]!=ans){
				break;
			}
		}
		//if(t==n){
		//	printf("%I64d %I64d\n",0LL,ans);
		//	continue;
		//}
		while(1){
			cnt++;
			for(int i=0;i<n;i++){
				half[i]=num[i]>>1;

			}
			bool tof=true;
			ans=num[0]=half[0]+half[n-1];
			if(num[0]&1){
				num[0]++;
				ans++;
			}
			for(int i=1;i<n;i++){
				num[i]=half[i]+half[i-1];
				if(num[i]&1){
					num[i]++;
				}
				if(ans!=num[i]){
					tof=false;
				}
			}
			if(tof) break;
			
		}
		printf("%I64d %I64d\n",cnt,ans);
	}
}