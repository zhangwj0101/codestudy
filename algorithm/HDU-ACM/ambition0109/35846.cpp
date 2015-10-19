////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-01 11:56:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3584
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:1288KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstring>
using namespace std;
#define Lowbit(x) (x&(-x))

inline bool scan_ud(int &num)
{
	char in;
	in=getchar();
	if(in==EOF) return false;
	while(in<'0'||in>'9') in=getchar();
	num=in-'0';
	while(in=getchar(),in>='0'&&in<='9'){
		num*=10,num+=in-'0';
	}
	return true;
}

bool Index[105][105][105],n;
void Modify(int x,int y,int z)
{
	for(int i=x;i<=n;i+=Lowbit(i)){
		for(int j=y;j<=n;j+=Lowbit(j)){
			for(int k=z;k<=n;k+=Lowbit(k)){
				Index[i][j][k]^=1;
			}
		}
	}
}
int Sum(int x,int y,int z)
{
	int result=0;
	for(int i=x;i>0;i-=Lowbit(i)){
		for(int j=y;j>0;j-=Lowbit(j)){
			for(int k=z;k>0;k-=Lowbit(k)){
				result^=Index[i][j][k];
			}
		}
	}
	return result;
}

int main()
{
	int q;
	while(scanf("%d%d",&n,&q)!=EOF){
		memset(Index,0,sizeof(Index));
		while(q--){
			int cmd;
			scan_ud(cmd);
			if(cmd){
				int x1,x2,y1,y2,z1,z2;
				scan_ud(x1);
				scan_ud(y1);
				scan_ud(z1);
				scan_ud(x2);
				scan_ud(y2);
				scan_ud(z2);
				Modify(x2+1,y2+1,z2+1);
				Modify(x2+1,y2+1,z1);
				Modify(x2+1,y1,z2+1);
				Modify(x1,y2+1,z2+1);
				Modify(x2+1,y1,z1);
				Modify(x1,y2+1,z1);
				Modify(x1,y1,z2+1);
				Modify(x1,y1,z1);
			}else{
				int x,y,z;
				scan_ud(x);
				scan_ud(y);
				scan_ud(z);
				printf("%d\n",Sum(x,y,z));
			}
		}
	}
}