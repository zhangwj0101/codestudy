////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-11 00:19:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1237
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:268KB
//////////////////System Comment End//////////////////
//10:45-11:16
#include <stdio.h>
#include<string.h>
#include <vector>
using namespace std;
void main()
{
	char str[201];
	vector<char> operStack;
	vector<double> oprdStack;
	double op1,op2,temp;
	char *token,c;
	while (gets(str))
	{
		if(!strcmp(str,"0"))
		{
			break;
		}
		token=strtok(str," ");
		sscanf(token,"%lf",&temp);
		oprdStack.push_back(temp);
		while(token=strtok(NULL," "))
		{
			switch (token[0])
			{
			case '+':
			case '-':
				operStack.push_back(token[0]);
				token=strtok(NULL," ");
				sscanf(token,"%lf",&op2);
				oprdStack.push_back(op2);
				break;
			case '*':
				op1=oprdStack.back();
				oprdStack.pop_back();
				token=strtok(NULL," ");
				sscanf(token,"%lf",&op2);
				oprdStack.push_back(op1*op2);
				break;
			case '/':
				op1=oprdStack.back();
				oprdStack.pop_back();
				token=strtok(NULL," ");
				sscanf(token,"%lf",&op2);
				oprdStack.push_back(op1/op2);
				break;
			}
		}
		op1=oprdStack.front();
		oprdStack.erase(oprdStack.begin());
		while(!operStack.empty())
		{
			op2=oprdStack.front();
			oprdStack.erase(oprdStack.begin());
			c=operStack.front();
			operStack.erase(operStack.begin());
			if (c=='+')
			{
				op1+=op2;
			}
			else
			{
				op1-=op2;
			}
		}
		printf("%.2lf\n",op1);

	}
}