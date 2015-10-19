////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-07 07:11:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1265
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
//³­µÄ
#include<iostream>
using namespace std;
int main()
{
	int n,t,i,p;
	unsigned int e ,m[23];
	float f;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%f",&f);
		for(i=0;i<23;i++)
			m[i]=0;
		if(f<0)
		{	t=0x80000000;f=-f;}
		else
		{
			t=0;
			if(f==0)
			{	printf("%X\n",t);continue;}
		}
		e=0;
		for(e=0;f>=2;f/=2,e++);
		e+=127;
		f--;
		i=0;
		while(f>0 && i<23)
		{
			f*=2;
			if(f>=1)
			{	m[i]=1;f--;}
			else
				m[i]=0;
			i++;
		}
		e<<=23;
		t=t | e;
		p=0x400000;
		for(i=0;i<23;i++,p>>=1)
			if(m[i])
				t= t | p;
		printf("%X\n",t);
	}
	return 0;
}
