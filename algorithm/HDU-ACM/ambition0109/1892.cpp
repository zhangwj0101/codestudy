////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-27 12:58:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1892
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:8144KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
#define Lowbit(x) (x&(-x))
int Index[1010][1010],N=1001;
int Num[1010][1010];
void Modify(int x,int y,int T)
{
	for(int i=x;i<=N;i+=Lowbit(i)){
		for(int j=y;j<=N;j+=Lowbit(j)){
			Index[i][j]+=T;
		}
	}
}
int Sum(int x,int y)
{
	int result=0;
	for(int i=x;i>0;i-=Lowbit(i)){
		for(int j=y;j>0;j-=Lowbit(j)){
			result+=Index[i][j];
		}
	}
	return result;
}

int main()
{
	int t,c=0;
	scanf("%d",&t);
	while(t--){
		int n;
		memset(Index,0,sizeof(Index));
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				Num[i][j]=1;
				//Modify(i,j,1);
			}
		}
		scanf("%d",&n);
		printf("Case %d:\n",++c);
		while(n--){
			char cmd[2];
			scanf("%s",cmd);
			if(cmd[0]=='S'){
				int x1,y1,x2,y2,sum;
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				if(x1<x2){x1^=x2^=x1^=x2;}
				if(y1<y2){y1^=y2^=y1^=y2;}
				sum=Sum(x1+1,y1+1)-Sum(x1+1,y2)-Sum(x2,y1+1)+Sum(x2,y2);
				sum+=(x1-x2+1)*(y1-y2+1);
				printf("%d\n",sum);
			}else if(cmd[0]=='A'){
				int x,y,num;
				scanf("%d%d%d",&x,&y,&num);
				Num[x+1][y+1]+=num;
				Modify(x+1,y+1,num);
			}else if(cmd[0]=='D'){
				int x,y,num;
				scanf("%d%d%d",&x,&y,&num);
				num=num>Num[x+1][y+1]?Num[x+1][y+1]:num;
				Num[x+1][y+1]-=num;
				Modify(x+1,y+1,-num);
			}else if(cmd[0]=='M'){
				int x1,y1,x2,y2,num;
				scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&num);
				num=num>Num[x1+1][y1+1]?Num[x1+1][y1+1]:num;
				Num[x1+1][y1+1]-=num;
				Num[x2+1][y2+1]+=num;
				Modify(x2+1,y2+1,num);
				Modify(x1+1,y1+1,-num);
			}
		}
	}
}