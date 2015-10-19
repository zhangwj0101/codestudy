////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2011-04-13 11:18:01
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2629
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;

char str[15];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",str);
		printf("He/She is from ");
		if(str[0]=='3'&&str[1]=='3'){
			printf("Zhejiang");
		}else if(str[0]=='1'&&str[1]=='1'){
			printf("Beijing");
		}else if(str[0]=='7'&&str[1]=='1'){
			printf("Taiwan");
		}else if(str[0]=='8'&&str[1]=='1'){
			printf("Hong Kong");
		}else if(str[0]=='8'&&str[1]=='2'){
			printf("Macao");
		}else if(str[0]=='5'&&str[1]=='4'){
			printf("Tibet");
		}else if(str[0]=='2'&&str[1]=='1'){
			printf("Liaoning");
		}else if(str[0]=='3'&&str[1]=='1'){
			printf("Shanghai");
		}
		printf(",and his/her birthday is on %.2s,%.2s,%.4s based on the table.\n",str+10,str+12,str+6);
	}
}