////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-12 16:59:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2073
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
#define P(x) ((x)*(x))
using namespace std;
const double sq2=sqrt(2.0); 
double p[201]={0};
int main()
{
	int i,n,x[2],y[2],m[2];
	double s[2];
	for(i=1;i<201;i++)
		p[i]=p[i-1]+sqrt(1.0*(P(i-1)+P(i)))+(i-1)*sq2;
	cin>>n;
	while(n--)
	{
		for(i=0;i<2;i++)
		{
			cin>>x[i]>>y[i];
			m[i]=x[i]+y[i];
			s[i]=sqrt(1.0*(P(x[i])+P(y[i]-m[i])))+p[m[i]];
		}
		s[0]-=s[1];
		if(s[0]<0)
			s[0]*=-1;
		printf("%.3lf\n",s[0]);
	}
	return 0;
}