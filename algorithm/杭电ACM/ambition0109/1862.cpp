////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-29 19:01:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1862
////Problem Title: 
////Run result: Accept
////Run time:3453MS
////Run memory:8544KB
//////////////////System Comment End//////////////////
/*
 * 1862.cpp
 *
 *  Created on: 2010-6-29
 *      Author: ambition
 */

#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

struct unit
{
	string id;
	string name;
	int score;
};

int compare1( const void* a, const void* b )
{
    return ((*(unit*)a).id>(*(unit*)b).id)?1:-1;
}
int compare2( const void* a, const void* b )
{
    if( (*(unit*)a).name>(*(unit*)b).name ) return 1;
    else if( (*(unit*)a).name<(*(unit*)b).name ) return -1;
    else return ((*(unit*)a).id>(*(unit*)b).id)?1:-1;
}
int compare3( const void* a, const void* b )
{
    if( (*(unit*)a).score>(*(unit*)b).score ) return 1;
    else if( (*(unit*)a).score<(*(unit*)b).score ) return -1;
    else return ((*(unit*)a).id>(*(unit*)b).id)?1:-1;
}

int main()
{
	int n,m,t=0;
	unit stu[100001];
	while(cin>>n>>m,n||m)
	{
		for(int i=0;i<n;i++)
			cin>>stu[i].id>>stu[i].name>>stu[i].score;
		cout<<"Case "<<++t<<':'<<endl;
		if(m==1)
		{
			qsort(stu,n,sizeof(unit),compare1);
			for(int i=0;i<n;i++)
				cout<<stu[i].id<<' '<<stu[i].name<<' '<<stu[i].score<<endl;
		}
		else if(m==2)
		{
			qsort(stu,n,sizeof(unit),compare2);
			for(int i=0;i<n;i++)
				cout<<stu[i].id<<' '<<stu[i].name<<' '<<stu[i].score<<endl;
		}
		else if(m==3)
		{
			qsort(stu,n,sizeof(unit),compare3);
			for(int i=0;i<n;i++)
				cout<<stu[i].id<<' '<<stu[i].name<<' '<<stu[i].score<<endl;
		}
	}
	return 0;
}
