////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-29 18:56:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2689
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
inline bool scan_ud(int &num)
{
	char in;
	in=getchar();
	if(in==EOF) return false;
	while(in<'0'||in>'9') in=getchar();
	num=in-'0';
	while(in=getchar(),in>='0'&&in<='9'){
		num*=10,num+=in-'0';
	}
	return true;
}
int num[1001];
int main()
{
	int n;
	while(scan_ud(n)){
		int count=0;
		for(int i=0;i<n;i++)
			scan_ud(num[i]);
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