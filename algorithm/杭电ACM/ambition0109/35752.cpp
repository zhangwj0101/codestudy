////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-26 19:11:53
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3575
////Problem Title: 
////Run result: Accept
////Run time:203MS
////Run memory:152KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

char str[1500];
int main()
{
	int n,c=0;
	scanf("%d",&n);
	while(n--){
		int s,t;
		scanf("%d%d",&s,&t);
		getchar();
		printf("Case %d:\n",++c);
		gets(str);
		for(int i=0;str[i];i+=(s+2)){
			if(i!=0){
				printf(" ");
				i+=1;
			}
			printf(" ");
			for(int j=0;j<t;j++)
				printf("%c",str[i+1]);
			printf(" ");
		}
		puts("");
		for(int i=0;i<s;i++)
			gets(str);
		for(int k=0;k<t;k++){
			for(int i=0;str[i];i+=(s+2)){
				if(i!=0){
					printf(" ");
					i+=1;
				}
				printf("%c",str[i]);
				for(int j=0;j<t;j++){
					printf(" ");
				}
				printf("%c",str[i+s+1]);
			}
			puts("");
		}
		gets(str);
		for(int i=0;str[i];i+=(s+2)){
			if(i!=0){
				printf(" ");
				i+=1;
			}
			printf(" ");
			for(int j=0;j<t;j++)
				printf("%c",str[i+1]);
			printf(" ");
		}
		puts("");
		for(int i=0;i<s;i++)
			gets(str);
		for(int k=0;k<t;k++){
			for(int i=0;str[i];i+=(s+2)){
				if(i!=0){
					printf(" ");
					i+=1;
				}
				printf("%c",str[i]);
				for(int j=0;j<t;j++){
					printf(" ");
				}
				printf("%c",str[i+s+1]);
			}
			puts("");
		}
		gets(str);
		for(int i=0;str[i];i+=(s+2)){
			if(i!=0){
				printf(" ");
				i+=1;
			}
			printf(" ");
			for(int j=0;j<t;j++)
				printf("%c",str[i+1]);
			printf(" ");
		}
		puts("\n");
	}
}
