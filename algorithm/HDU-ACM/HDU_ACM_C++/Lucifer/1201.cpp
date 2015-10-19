////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-09 07:24:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1201
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int J(int y)
{
	if(((y%4==0)&&(y%100!=0))||(y%400==0))
		return 1;
	else 
		return 0;
}
int main()
{
	int t,y,m,d,s,i;
	cin>>t;
	while(t--)
	{
		scanf("%d-%d-%d",&y,&m,&d);
		if(m==2&&d==29&& !J(y+18))
			cout<<-1<<endl;
		else
		{
			s=0;
			if(!(m<=2 && d<=28))
				y++;
			for(i=0;i<18;i++)
				if(J(y+i))
					s++;
			s+=365*18;
			cout<<s<<endl;
		}
	}
	return 0;
}