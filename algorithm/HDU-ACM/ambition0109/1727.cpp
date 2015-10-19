////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-27 21:37:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1727
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:200KB
//////////////////System Comment End//////////////////
/*
 * 1727.cpp
 *
 *  Created on: 2010-11-27
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
using namespace std;
char num[][10] = { "zero", "one", "two", "three", "four", "five", "six", "seven",
		"eight", "nine" };
char numteen[][10] = { "ten", "eleven", "twelve", "thirteen", "fourteen",
		"fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
char numty[][10] = { "","", "twenty", "thirty", "forty", "fifty", "sixty",
		"seventy", "eighty", "ninety" };
int main() {
	int n;
	while(~scanf("%d",&n)){
		int t,h,s,g;
		t=n/1000;
		h=n/100%10;
		s=n/10%10;
		g=n%10;
		if(t){
			printf("%s thousand",num[t]);
			if(h||s||g) printf(" and ");
		}
		if(h){
			printf("%s hundred",num[h]);
			if(s||g) printf(" and ");
		}
		if(s==0){
			if(((t||h)&&g!=0)||!(t||h)) printf("%s",num[g]);
		}else if(s==1){
			printf("%s",numteen[g]);
		}else{
			printf("%s",numty[s]);
			if(g) printf("-%s",num[g]);
		}
		puts("");
	}
}
