////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-10 10:49:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1422
////Problem Title: 
////Run result: Accept
////Run time:250MS
////Run memory:768KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<vector>
using namespace std;

void main()
{
	int n;
	vector<int> num;
	while(cin>>n)
	{
		num.resize(n);
		for(int i=0;i<n;i++)
		{
			int in,out;
			scanf("%d%d",&in,&out);
			num[i]=in-out;
		}
		int start=0,end=0,tlen=0,len=0,tsum;
		for(int i=0;i<2*n;i++)
		{
			if(!len){
				if(num[i%n]>=0){
					tsum=num[i%n];
					tlen=len=1;start=i;end=i;
				}
			}else{
				tsum+=num[i%n];
				if(tsum<0){
					tlen=tsum=0;
					start=i+1;end=i+1;
				}else{
					end=i;
					tlen++;
				}
			}
			if(tlen>len) len=tlen;
			if(end-start+1>=n) break;
		}
		printf("%d\n",len);
	}
}