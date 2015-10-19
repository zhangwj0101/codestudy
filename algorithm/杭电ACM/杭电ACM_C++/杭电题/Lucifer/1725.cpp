////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-19 18:35:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1725
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <algorithm>
using namespace std;
unsigned int temp,n1[14]={1};
int main()
{
	int n,m;
	int i;
	int sum,a;
	scanf("%d",&n);
	for(temp=i=1;i<14;i++)
	{
		n1[i]=temp;
		temp*=i;
	}
	while(n--)
	{
		sum=0;
		scanf("%d",&m);
		for(i=13;m/n1[i]==0;i--);
		while(m>0)
		{
			a=m/n1[i];
			sum+=a;
			m%=n1[i];
			i--;
		}
		printf("%d\n",sum);
	}
	return 0;
}