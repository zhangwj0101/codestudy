////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-06 16:13:40
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1591
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int used[26]={0},i,t;
	char code[26],keyword[26],text[1000];
	scanf("%s",keyword);getchar();
	for(i=0;keyword[i]!='\0';i++)
	{
		used[keyword[i]-'A']=1;
		code[keyword[i]-'A']=i+'a';
	}
	for(i=0,t=25;i<=26;i++)
		if(!used[i])
		{
			code[i]=t+'a';
			t--;
		}
	while(gets(text))
	{
		for(i=0;text[i]!='\0';i++)
		{
			if(text[i]<='z'&&text[i]>='a')
				text[i]=code[text[i]-'a'];
			if(text[i]<='Z'&&text[i]>='A')
				text[i]=code[text[i]-'A']-32;
		}
		puts(text);
	}
}