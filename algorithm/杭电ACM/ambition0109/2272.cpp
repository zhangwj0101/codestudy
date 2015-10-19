////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-12 15:23:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2272
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<algorithm>
using namespace std;

inline int Abs(const int& num){
	int temp=(num>>31);
	return (num+temp)^temp;
}
int sco[105];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%*s %d",&sco[i]);
		}
		sort(sco,sco+n);
		int Sum=0;
		for(int i=0;i<n;i++){
			Sum+=Abs(sco[i]-i-1);
		}
			printf("%d\n",Sum);
	}

}
