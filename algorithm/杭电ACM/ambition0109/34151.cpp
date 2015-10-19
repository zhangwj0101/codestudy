////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-21 11:08:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3415
////Problem Title: 
////Run result: Accept
////Run time:562MS
////Run memory:3708KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<list>
using namespace std;

int num[100001];
int sum[200001];
list<int> Min;
void main()
{
    int t,n,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
		sum[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&num[i]);
			sum[i]=sum[i-1]+num[i];
		}
		for(int i=1;i<=n;i++)
			sum[n+i]=sum[n+i-1]+num[i];
        int max=-0x7fffffff,temp=0;
        int start=0,end=0;
		Min.clear();Min.push_back(0);
        for(int i=1;i<=2*n;i++)
        {
			if(i-Min.front()>k) Min.pop_front();
			temp=sum[i]-sum[Min.front()];
			if(temp>max){max=temp;start=Min.front()+1;end=i;}
			while(!Min.empty()&&sum[i]<=sum[Min.back()])
				Min.pop_back(); 
			Min.push_back(i);
        }
        printf("%d %d %d\n",max,start,(end-1)%n+1);
    }
}