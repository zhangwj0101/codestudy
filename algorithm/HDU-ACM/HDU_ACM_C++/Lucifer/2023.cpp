////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-11 16:36:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2023
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
struct S
{
	int c[5];
	double aver;
}stu[50];
int main()
{
	double aver[5],ta;
    int n,m,i,j,t,k,f;
	while(cin>>n>>m)
	{
		for(i=0;i<m;i++)
			aver[i]=0;
		for(i=0;i<n;i++)
		{
			for(ta=j=0;j<m;j++)
			{
				cin>>t;
				stu[i].c[j]=t;
				aver[j]+=t;
				ta+=t;
			}
			stu[i].aver=ta/m;
		}
		for(i=0;i<m;i++)
		{
			aver[i]/=n;
		}
		for(k=i=0;i<n;i++)
		{
			f=1;
			for(j=0;j<m;j++)
			{
				if(stu[i].c[j]<aver[j])
				{
					f=0;
					break;
				}
			}
			if(f)
				k++;
		}
		for(i=0;i<n;i++)
		{
			printf("%.2lf",stu[i].aver);
			if(i<n-1)
				printf(" ");
		}
		printf("\n");
		for(i=0;i<m;i++)
		{
			printf("%.2lf",aver[i]);
			if(i<m-1)
				printf(" ");
		}
		printf("\n%d\n\n",k);
	}
   return 0;
}