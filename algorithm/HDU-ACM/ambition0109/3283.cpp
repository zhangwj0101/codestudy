////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-20 17:29:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3283
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:296KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;
void main()
{
	int t,n,is;
	string num;
	for(cin>>t;t>0;t--)
	{
		cin>>n>>num;
		for(int i=num.length()-2;i>=0;i--)
		{
			is=0;
			if(num[i]>=num[i+1])
				continue;
			else
			{
				is=1;
				for(int j=num.length()-1;j>i;j--)
					if(num[j]>num[i])
					{char tt=num[j];num[j]=num[i];num[i]=tt;break;}
				for(i+=1;i<num.length();i++)
					for(j=i+1;j<num.length();j++)
						if(num[j]<num[i])
						{char tt=num[j];num[j]=num[i];num[i]=tt;}
				break;
			}
		}
		if(is) cout<<n<<' '<<num<<endl;
		else cout<<n<<' '<<"BIGGEST"<<endl;
	}
}