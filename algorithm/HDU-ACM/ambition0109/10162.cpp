////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-23 15:47:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1016
////Problem Title: 
////Run result: Accept
////Run time:296MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<list>
using namespace std;

bool num[21];
list<int> ring;
int prime[11]={3,5,7,11,13,17,19,23,29,31,37};
int n,count;
bool isprime(int num)
{
	for(int i=0;i<11;i++)
		if(prime[i]==num) return true;
	return false;
}
void Dfs(int pre)
{
	if(count==n){
		if(isprime(pre+1)){
			printf("1");
			list<int>::iterator iter=ring.begin();
			iter++;
			while(iter!=ring.end())
				printf(" %d",*iter++);
			printf("\n");
		}
		return;
	}
	if(pre&1){
		for(int i=2;i<=n;i+=2){
			if(num[i]&&isprime(i+pre)){
				ring.push_back(i);
				num[i]=false;
				count++;
				Dfs(i);
				count--;
				num[i]=true;
				ring.pop_back();
			}
		}
	}else{
		for(int i=3;i<=n;i+=2){
			if(num[i]&&isprime(i+pre)){
				ring.push_back(i);
				num[i]=false;
				count++;
				Dfs(i);
				count--;
				num[i]=true;
				ring.pop_back();
			}
		}
	}
}
void main()
{
	int c=0;
	while(scanf("%d",&n)!=EOF){
		if(n&1){
			printf("Case %d:\n\n",++c);
			continue;
		}
		ring.clear();
		ring.push_back(1);
		memset(num,true,sizeof(num));
		num[1]=false;
		count=1;
		printf("Case %d:\n",++c);
		Dfs(1);
		printf("\n");
	}
}