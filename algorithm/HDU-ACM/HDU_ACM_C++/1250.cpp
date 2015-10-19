////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-15 20:15:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1250
////Problem Title: 
////Run result: Accept
////Run time:484MS
////Run memory:27444KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
const int M=2006;
class HugeInt
{
public:
	void setValue(long value)
	{
		int i;
	for(i=0;i<M;i++)
	{
		integer[i]=0;
	}
	for(i=M-1;(value!=0)&&(i>=0);i--)
	{
		integer[i]=value%10;
		value/=10;
	}
	}
	void setValue(const char *string)
	{
		int i,j,length,k;
	for(i=0;i<M;i++)
		integer[i]=0;
	length=strlen(string);
	for(j=M-length,k=0;j<M;j++)
	{
		if(isdigit(string[k]))
			integer[j]=string[k]-'0';
	}
	}
	void print()
	{
	int i;
	for(i=0;(integer[i]==0)&&(i<M);i++);
	if(i==M)
		cout<<0;
	else
		for(;i<M;i++)
			cout<<integer[i];
	}
   HugeInt( const char *string)
   {
	   setValue(string);
   }
   HugeInt()
   {}
   HugeInt operator+( const HugeInt &op2 ) const
	{
	HugeInt temp;
	int carry=0,i;
	for(i=M-1;i>=0;i--)
	{
		temp.integer[i]=this->integer[i]+op2.integer[i]+carry;
		if(temp.integer[i]>9)
		{
			temp.integer[i]-=10;
			carry=1;
		}
		else
			carry=0;
	}
	return temp;
	}
   HugeInt operator+( const char *op2)
	{
	return *this+HugeInt(op2);
	}
   short integer[M];
}hugeint[7100];
int main()
{
	int i,pi,max;
	for(i=1;i<=4;i++)
		hugeint[i].setValue(1);
	max=4;
	while(cin>>pi)
	{
		if(pi>max)
		{
		for(i=max+1;i<=pi;i++)
			hugeint[i]=hugeint[i-1]+hugeint[i-2]+hugeint[i-3]+hugeint[i-4];
		max=pi;
		}
		hugeint[pi].print();
		cout<<endl;
	}
	return 0;
}