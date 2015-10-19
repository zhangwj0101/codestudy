////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-04-26 21:14:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2019
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int n,m,s[100],k,i;
   cin>>n>>m;
   while(n!=0||m!=0)
   {
	   k=0;
		for(i=0;i<n;i++)     //数组赋值
			cin>>s[i];
		for(i=0;i<n;i++)     //寻找插入位置
			if(s[i]>m)
			{
				k=i;
				break;
			}
		if(k!=0)
		{                    //插入的不是最小值
			for(i=n;i>k;i--)
				s[i]=s[i-1];
		    s[k]=m;
		}
		else                  //插入的不是最小值
		{
			for(i=n;i>0;i--)
				s[i]=s[i-1];
			s[0]=m;
		}
		for(i=0;i<=n;i++)
		{
			cout<<s[i];
			if(i<n)
				cout<<" ";
		}
		cout<<endl;
		cin>>n>>m;
   }
      
   return 0;
}

