////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-02 14:09:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1004
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:448KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;

int hash[5002];
string T[5002];
int ELFhash(string str)
{
	unsigned long h=0,g;
	for(int i=0;str[i];i++)
	{
		h=(h<<4)+str[i];
		i++;
		g=h&0xf0000000L;
		if(g)h^=g>>24;
		h&=~g;
	}
	h%=5001;
	return h;
}

void main()
{
	string temp;
	int i,max,t,n;
	while(cin>>n,n)
	{
		memset(hash,0,sizeof(hash));
		for(i=0,max=0;i<n;i++)
		{
			cin>>temp;
			t=ELFhash(temp);
			while(hash[t]&&T[t]!=temp)
			{t++;t%=5001;}
			hash[t]++;
			T[t]=temp;
			if(hash[t]>hash[max])
				max=t;
		}
		cout<<T[max]<<endl;
	}
}