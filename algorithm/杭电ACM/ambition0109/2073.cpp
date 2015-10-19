////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-21 15:16:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2073
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:608KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

const double sqrtt=1.4142135623730951;
double length[201][201];
void main()
{
	int n,x1,x2,y1,y2;
	length[0][0]=0.0;double max=0.0;
	for(int i=1;i<=200;i++)
	{
		length[0][i]=max+sqrt((double)(i*i+(i-1)*(i-1)));
		max=length[0][i];
		for(int j=1;j<=i;j++)
		{
			length[j][i-j]=max+sqrtt;
			max=length[j][i-j];
		}
	}
	for(cin>>n;n>0;n--)
	{
		cin>>x1>>y1>>x2>>y2;
		printf("%.3lf\n",fabs(length[x2][y2]-length[x1][y1]));
	}
}