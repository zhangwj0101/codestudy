////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-15 20:02:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1715
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:324KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
const int M=210;
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
}hugeint[1002];
int main()
{
	int i,n,pi;
	hugeint[1].setValue(1);
	hugeint[2].setValue(1);
	for(i=3;i<1002;i++)
		hugeint[i]=hugeint[i-1]+hugeint[i-2];
	cin>>n;
	while(n--)
	{
		cin>>pi;
	hugeint[pi].print();
	cout<<endl;
	}
	return 0;
}