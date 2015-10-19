////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-06 18:56:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1236
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
struct R
{
	char n[21];
	int s;
}rec[1001];
int cmp(const void*a,const void *b)
{
	if((*(R*)a).s!=(*(R*)b).s)
		return (*(R*)b).s-(*(R*)a).s;
	else
		return strcmp((*(R*)a).n,(*(R*)b).n);
}
int main()
{
	int mark[10];
	int n,i,m,g,m1,t;
		while(cin>>n&&n)
		{
			cin>>m>>g;
			for(i=0;i<m;i++)
				cin>>mark[i];
			for(i=0;i<n;i++)
			{
				cin>>rec[i].n;
				rec[i].s=0;
				cin>>m1;
				while(m1--)
				{
					cin>>t;
					rec[i].s+=mark[t-1];
				}
			}
			qsort(rec,n,sizeof(R),cmp);
			for(i=0;i<n;i++)
				if(rec[i].s<g)
					break;
			n=i;
			cout<<n<<endl;
			for(i=0;i<n;i++)
				cout<<rec[i].n<<" "<<rec[i].s<<endl;
		}
	return 0;
}