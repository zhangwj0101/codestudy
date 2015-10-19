////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-11-01 11:50:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2222
////Problem Title: 
////Run result: Accept
////Run time:406MS
////Run memory:28920KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
const int mn=500010,ml=1000010;
struct node
{
    int match;
    node *lk;
    node *child[26];
};

node *Trie=new node();
node *SuperRoot=new node();

void Insert(node *Trie,char *s)
{
    if(*s==0)Trie->match++;
    else
    {
        if(Trie->child[*s-'a']==0)Trie->child[*s-'a']=new node();
        Insert(Trie->child[*s-'a'],s+1);
    }
}

node* Q[mn];
int begin,end;

void buildtrie()
{
    for(int i=0;i<26;i++)SuperRoot->child[i]=Trie;
    Trie->lk=SuperRoot;
    begin=end=0;
    Q[end++]=Trie;
    while(begin<end)
    {
        node *p=Q[begin++];
        for(int i=0;i<26;i++)
            if(p->child[i]!=0)
            {
                p->child[i]->lk=p->lk->child[i];
                Q[end++]=p->child[i];
            }
            else p->child[i]=p->lk->child[i];
    }
}

char s[ml];
int main()
{
    int n,ans,len,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d\n",&n);
        Trie=new node();
        SuperRoot=new node();
        for(int i=0;i<n;i++)
        {
            gets(s);
            Insert(Trie,s);
        }
        buildtrie();
        ans=0;
        gets(s);
        len=strlen(s);
        node * TT=Trie;
        for(int i=0;i<=len;i++)
        {
            if(TT->match)
            {
                node *t=TT;
                while(t->match)
                {
                    ans+=t->match;
                    t->match=0;
                    t=t->lk;
                }
            }
            TT=TT->child[s[i]-'a'];
        }
        printf("%d\n",ans);
    }
    return 0;
}