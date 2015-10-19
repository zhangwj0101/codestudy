////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-10 18:11:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1319
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:56KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
const int M=32678; 
int pp[M]={0,1,1};
int p[10000]={1,2},N;
int cmp(const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int main()
{
    int i,j,c,*it,num;
	int n,t1,t2,tn;
    for(i=3,N=2;i<M;i+=2)
    {
        for(j=2;j<=sqrt(1.0*i);j++)
            if(i%j==0)
                break;
        if(j>sqrt(1.0*i))
        {
            p[N++]=i;
            pp[i]=1;
        }
    }
    while(cin>>n>>c)
    {
		for(tn=n;tn;tn--)
			if(pp[tn])
				break;
		it=(int*)bsearch(&tn,p,N,sizeof(int),cmp);
		num=it-p+1;
		cout<<n<<" "<<c<<":";
		if(num<=2*c)
		{
			for(i=0;i<num;i++)
				cout<<" "<<p[i];
		}
		else
		{
		if(num%2)
		{
			t1=num/2-c+1;
			t2=num/2+c-1;
		}
		else
		{
			t1=num/2-c;
			t2=num/2+c-1;
		}
		for(i=t1;i<=t2;i++)
			cout<<" "<<p[i];
		}
		cout<<endl<<endl;
    }
    return 0;
}