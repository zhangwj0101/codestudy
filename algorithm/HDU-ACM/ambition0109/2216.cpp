////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-31 17:05:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2216
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:452KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<queue>
using namespace std;

struct step{
	int sx,sy;
	int zx,zy;
	int t;
	void set(int nsx,int nsy,int nzx,int nzy,int nt){
		sx=nsx;sy=nsy;zx=nzx;zy=nzy;t=nt;
	}
};
char map[21][21];
bool Hash[21][21][21][21];
int Dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int ax,ay,ssx,ssy,zzx,zzy;
int Bfs(){
	queue<step> steps;
	memset(Hash,false,sizeof(Hash));
	step temp;
	temp.set(ssx,ssy,zzx,zzy,0);
	steps.push(temp);
	Hash[ssy][ssx][zzy][zzx]=true;
	while(!steps.empty()){
		int tsx,tsy,tzx,tzy,tt;
		tsx=steps.front().sx;
		tsy=steps.front().sy;
		tzx=steps.front().zx;
		tzy=steps.front().zy;
		tt=steps.front().t+1;
		steps.pop();
		for(int i=0;i<4;i++){
			int ttzx=tzx+Dir[i][0];
			int ttzy=tzy+Dir[i][1];
			if(ttzx>=0&&ttzx<ax&&ttzy>=0&&ttzy<ay){
				if(map[ttzy][ttzx]=='X') continue;
				int ttsx=tsx-Dir[i][0];
				int ttsy=tsy-Dir[i][1];
				if(ttsx>=0&&ttsx<ax&&ttsy>=0&&ttsy<ay){
					if(map[ttsy][ttsx]=='X')
					{ttsx=tsx;ttsy=tsy;}
				}else{ttsx=tsx;ttsy=tsy;}
				if(ttsx==ttzx&&ttsy==ttzy) return tt;
				for(int j=0;j<4;j++){
					if(ttsx+Dir[j][0]==ttzx&&ttsy+Dir[j][1]==ttzy)
						return tt;
				}
				if(Hash[ttsy][ttsx][ttzy][ttzx]) continue;
				temp.set(ttsx,ttsy,ttzx,ttzy,tt);
				steps.push(temp);
				Hash[ttsy][ttsx][ttzy][ttzx]=true;
			}
		}
	}
	return -1;
}
int main()
{
	while(scanf("%d%d",&ay,&ax)!=EOF){
		ssx=ssy=zzx=zzy=-1;
		for(int i=0;i<ay;i++){
			scanf("%s",map[i]);
			if(ssx==-1||zzx==-1)
			for(int j=0;j<ax;j++){
				if(map[i][j]=='S'){
					ssx=j;ssy=i;
				}
				if(map[i][j]=='Z'){
					zzx=j;zzy=i;
				}
			}
		}
		int ans=Bfs();
		if(ans==-1) printf("Bad Luck!\n");
		else printf("%d\n",ans);
	}
}