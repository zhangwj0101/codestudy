////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-03 14:49:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1462
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:272KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;

char map[30][30];
int len[30];
void main()
{
	string sa,sb,sc,sd;
	int ma,mb,mc,md,i,j,mx,my,t=0;
	while(cin>>sa,sa!="#")
	{
		if(t) cout<<endl;t=1;
		memset(map,' ',sizeof(map));
		cin>>sb>>sc>>sd;
		for(i=0;i<sa.length();i++)
		{
			for(j=0;j<sb.length();j++)
				if(sa[i]==sb[j])break;
			if(sa[i]==sb[j])break;
		}
		ma=i;mb=j;
		if(ma==sa.length()) {cout<<"Unable to make two crosses"<<endl;continue;}
		for(i=0;i<sc.length();i++)
		{
			for(j=0;j<sd.length();j++)
				if(sc[i]==sd[j])break;
			if(sc[i]==sd[j])break;
		}
		mc=i;md=j;
		if(mc==sc.length()) {cout<<"Unable to make two crosses"<<endl;continue;}
		for(i=0;i<sa.length();i++)
			map[mb>md?mb:md][i]=sa[i];
		for(i+=3,j=0;j<sc.length();i++,j++)
			map[mb>md?mb:md][i]=sc[j];
		mx=i;
		for(i=0;i<sb.length();i++)
			map[(mb>md?mb:md)-mb+i][ma]=sb[i];
		my=(mb>md?mb:md)-mb+i;
		for(i=0;i<sd.length();i++)
			map[(mb>md?mb:md)-md+i][sa.length()+3+mc]=sd[i];
		if(my<((mb>md?mb:md)-md+i)) my=((mb>md?mb:md)-md+i);
		for(i=0;i<my;i++)
		{
			for(j=mx-1;j>=0;j--)
			{
				if(map[i][j]!=' ')
					break;
			}
			len[i]=j+1;
		}
		for(i=0;i<my;i++)
		{
			for(j=0;j<len[i];j++)
				cout<<map[i][j];
			cout<<endl;
		}
	}
}