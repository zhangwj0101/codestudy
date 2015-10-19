////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-08 16:54:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1025
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:572KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<vector>
using namespace std;

vector<int> num,temp;
void main()
{
	int n,tt=0;
	while(scanf("%d",&n)!=EOF)
	{
		num.resize(n);
		temp.clear();
		for(int i=0;i<n;i++){
			int rich,poor;
			scanf("%d%d",&rich,&poor);
			num[rich-1]=poor;
		}
		temp.push_back(num[0]);
		for(int i=1;i<n;i++)
		{
			if(num[i]>temp[temp.size()-1]){
				temp.push_back(num[i]);continue;
			}
			int bottom=0,top=temp.size()-1,middle,ans;
			while(top>=bottom){
				middle=(top+bottom)/2;
				if(temp[middle]>=num[i]){
					top=(ans=middle)-1;
				}else{
					bottom=middle+1;
				}
			}
			temp[ans]=num[i];
			/*
			int tt=temp.size()-1;
			while(tt>=0&&temp[tt]>num[i])tt--;
			temp[tt+1]=num[i];
			*/
		}
		if(temp.size()==1)
			printf("Case %d:\nMy king, at most 1 road can be built.\n\n",++tt);
		else
			printf("Case %d:\nMy king, at most %d roads can be built.\n\n",++tt,temp.size());
	}
}