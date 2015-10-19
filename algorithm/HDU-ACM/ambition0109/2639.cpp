////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-12 11:49:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2639
////Problem Title: 
////Run result: Accept
////Run time:1781MS
////Run memory:1036KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<set>
using namespace std;

set<int> bag[1001],temp;
int v[101],w[101];
void main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,av,ak;
		scanf("%d%d%d",&n,&av,&ak);
		for(int i=1;i<=n;i++) scanf("%d",&w[i]);
		for(int i=1;i<=n;i++) scanf("%d",&v[i]);
		bag[0].insert(0);
		for(int i=1;i<=av;i++){
			bag[i].clear();
			bag[i].insert(0);
		}
		for(int i=1;i<=n;i++)
			for(int k=av;k>=v[i];k--){
				set<int>::iterator it;
				for(it=bag[k-v[i]].begin();it!=bag[k-v[i]].end();it++)
					bag[k].insert(*it+w[i]);
				if(bag[k].size()>ak){
					it=bag[k].end();
					for(int ii=0;ii<ak;ii++)it--;
					bag[k].erase(bag[k].begin(),it);
				}
			}
			cout<<*bag[av].begin()<<endl;
	}
}