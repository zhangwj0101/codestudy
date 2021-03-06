////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-02 22:26:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1823
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:5156KB
//////////////////System Comment End//////////////////
#include<cstdio>
using namespace std;

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

inline bool scan_lf(double &num)
{
	char in;double Dec=0.1;
	bool IsD=false;
	in=getchar();
	while(in!='.'&&(in<'0'||in>'9'))
		in=getchar();
	if(in=='.') {IsD=true;num=0;}
	else num=in-'0';
	if(!IsD){
		while(in=getchar(),in>='0'&&in<='9'){
			num*=10;num+=in-'0';}
	}
	if(in=='.'){
		while(in=getchar(),in>='0'&&in<='9'){
			num+=Dec*(in-'0');Dec*=0.1;
		}
	}
	return true;
}


struct ATree
{
	int left,right;
	int max;
};

struct HTree
{
	int left,right;
	ATree act[2050];
}STree[260];

void inita(int left,int right,int t,int idx){
	STree[t].act[idx].left=left;
	STree[t].act[idx].right=right;
	STree[t].act[idx].max=-1;
	if(left==right) return;
	int mid=(left+right)>>1;
	inita(left,mid,t,idx<<1);
	inita(mid+1,right,t,idx<<1|1);
}
void inith(int left,int right,int idx)
{
	STree[idx].left=left;
	STree[idx].right=right;
	inita(0,1000,idx,1);
	if(left==right) return;
	int mid=(left+right)>>1;
	inith(left,mid,idx<<1);
	inith(mid+1,right,idx<<1|1);
}

void Modifya(int act,int t,int idx,int val)
{
	if(STree[t].act[idx].left==STree[t].act[idx].right){
		if(val>STree[t].act[idx].max){
			STree[t].act[idx].max=val;
		}
		return;
	}
	int mid=(STree[t].act[idx].left+STree[t].act[idx].right)>>1;
	if(act<=mid){
		Modifya(act,t,idx<<1,val);
	}else{
		Modifya(act,t,idx<<1|1,val);
	}
	if(val>STree[t].act[idx].max){
		STree[t].act[idx].max=val;
	}
}
void Modifyh(int hig,int act,int idx,int val){
	Modifya(act,idx,1,val);
	if(STree[idx].left==STree[idx].right) return;
	int mid=(STree[idx].left+STree[idx].right)>>1;
	if(hig<=mid){
		Modifyh(hig,act,idx<<1,val);
	}else{
		Modifyh(hig,act,idx<<1|1,val);
	}
}

int querya(int left,int right,int t,int idx)
{
	if(STree[t].act[idx].max<0) return -1;
	if(STree[t].act[idx].left==left&&STree[t].act[idx].right==right){
		return STree[t].act[idx].max;
	}
	int mid=(STree[t].act[idx].left+STree[t].act[idx].right)>>1;
	if(right<=mid){
		return querya(left,right,t,idx<<1);
	}else if(left>mid){
		return querya(left,right,t,idx<<1|1);
	}else{
		int ml=querya(left,mid,t,idx<<1);
		int mr=querya(mid+1,right,t,idx<<1|1);
		return (ml>mr?ml:mr);
	}
}

int queryh(int lh,int rh,int la,int ra,int idx){
	if(STree[idx].left==lh&&STree[idx].right==rh){
		return querya(la,ra,idx,1);
	}
	int mid=(STree[idx].left+STree[idx].right)>>1;
	if(rh<=mid){
		return queryh(lh,rh,la,ra,idx<<1);
	}else if(lh>mid){
		return queryh(lh,rh,la,ra,idx<<1|1);
	}else{
		int ml=queryh(lh,mid,la,ra,idx<<1);
		int mr=queryh(mid+1,rh,la,ra,idx<<1|1);
		return (ml>mr?ml:mr);
	}  
}

int main()
{
	int n;
	while(scanf("%d",&n),n){
		inith(100,200,1);
		while(n--){
			char cmd[2];
			scanf("%s",cmd);
			if(cmd[0]=='I'){
				int h;
				double a,l;
				int ia,il;
				scan_ud(h);
				scan_lf(a);
				scan_lf(l);
				ia=int((a*10)+1e-8);
				il=int((l*10)+1e-8);
				Modifyh(h,ia,1,il);
			}else if(cmd[0]=='Q'){
				int lh,rh,la,ra;
				double dla,dra;
				scan_ud(lh);
				scan_ud(rh);
				scan_lf(dla);
				scan_lf(dra);
				la=int((dla*10)+1e-8);
				ra=int((dra*10)+1e-8);
				if(la>ra) la^=ra^=la^=ra;
				if(lh>rh) lh^=rh^=lh^=rh;
				int ans=queryh(lh,rh,la,ra,1);
				if(ans<0) puts("-1");
				else printf("%.1lf\n",ans/10.0);
			}
		}
	}
}