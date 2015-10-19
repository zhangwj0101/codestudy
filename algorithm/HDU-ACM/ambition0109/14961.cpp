////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-02 11:54:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1496
////Problem Title: 
////Run result: Accept
////Run time:875MS
////Run memory:15964KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<memory>
using namespace std;

int hush1[2000001],hush2[2000001];
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
		memset(hush1,0,sizeof(hush1));
		memset(hush2,0,sizeof(hush2));
		for(i=1;i<=100;i++)
			for(j=1;j<=100;j++)
			{
				hush1[a*pow2[i]+b*pow2[j]+1000000]+=1;
				hush2[-c*pow2[i]-d*pow2[j]+1000000]+=1;
			}
		for(i=0,count=0;i<2000001;i++)
			count+=hush1[i]*hush2[i];
		cout<<count*16<<endl;
	}
}