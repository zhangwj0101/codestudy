////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-30 16:33:09
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2069
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:356KB
//////////////////System Comment End//////////////////
/*
 * 2069.cpp
 *
 *  Created on: 2010-6-30
 *      Author: ambition
 */

#include<iostream>
using namespace std;

int main()
{
	int n,a,b,c,d,count;
	while(cin>>n)
	{
		for(a=0,count=0;a<=n/50;a++)
			for(b=0;b<=(n-50*a)/25;b++)
				for(c=0;c<=(n-25*b-50*a)/10;c++)
					for(d=0;d<=(n-10*c-25*b-50*a)/5;d++)
						if(a+b+c+d+(n-5*d-10*c-25*b-50*a)<=100)
							count++;
		cout<<count<<endl;
	}
}
