////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-26 08:16:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1036
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int calT(char s[8])
{
	int i;
	for(i=0;i<8;i++)
		s[i]-='0';
	return s[0]*3600+(s[2]*10+s[3])*60+s[5]*10+s[6];
}
int main()
{
	char s[8];
	int n,t,j,i;
	double d,sum;
	while(cin>>n>>d)
	{
		while(cin>>t)
		{
			sum=0;
			for(j=0;j<n;j++)
			{
				cin>>s;
				if(*s=='-')
				{
					sum=-1;
					break;
				}
				else
					sum+=calT(s);
			}
			for(i=j;i<n-1;i++)
				cin>>s;
			printf("%3d:",t);
			if(sum!=-1)
			{
				sum=sum/d+0.5;
				printf("%2d:%02d min/km\n",(int)sum/60,(int)sum%60);
			}
			else
				printf(" -\n");
		}
	}
    return 0;
}