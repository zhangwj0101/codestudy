////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-19 20:09:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3650
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<algorithm>
using namespace std;

struct Line{
	int left,right;
}Line[105];
//int Dis[205];
//
//int Find(int val,int Max){
//	int top=0,bot=Max;
//	int mid=(top+bot)>>1;
//	while(true){
//		if(Dis[mid]==val){
//			return mid;
//		}else if(Dis[mid]>val){
//			bot=mid-1;
//		}else if(Dis[mid]<val){
//			top=mid+1;
//		}
//		mid=(top+bot)>>1;
//	}
//}
//
//int Hash[205];
//int main()
//{
//	int n;
//	while(scanf("%d",&n),n){
//		for(int i=0;i<n;i++){
//			scanf("%d%d",&Line[i].left,&Line[i].right);
//			if(Line[i].left>Line[i].right){
//				Line[i].left^=Line[i].right^=Line[i].left^=Line[i].right;
//			}
//			Dis[i<<1]=Line[i].left;
//			Dis[i<<1|1]=Line[i].right;
//		}
//		sort(Dis,Dis+2*n);
//		int m=0;
//		for(int i=1;i<2*n;i++){
//			if(Dis[m]!=Dis[i]){
//				Dis[++m]=Dis[i];
//			}
//		}
//		int max=0;
//		memset(Hash,0,sizeof(Hash));
//		for(int i=0;i<n;i++){
//			int pl=Find(Line[i].left,m);
//			int pr=Find(Line[i].right,m);
//			for(int j=pl;j<=pr;j++){
//				Hash[j]++;
//				if(Hash[j]>max){
//					max=Hash[j];
//				}
//			}
//		}
//		printf("%d\n",max);
//	}
//}

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