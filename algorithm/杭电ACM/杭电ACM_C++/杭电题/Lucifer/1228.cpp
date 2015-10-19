////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-04-25 09:07:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1228
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string>
using namespace std;
int trans(string a)
{
	if(a=="zero")
		return 0;
	else if(a=="one")
		return 1;
	else if(a=="two")
		return 2;
	else if(a=="three")
		return 3;
	else if(a=="four")
		return 4;
	else if(a=="five")
		return 5;
	else if(a=="six")
		return 6;
	else if(a=="seven")
		return 7;
	else if(a=="eight")
		return 8;
	else if(a=="nine")
		return 9;
	else if(a=="+")
		return 10;
	else if(a=="=")
		return 11;
	return -1;
}
int main()
{
   string a;
   int a1=0,a2=0,t;
   while(true)
   {
	  a1=0,a2=0;
	  while(true)
	  {
		  cin>>a;
		  while(((t=trans(a))!=10)&&((t=trans(a))!=11))
		  {
			  a1=a1*10+t;
			  cin>>a;
		  }
		  if(t==11)
			  break;
		  else
		  {
			  cin>>a;
			while(((t=trans(a))!=11))
			{
				a2=a2*10+t;
				cin>>a;
			}
			break;
		  }
			
	  }
    if(a1+a2==0)
		break;
	else
		cout<<a1+a2<<endl;
   }
	  return 0;
}

