////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-08 16:04:40
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2054
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:400KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
main()
{
    char *pa,*pb,*p;
    char a[100000], b[100000];
    while (scanf("%s%s",&a,&b) != EOF)
    {
        pa=a;pb=b;
        while(*pa=='0') pa++;
		p=pa+strlen(pa)-1;
		if(strchr(pa,'.'))
		{
			while(*p=='0')
				*p--=0;
			if(*p=='.') *p='\0';
		}
        while(*pb=='0') pb++;
		p=pb+strlen(pb)-1;
		if(strchr(pb,'.'))
		{
			while(*p=='0')
				*p--=0;
			if(*p=='.') *p='\0';
		}
        puts(strcmp(pa, pb)?"NO":"YES");
    }
}