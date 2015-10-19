////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-07 14:00:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2119
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:324KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
double Matrix[101][101];
unsigned Mn,Mm;
int Rank;

void GetRank()
{
	unsigned is,js,nn;
	double d,q;
	nn=Mn>Mm?Mm:Mn;
	Rank=0;
	for(unsigned l=0;l<nn;l++)
	{
		q=0.;
		for(unsigned i=l;i<Mn;i++)
			for(unsigned j=l;j<Mm;j++)
			{
				d=fabs(Matrix[i][j]);
				if(d>q) {q=d;is=i;js=j;}
			}
		if(q==0) break;
		Rank=Rank+1;
		if(js!=l)
			for(unsigned i=l;i<Mn;i++)
			{double t=Matrix[i][l];Matrix[i][l]=Matrix[i][js];Matrix[i][js]=t;}
		if(is!=l)
			for(unsigned j=l;j<Mm;j++)
			{double t=Matrix[l][j];Matrix[l][j]=Matrix[is][j];Matrix[is][j]=t;}
		for(unsigned i=l+1;i<Mn;i++)
			for(unsigned j=l+1;j<Mm;j++)
			{
				d=Matrix[i][l]*Matrix[l][j]/Matrix[l][l];
				Matrix[i][j]=Matrix[i][j]-d;
			}
	}
}
void main()
{
	while(cin>>Mn,Mn)
	{
		cin>>Mm;
		for(unsigned i=0;i<Mn;i++)
			for(unsigned j=0;j<Mm;j++)
				cin>>Matrix[i][j];
		GetRank();
		cout<<Rank<<endl;
	}
}