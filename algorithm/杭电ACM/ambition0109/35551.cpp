////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-19 19:29:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3555
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

__int64 unans[23]={0,0,1,20,299,3970,49401,590040,6850999,
	77919950,872348501,9645565060,105583302099,1146187455930,
	12356291257201,132416725116080,1411810959903599,
	14985692873919910,158445117779295501};
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
					sum+=(num/ten[i]-49)/100*(ten[i]-unans[i]);
				}
			}else{
				sum+=((num/ten[i]-49)/100+1)*(ten[i]-unans[i]);
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
		//for(int i=0;i<19;i++){
		//	num=ten[i];
			__int64 temp=num;
			int len=0;
			while(temp){
				temp/=10;
				len++;
			}
			__int64 ans=Get(num,len);
			printf("%I64d\n",ans);
	/*	}*/
		//getchar();getchar();
	}/*getchar();*/

}