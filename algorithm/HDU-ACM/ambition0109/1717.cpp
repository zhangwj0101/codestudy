////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-11 21:58:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1717
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

int GCD(int a,int b){
	while(b){
		int t=b;
		b=a%b;
		a=t;
	}
	return a;
}

char str[15];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",str);
		int x=0,y=0;
		int i;
		for(i=2;str[i]&&str[i]!='(';i++){
			x*=10;
			x+=str[i]-'0';
		}
		if(str[i]=='('){
			int lx=i-2,ly;
			for(ly=0,i+=1;str[i]!=')';i++,ly++){
				y*=10;
				y+=str[i]-'0';
			}
			int yy=1,xx=1;
			for(;ly;ly--) yy*=10; yy=yy-1;
			for(;lx;lx--) xx*=10;
			y+=yy*x;
			yy=yy*xx;
			int gcd=GCD(y,yy);
			printf("%d/%d\n",y/gcd,yy/gcd);
		}else{
			int s=1;
			for(i-=2;i;i--){
				s*=10;
			}
			int gcd=GCD(s,x);
			printf("%d/%d\n",x/gcd,s/gcd);
		}
	}
}