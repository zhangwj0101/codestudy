////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-02 11:47:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1496
////Problem Title: 
////Run result: Accept
////Run time:203MS
////Run memory:8124KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<memory>
using namespace std;

int hush[2000001];
int pow2[101];
void main()
{
	int a,b,c,d,i,j,count;
	for(i=1;i<=100;i++)
		pow2[i]=i*i;
	while(cin>>a>>b>>c>>d)
	{
		if(a>0&&b>0&&c>0&&d>0){ cout<<0<<endl;continue;}
		if(a<0&&b<0&&c<0&&d<0){ cout<<0<<endl;continue;}
		memset(hush,0,sizeof(hush));
		for(i=1;i<=100;i++)
			for(j=1;j<=100;j++)
				hush[a*pow2[i]+b*pow2[j]+1000000]+=1;
		for(i=1,count=0;i<=100;i++)
			for(j=1;j<=100;j++)
				count+=hush[-c*pow2[i]-d*pow2[j]+1000000];
		cout<<count*16<<endl;
	}
}