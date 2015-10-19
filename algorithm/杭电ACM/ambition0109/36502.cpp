////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-19 20:10:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3650
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

struct Line{
	int left,right;
}Line[105];

int main()
{
	int n;
	while(scanf("%d",&n),n){
		for(int i=0;i<n;i++){
			scanf("%d%d",&Line[i].left,&Line[i].right);
		}
		int cntl,cntr,max=0;
		for(int i=0;i<n;i++){
			cntl=cntr=0;
			for(int j=0;j<n;j++){
				if(Line[i].left>=Line[j].left&&Line[i].left<=Line[j].right){
					cntl++;
				}
				if(Line[i].right>=Line[j].left&&Line[i].right<=Line[j].right){
					cntr++;
				}
			}
			if(cntl>max) max=cntl;
			if(cntr>max) max=cntr;
		}
		printf("%d\n",max);
	}
}