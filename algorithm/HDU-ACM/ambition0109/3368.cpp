////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-04 10:22:31
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 3368
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int main(void)
{
    int n,nn,i,j,k,l,m,max,num[8][8];
    char s[8][9];
    for(scanf("%d",&n),nn=0;nn<n;nn++)
    {
		for(i=0;i<8;i++)
			for(j=0;j<8;j++)
				num[i][j]=0;
        for(i=0;i<8;i++)
            scanf("%s",s[i]);
        for(i=0,max=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(s[i][j]=='D')
                {
                    if((j+1<8)&&s[i][j+1]=='L')
                        for(k=j+1,m=0;k<8;k++)
                        {
                            if(s[i][k]=='L')
                                m++;
                            else if(s[i][k]=='D')
                                break;
                            else if(s[i][k]=='*')
                            {
								num[i][k]+=m;
                                if(num[i][k]>max)
                                    max=num[i][k];
                                break;
                            }
                        }
                    if((i+1<8)&&s[i+1][j]=='L')
                        for(k=i+1,m=0;k<8;k++)
                        {
                            if(s[k][j]=='L')
                                m++;
                            else if(s[k][j]=='D')
                                break;
                            else if(s[k][j]=='*')
                            {
								num[k][j]+=m;
                                if(num[k][j]>max)
                                    max=num[k][j];
                                break;
                            }
                        }
                    if((j-1>=0)&&s[i][j-1]=='L')
                        for(k=j-1,m=0;k>=0;k--)
                        {
                            if(s[i][k]=='L')
                                m++;
                            else if(s[i][k]=='D')
                                break;
                            else if(s[i][k]=='*')
                            {
								num[i][k]+=m;
                                if(num[i][k]>max)
                                    max=num[i][k];
                                break;
                            }
                        }
                    if((i-1>=0)&&s[i-1][j]=='L')
                        for(k=i-1,m=0;k>=0;k--)
                        {
                            if(s[k][j]=='L')
                                m++;
                            else if(s[k][j]=='D')
                                break;
                            else if(s[k][j]=='*')
                            {
								num[k][j]+=m;
                                if(num[k][j]>max)
                                    max=num[k][j];
                                break;
                            }
                        }
                    if((i-1>=0)&&(j-1>=0)&&s[i-1][j-1]=='L')
                        for(k=i-1,l=j-1,m=0;k>=0&&l>=0;k--,l--)
                        {
                            if(s[k][l]=='L')
                                m++;
                            else if(s[k][l]=='D')
                                break;
                            else if(s[k][l]=='*')
                            {
								num[k][l]+=m;
                                if(num[k][l]>max)
                                    max=num[k][l];
                                break;
                            }
                        }
                    if((i-1>=0)&&(j+1<8)&&s[i-1][j+1]=='L')
                        for(k=i-1,l=j+1,m=0;k>=0&&l<8;k--,l++)
                        {
                            if(s[k][l]=='L')
                                m++;
                            else if(s[k][l]=='D')
                                break;
                            else if(s[k][l]=='*')
                            {
								num[k][l]+=m;
                                if(num[k][l]>max)
                                    max=num[k][l];
                                break;
                            }
                        }
                    if((i+1<8)&&(j-1>=0)&&s[i+1][j-1]=='L')
                        for(k=i+1,l=j-1,m=0;k<8&&l>=0;k++,l--)
                        {
                            if(s[k][l]=='L')
                                m++;
                            else if(s[k][l]=='D')
                                break;
                            else if(s[k][l]=='*')
                            {
								num[k][l]+=m;
                                if(num[k][l]>max)
                                    max=num[k][l];
                                break;
                            }
                        }
                    if((i+1<8)&&(j+1<8)&&s[i+1][j+1]=='L')
                        for(k=i+1,l=j+1,m=0;k<8&&l<8;k++,l++)
                        {
                            if(s[k][l]=='L')
                                m++;
                            else if(s[k][l]=='D')
                                break;
                            else if(s[k][l]=='*')
                            {
								num[k][l]+=m;
                                if(num[k][l]>max)
                                    max=num[k][l];
                                break;
                            }
                        }
                }
            }
        }
        printf("Case %d: %d\n",nn+1,max);
    }
    return 0;
}