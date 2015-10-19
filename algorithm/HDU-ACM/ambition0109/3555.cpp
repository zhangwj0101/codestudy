////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-19 17:05:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3555
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

//__int64 unans[23];
__int64 ten[23];
__int64 Get(__int64 num,int len)
{
	if(num==0) return 0;
	__int64 temp=num,sum=0;
	for(int i=len-2;i>=0;i--){
		if(num/ten[i]>=49){
			if(temp/ten[i]==49){
				if(i==0){
					sum+=(num/ten[i]-49)/100+1;
				}else{
					sum+=num%ten[i]-Get(num%ten[i],i)+1;
					sum+=(num/ten[i]-49)/100*(ten[i]-Get(ten[i],i));
				}
			}else{
				sum+=((num/ten[i]-49)/100+1)*(ten[i]-Get(ten[i],i));
			}
		}
		temp%=ten[i+1];
	}
	return sum;
}

int main()
{
	int n;
	scanf("%d",&n);
	ten[0]=1;
	for(int i=1;i<20;i++){
		ten[i]=ten[i-1]*10;
	}
	while(n--){
		__int64 num;
		scanf("%I64d",&num);
		__int64 temp=num;
		int len=0;
		while(temp){
			temp/=10;
			len++;
		}
		__int64 ans=Get(num,len);
		printf("%I64d\n",ans);
	}
}