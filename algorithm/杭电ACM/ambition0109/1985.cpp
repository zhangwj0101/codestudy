////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-08 14:15:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1985
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
	int t,cas=0;
	scanf("%d",&t);
	while(t--){
		double num; char unit[5];
		scanf("%lf %s",&num,unit);
		printf("%d ",++cas);
		if(strcmp(unit,"kg")==0){
			printf("%.4lf lb",num*2.2046);
		}else if(strcmp(unit,"l")==0){
			printf("%.4lf g",num*0.2642);
		}else if(strcmp(unit,"lb")==0){
			printf("%.4lf kg",num*0.4536);
		}else if(strcmp(unit,"g")==0){
			printf("%.4lf l",num*3.7854);
		}
		puts("");
	}
}