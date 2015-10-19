////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-19 15:12:44
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1727
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:304KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int n;
	int i;
	int flag;
	int t[]={1,10,100,1000};
	char t1[][10]={"zero","one","two","three","four","five","six","seven","eight","nine",\
"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};
	char t2[][10]={"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
	char t3[][10]={"hundred","thousand"};
	while(scanf("%d",&n)!=EOF)
	{
		for(i=3;i>=0;i--)
			if(n/t[i])
				break;
		flag=0;
		if(i==3)
		{
			printf("%s thousand",t1[n/t[i]]);
			flag=1;
			for(n%=t[i--];!(n/t[i])&&i>=0;i--)n%=t[i];
		}
		if(i==2)
		{
			printf("%s",flag?" and ":"");
			printf("%s hundred",t1[n/t[i]]);
			flag=1;
			n%=t[i--];
		}
		if(n!=0)
		{
			if(((n-1)/t[1])<2)
			{
				printf("%s",flag?" and ":"");
				printf("%s",t1[n]);
			}
			else
			{
				printf("%s",flag?" and ":"");
				printf("%s",t2[n/t[1]]);
				n%=t[1];
				if(n!=0)
					printf("-%s",t1[n]);
			}
			flag=1;
		}
		puts(flag?"":t1[0]);
	}
	return 0;
}