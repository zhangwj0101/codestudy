////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-08-01 22:12:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1015
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int sl,tag;
int flag;
char p[6];
int cmb(char q[],char p[],int index)
{
	int i,j,f,sum,s,t;
	if(!index&&flag)
		return 1;
	else if(index<5)
	{
		for(i=0;i<sl;i++)
		{
			f=0;
			for(j=0;j<index;j++)
				if(p[j]==q[i])
				{
					f=1;
					break;
				}
			if(f)continue;
			if(flag)break;
			p[index]=q[i];
			cmb(q,p,index+1);
		}
	}
	else
	{
		for(sum=0,i=0;i<5;i++)
		{
			f=i%2?-1:1;
			t=p[i]-'A'+1;
			for(s=f,j=0;j<=i;j++)
				s*=t;
			sum+=s;
		}
		if(sum==tag)
			flag=1;
	}
}
int main()
{
	char q[13];
	int i,j;
	while(cin>>tag>>q)
	{
		if(!tag&&!strcmp(q,"END"))
			break;
		flag=0;
		sl=strlen(q);
		for(i=0;i<sl;i++)
			for(j=i+1;j<sl;j++)
				if(q[i]<q[j])
					swap(q[i],q[j]);
		cmb(q,p,0);
		puts(flag?p:"no solution");
	}
    return 0;
}