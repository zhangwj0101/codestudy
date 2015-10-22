////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-10 21:32:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1297
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:324KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
#define DIGIT	4
#define DEPTH	10000
#define MAX     100
typedef int bignum_t[MAX+1];

void init(bignum_t a,int b)
{
	int i;
	for(i=0;b>0;i++)
	{
		a[i+1]=b%DEPTH;
		b/=DEPTH;
	}
	a[0]=i?i:1;
	while(i<=MAX)
		a[++i]=0;
}

void write(const bignum_t a,ostream& os=cout){
	int i,j;
	for (os<<a[i=a[0]],i--;i;i--)
		for (j=DEPTH/10;j;j/=10)
			os<<a[i]/j%10;
	os<<endl;
}

void add(bignum_t a,const bignum_t b){
	int i;
	for (i=1;i<=b[0];i++)
		if ((a[i]+=b[i])>=DEPTH)
			a[i]-=DEPTH,a[i+1]++;
	if (b[0]>=a[0])
		a[0]=b[0];
	else
		for (;a[i]>=DEPTH&&i<a[0];a[i]-=DEPTH,i++,a[i]++);
	a[0]+=(a[a[0]+1]>0);
}

int main()
{
    bignum_t a[1001];
    int i,n;
	init(a[0],1);
	init(a[1],1);
	init(a[2],2);
	init(a[3],4);
	for(i=4;i<=1000;i++)
	{
		memcpy(a[i],a[i-1],sizeof(bignum_t));
		add(a[i],a[i-2]);
		add(a[i],a[i-4]);
	}
    while(scanf("%d",&n)==1)
		write(a[n]);
   return 0;
}