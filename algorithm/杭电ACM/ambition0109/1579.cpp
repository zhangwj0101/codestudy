////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-31 19:37:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1579
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int num[21][21][21];
int getw(int a,int b,int c){
	if(a<=0||b<=0||c<=0){
		return 1;
	}else if(a<b&&b<c){
		if(!num[a][b][c]){
			if(!num[a][b][c-1])
				num[a][b][c-1]=getw(a,b,c-1);
			if(!num[a][b-1][c])
				num[a][b-1][c]=getw(a,b-1,c);
			if(!num[a][b-1][c-1])
				num[a][b-1][c-1]=getw(a,b-1,c-1);
			num[a][b][c]=num[a][b][c-1]+num[a][b-1][c]-num[a][b-1][c-1];
		}
	}else{
		if(!num[a][b][c]){
			if(!num[a-1][b][c])
				num[a-1][b][c]=getw(a-1,b,c);
			if(!num[a-1][b-1][c])
				num[a-1][b-1][c]=getw(a-1,b-1,c);
			if(!num[a-1][b][c-1])
				num[a-1][b][c-1]=getw(a-1,b,c-1);
			if(!num[a-1][b-1][c-1])
				num[a-1][b-1][c-1]=getw(a-1,b-1,c-1);
			num[a][b][c]=num[a-1][b][c]+num[a-1][b][c-1]+num[a-1][b-1][c]-num[a-1][b-1][c-1];
		}
	}
	return num[a][b][c];
}

int main()
{
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c),a!=-1||b!=-1||c!=-1){
		printf("w(%d, %d, %d) = ",a,b,c);
		if(a<=0||b<=0||c<=0) a=b=c=0;
		if(a>20||b>20||c>20) a=b=c=20;
		if(!num[a][b][c])
			num[a][b][c]=getw(a,b,c);
		printf("%d\n",num[a][b][c]);
	}
}