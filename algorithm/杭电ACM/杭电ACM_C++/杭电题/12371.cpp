////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-17 12:09:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1237
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:332KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<vector>
using namespace std;
double cal(double a,double b,char op)
{
	switch(op)
	{
		case '*':return a*b;
		case '/':return a/b;
		case '+':return a+b;
		case '-':return a-b;
	}
}
int main()
{
	vector<double> oprd;
	vector<char> oper;
	
	char str[201];
	char *p,c;
	double op1,op2;
	while(gets(str),strcmp(str,"0"))
	{
		p=strtok(str," ");
		sscanf(p,"%lf",&op1);
		oprd.push_back(op1);
		while(p=strtok(NULL," "),p)
		{
			c=*p;
			p=strtok(NULL," ");
			sscanf(p,"%lf",&op2);
			switch(c)
			{
				case '*':
				case '/':
					op1=oprd.back();
					oprd.back()=cal(op1,op2,c);
					break;
				default:
					oper.push_back(c);
					oprd.push_back(op2);
					break;
			}
		}

		while(!oper.empty())
		{
			op1=oprd.front();
			oprd.erase(oprd.begin());
			op2=oprd.front();
			c=oper.front();
			oper.erase(oper.begin());
			oprd.front()=cal(op1,op2,c);
		}
		printf("%.2lf\n",oprd.front());
		oprd.erase(oprd.begin());
	}
	return 0;
}