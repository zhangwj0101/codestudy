////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-08 20:15:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1002
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
void add(string &,  string &);
int main()
{ 
	for (int n; cin >> n;)
	{    
		int m = 0, k=1;    
		for (string s1, s2; n-- && cin >> s1 >> s2;)    
		{       cout << (m++ ? "\n" : "");
		        cout << "Case " << k++ << ":\n" << s1 << " + " << s2 << " = ";     
				string a(1000,'0');     
				add(a, s1);     
				add(a, s2);        
				reverse(a.begin(), a.end());       
				cout<<a.substr(a.find_first_not_of('0'))<<"\n"; 
       }
	} 
	return 0;
}
void add(string & a,  string & b)
{
	int temp = 0; 
	reverse(b.begin(),b.end()); 
	int k = b.length(); 
	for (int i = 0; i < k || temp ; i++)
	{    
		temp += (a[i]-'0') + (i < k) * (b[i]-'0');   
		a[i] = temp % 10 + '0'; 
		temp /= 10;
	}
}
