////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-24 23:56:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1177
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
struct In { 
   int id;int x; int y; 
};
int cmp( const void *a , const void *b ) 
{ 
    struct In *c = (In *)a; 
    struct In *d = (In *)b; 
    if(c->x != d->x) return d->x -c->x; 
    else return c->y - d->y; 
}
int main()
{
	In 	sub[131];
	int n,g,s,c,m,i,h,min,sec;
    while(cin>>n&&n)
    {
		cin>>g>>s>>c>>m;
		for(i=0;i<n;i++)
		{
			sub[i].id=i+1;
			cin>>sub[i].x;
			scanf("%d:%d:%d",&h,&min,&sec);
			sub[i].y=h*3600+min*60+sec;
		}
		qsort(sub,n,sizeof(In),cmp);
		for(i=0;i<n;i++)
			if(sub[i].id==m)
				break;
		cout<<"Accepted today? I've got ";
		if(i<g)
			cout<<"a golden medal :)\n";
		else if(i<s+g)
			cout<<"a silver medal :)\n";
		else if(i<s+g+c)
			cout<<"a copper medal :)\n";
		else
			cout<<"an honor mentioned :)\n";
    }
  return 0;
}